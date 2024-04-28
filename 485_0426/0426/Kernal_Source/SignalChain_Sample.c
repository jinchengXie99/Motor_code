/*******************************************************************************
 * ��Ȩ���� (C)2016, LINKO Semiconduct
 *
 * �ļ����ƣ� FOC.Drive.c
 * �ļ���ʶ��
 * ����ժҪ�� ���ʸ�����Ƶ����ڻ����ؼ������㷨
 * ����˵���� ��
 * ��ǰ�汾�� V 2.0
 * ��    �ߣ� WhenCai Zhao Howlet Li
 * ������ڣ� 2020��9��10��
 *
 * �޸ļ�¼1��
 *    �޸����ڣ�2020��9��10��
 *    �� �� �ţ�V2.0
 *    �� �� �ˣ�Howlet Li
 *    �޸����ݣ���ʽ����
 *
 *******************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "FOC_Drive.h"
#include "global_variable.h"
#include "hardware_config.h"
#include "mc_math.h"
#include "MC_Parameter.h"
#include "USER_APP.h"

#if (CURRENT_SAMPLE_TYPE == CURRENT_SAMPLE_1SHUNT)
/*******************************************************************************
 �������ƣ�    stru_CurrPhaseUVW SVPWM_1ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
 ����������    ����������㷨����SVPWM�����������õ�U, V�����
 ���������    stru_FOC_CurrLoopDef *this  �ṹ��ָ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
stru_CurrPhaseUVW SVPWM_1ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
{

    stru_Array_Def mADC_Result;
    stru_CurrPhaseUVW Local_Stator_Currents;
    s32 wAux;
    s16 hCurrA, hCurrB, hCurrC;

    u8 bCurrASamp = 0, bCurrBSamp = 0;

    GET_ADC_DATA(mADC_Result);
    switch (this->bSampCur1)
    {
        case SAMP_IA:

            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrA = sat(wAux, S16_MIN, S16_MAX);

            bCurrASamp = 1;
            break;
        case SAMP_IB:
            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrB = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;
        case SAMP_IC:
            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

            break;

        case SAMP_NIA:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrA = sat(wAux, S16_MIN, S16_MAX);

            bCurrASamp = 1;
            break;

        case SAMP_NIB:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrB = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;

        case SAMP_NIC:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

        case SAMP_OLDA:
            hCurrA = this->mStatCurrUVW.nPhaseU;
            bCurrASamp = 1;
            break;

        case SAMP_OLDB:
            hCurrB = this->mStatCurrUVW.nPhaseV;
            bCurrBSamp = 1;
            break;

        case SAMP_OLDC:
            hCurrC = this->mStatCurrUVW.nPhaseW;

            break;


        default:

            break;
    }

    GET_ADC1_DATA(mADC_Result);
    // Second sampling point
    switch (this->bSampCur2)
    {
        case SAMP_IA:
            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrA = sat(wAux, S16_MIN, S16_MAX);
            bCurrASamp = 1;
            break;
        case SAMP_IB:
            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrB = sat(wAux, S16_MIN, S16_MAX);
            bCurrBSamp = 1;
            break;
        case SAMP_IC:
            wAux = mADC_Result.nData0 - (s32)(this->nBusShuntOffset);
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

            break;
        case SAMP_NIA:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrA = sat(wAux, S16_MIN, S16_MAX);

            bCurrASamp = 1;
            break;

        case SAMP_NIB:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrB = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;

        case SAMP_NIC:
            wAux = (s32)(this->nBusShuntOffset) - mADC_Result.nData0;
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

            break;
        case SAMP_OLDA:
            hCurrA = this->mStatCurrUVW.nPhaseU;
            bCurrASamp = 1;
            break;

        case SAMP_OLDB:
            hCurrB = this->mStatCurrUVW.nPhaseU;
            bCurrBSamp = 1;
            break;

        case SAMP_OLDC:
            hCurrC = this->mStatCurrUVW.nPhaseU;
            break;

        default:

            break;
    }

    if (bCurrASamp == 0)
    {
        /* ���ʹ��� */
        wAux = -hCurrB - hCurrC;
        hCurrA = sat(wAux, S16_MIN, S16_MAX);
    }
    if (bCurrBSamp == 0)
    {
        wAux = -hCurrA - hCurrC;
        hCurrB = sat(wAux, S16_MIN, S16_MAX);
    }


    Local_Stator_Currents.nPhaseU = hCurrA;
    Local_Stator_Currents.nPhaseV = hCurrB;

    return (Local_Stator_Currents);
}

/*******************************************************************************
 �������ƣ�    void ADC_NormalModeCFG(void)
 ����������    ADC��������ģʽͨ������
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void ADC_NormalModeCFG(void)
{

    ADC_CHN0 = ADC_1SHUNT_CURR_CH | (ADC_1SHUNT_CURR_CH << 4) | (ADC_1SHUNT_CURR_CH << 8) | (ADC_1SHUNT_CURR_CH << 12);
    ADC_CHN1 = ADC_BUS_VOL_CHANNEL | (ADC_TEMP_CHANNEL << 4);

}

void ADC_NormalModeCFG1(void)
{
 
    //ADC_CHN0 = ADC_1SHUNT_CURR_CH | (ADC_1SHUNT_CURR_CH << 4) | (ADC_BUS_VOL_CHANNEL << 8) | (ADC_1SHUNT_CURR_CH << 12);
    ADC_CHN0 = BEMF_CH_A | (ADC_BUS_VOL_CHANNEL << 4) | (BEMF_CH_B << 8) | (BEMF_CH_C << 12);
    ADC_CHN1 = ADC_BUS_VOL_CHANNEL | (ADC_BUS_CURR_CHANNEL << 4);
  
}

/*******************************************************************************
 �������ƣ�    void MCPWM0_RegUpdate(void)
 ����������    ����MCPWMģ��ռ�ձ�ֵ������MCPWMģ��ADC������Ĵ���ֵ
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void MCPWM0_RegUpdate(void)
{
    MCPWM_TH00 = struFOC_CurrLoop.mVoltUVW_NegPWM.nPhaseU;
    MCPWM_TH01 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;

    MCPWM_TH10 = struFOC_CurrLoop.mVoltUVW_NegPWM.nPhaseV;
    MCPWM_TH11 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;

    MCPWM_TH20 = struFOC_CurrLoop.mVoltUVW_NegPWM.nPhaseW;
    MCPWM_TH21 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;

}

#endif

#if (CURRENT_SAMPLE_TYPE == CURRENT_SAMPLE_2SHUNT)
/*******************************************************************************
 �������ƣ�    stru_CurrPhaseUVW SVPWM_2ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
 ����������    ����SVPWM�����������õ�U, V�����
 ���������    stru_FOC_CurrLoopDef *this  �ṹ��ָ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
stru_CurrPhaseUVW SVPWM_2ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
{
    stru_Array_Def mADC_Result;
    stru_CurrPhaseUVW Local_Stator_Currents;
    s16 hCurrA = 0, hCurrB = 0;
    GET_ADC0_DATA(mADC_Result);
    hCurrA = (s32)(this->nPhaseAOffset) - mADC_Result.nData0;
    /* First sampling point */
    //    switch (this->bSampCur1)
    //    {
    //    case SAMP_IA:

    //        wAux = (s32)(this->nPhaseAOffset) - mADC_Result.nData0;
    //        //hCurrA = sat(wAux, S16_MIN, S16_MAX);

    //        //bCurrASamp = 1;
    //        break;

    //    case SAMP_IB:

    //        wAux = (s32)(this->nPhaseBOffset) - mADC_Result.nData0;
    //        hCurrB = sat(wAux, S16_MIN, S16_MAX);

    //        bCurrBSamp = 1;
    //        break;

    //    case SAMP_IC:

    //        wAux = (s32)(this->nPhaseCOffset) - mADC_Result.nData0;
    //        hCurrC = sat(wAux, S16_MIN, S16_MAX);

    //        bCurrBSamp = 1;
    //        break;
    //    case SAMP_NIA:
    //        hCurrA = this->mStatCurrUVW.nPhaseU;
    //        bCurrASamp = 1;

    //        break;
    //    case SAMP_NIB:
    //        hCurrB = this->mStatCurrUVW.nPhaseV;
    //        bCurrBSamp = 1;

    //        break;
    //    case SAMP_NIC:
    //        hCurrC = 0 - this->mStatCurrUVW.nPhaseU - this->mStatCurrUVW.nPhaseV;

    //        break;
    //    default:
    //        wAux = 0;
    //        break;
    //    }

    GET_ADC1_DATA(mADC_Result);
    hCurrB = (s32)(this->nPhaseBOffset) - mADC_Result.nData0;
    /* Second sampling point */
    //    switch (this->bSampCur2)
    //    {
    //    case SAMP_IA:
    //        wAux = (s32)(this->nPhaseAOffset) - mADC_Result.nData0;
    //        hCurrA = sat(wAux, S16_MIN, S16_MAX);

    //        bCurrASamp = 1;
    //        break;

    //    case SAMP_IB:

    //        wAux = (s32)(this->nPhaseBOffset) - mADC_Result.nData0;
    //        //hCurrB = sat(wAux, S16_MIN, S16_MAX);

    //       // bCurrBSamp = 1;
    //        break;

    //    case SAMP_IC:

    //        wAux = (s32)(this->nPhaseCOffset) - mADC_Result.nData0;
    //        hCurrC = sat(wAux, S16_MIN, S16_MAX);

    //        break;
    //    case SAMP_NIA:
    //        hCurrA = this->mStatCurrUVW.nPhaseU;
    //        bCurrASamp = 1;

    //        break;
    //    case SAMP_NIB:
    //        hCurrB = this->mStatCurrUVW.nPhaseV;
    //        bCurrBSamp = 1;

    //        break;
    //    case SAMP_NIC:
    //        hCurrC = 0 - this->mStatCurrUVW.nPhaseU - this->mStatCurrUVW.nPhaseV;

    //        break;
    //    default:
    //        wAux = 0;
    //        break;
    //    }
    //    if (bCurrASamp == 0)
    //    {   /* ���ʹ��� hd */
    //        wAux = -hCurrB - hCurrC;
    //        hCurrA = sat(wAux, S16_MIN, S16_MAX);
    //    }
    //    if (bCurrBSamp == 0)
    //    {
    //        wAux = -hCurrA - hCurrC;
    //        hCurrB = sat(wAux, S16_MIN, S16_MAX);
    //    }

    #if (CHIP_PART_NUMBER == LKS32MC057D_V0)
    Local_Stator_Currents.nPhaseU = -hCurrA;
    #else
    Local_Stator_Currents.nPhaseU = hCurrA;
    #endif
    Local_Stator_Currents.nPhaseV = hCurrB;

    return (Local_Stator_Currents);
}

/*******************************************************************************
 �������ƣ�    void ADC_NormalModeCFG(void)
 ����������    ADC��������ģʽͨ������
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void ADC_NormalModeCFG(void)
{
	if(UserSys.ucMotorDir == CW)
	{
		ADC_CHN0 = ADC_CURRETN_A_CHANNEL | (ADC_HEAT_TEMP_CHANNEL << 4) | (ADC_BUS_VOL_CHANNEL << 8) | (ADC_CURRETN_B_CHANNEL << 12);
		ADC_CHN1 = ADC_IPM_TEMP_CHANNEL | (M0_ADC_BUS_CURR_CH << 4); 
	}		
	else
	{	
		ADC_CHN0 = ADC_CURRETN_B_CHANNEL | (ADC_HEAT_TEMP_CHANNEL << 4) | (ADC_BUS_VOL_CHANNEL << 8) | (ADC_CURRETN_A_CHANNEL << 12);
		ADC_CHN1 = ADC_IPM_TEMP_CHANNEL | (M0_ADC_BUS_CURR_CH << 4);
	}	
}

void ADC_NormalModeCFG1(void)
{
    ADC_CHN0 = BEMF_CH_A | (BEMF_CH_B << 4) | (ADC_BUS_VOL_CHANNEL << 8) | (BEMF_CH_C << 12);    //BEMF_CH_B
    ADC_CHN1 = ADC_BUS_VOL_CHANNEL | (ADC_BUS_VOL_CHANNEL << 4);
  
}

/*******************************************************************************
 �������ƣ�    void MCPWM0_RegUpdate(void)
 ����������    ����MCPWMģ��ռ�ձ�ֵ������MCPWMģ��ADC������Ĵ���ֵ
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void MCPWM0_RegUpdate(void)
{
	if(UserSys.ucMotorDir == CW)
	{
		MCPWM_TH00 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;
		MCPWM_TH01 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;

		MCPWM_TH10 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;
		MCPWM_TH11 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;

		MCPWM_TH20 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;
		MCPWM_TH21 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;
	}
	else
	{
		MCPWM_TH00 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;
		MCPWM_TH01 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;

		MCPWM_TH10 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;
		MCPWM_TH11 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;

		MCPWM_TH20 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;
		MCPWM_TH21 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;
	}

}


#endif


#if ((CURRENT_SAMPLE_TYPE == CURRENT_SAMPLE_3SHUNT)||(CURRENT_SAMPLE_TYPE == CURRENT_SAMPLE_MOSFET))
/*******************************************************************************
 �������ƣ�    stru_CurrPhaseUVW SVPWM_3ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
 ����������    ����SVPWM�����������õ�U, V�����
 ���������    stru_FOC_CurrLoopDef *this  �ṹ��ָ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
stru_CurrPhaseUVW SVPWM_3ShuntGetPhaseCurrent(stru_FOC_CurrLoopDef *this)
{
    stru_Array_Def mADC_Result;
    stru_CurrPhaseUVW Local_Stator_Currents;
    s32 wAux;
    s16 hCurrA = 0, hCurrB = 0, hCurrC = 0;

    u8 bCurrASamp = 0, bCurrBSamp = 0;
    GET_ADC_DATA(mADC_Result);
    /* First sampling point */
    switch (this->bSampCur1)
    {
        case SAMP_IA:

            wAux = (s32)(this->nPhaseAOffset) - mADC_Result.nData0;
            hCurrA = sat(wAux, S16_MIN, S16_MAX);

            bCurrASamp = 1;
            break;

        case SAMP_IB:

            wAux = (s32)(this->nPhaseBOffset) - mADC_Result.nData0;
            hCurrB = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;

        case SAMP_IC:

            wAux = (s32)(this->nPhaseCOffset) - mADC_Result.nData0;
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;
        case SAMP_NIA:
            hCurrA = this->mStatCurrUVW.nPhaseU;
            bCurrASamp = 1;

            break;
        case SAMP_NIB:
            hCurrB = this->mStatCurrUVW.nPhaseV;
            bCurrBSamp = 1;

            break;
        case SAMP_NIC:
            hCurrC = 0 - this->mStatCurrUVW.nPhaseU - this->mStatCurrUVW.nPhaseV;

            break;
        default:
            wAux = 0;
            break;
    }

    GET_ADC1_DATA(mADC_Result);
    /* Second sampling point */
    switch (this->bSampCur2)
    {
        case SAMP_IA:
            wAux = (s32)(this->nPhaseAOffset) - mADC_Result.nData0;
            hCurrA = sat(wAux, S16_MIN, S16_MAX);

            bCurrASamp = 1;
            break;

        case SAMP_IB:

            wAux = (s32)(this->nPhaseBOffset) - mADC_Result.nData0;
            hCurrB = sat(wAux, S16_MIN, S16_MAX);

            bCurrBSamp = 1;
            break;

        case SAMP_IC:

            wAux = (s32)(this->nPhaseCOffset) - mADC_Result.nData0;
            hCurrC = sat(wAux, S16_MIN, S16_MAX);

            break;
        case SAMP_NIA:
            hCurrA = this->mStatCurrUVW.nPhaseU;
            bCurrASamp = 1;

            break;
        case SAMP_NIB:
            hCurrB = this->mStatCurrUVW.nPhaseV;
            bCurrBSamp = 1;

            break;
        case SAMP_NIC:
            hCurrC = 0 - this->mStatCurrUVW.nPhaseU - this->mStatCurrUVW.nPhaseV;

            break;
        default:
            wAux = 0;
            break;
    }
    if (bCurrASamp == 0)
    {
        /* ���ʹ��� hd */
        wAux = -hCurrB - hCurrC;
        hCurrA = sat(wAux, S16_MIN, S16_MAX);
    }
    if (bCurrBSamp == 0)
    {
        wAux = -hCurrA - hCurrC;
        hCurrB = sat(wAux, S16_MIN, S16_MAX);
    }

    Local_Stator_Currents.nPhaseU = hCurrA;
    Local_Stator_Currents.nPhaseV = hCurrB;

    return (Local_Stator_Currents);
}

/*******************************************************************************
 �������ƣ�    void ADC_NormalModeCFG(void)
 ����������    ADC��������ģʽͨ������
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void ADC_NormalModeCFG(void)
{
    ADC_CHN0 = ADC_CURRETN_A_CHANNEL | (ADC_CURRETN_B_CHANNEL << 4) | (ADC_CURRETN_A_CHANNEL << 8) | (ADC_CURRETN_B_CHANNEL << 12);
    ADC_CHN1 = ADC_BUS_VOL_CHANNEL | (ADC_BUS_VOL_CHANNEL << 4);

    struFOC_CurrLoop.ADC_A_B_CurrentSamp = ADC_CURRETN_A_CHANNEL | (ADC_CURRETN_B_CHANNEL << 4) | (ADC_CURRETN_A_CHANNEL << 8) | (ADC_CURRETN_B_CHANNEL << 12);
    struFOC_CurrLoop.ADC_A_C_CurrentSamp = ADC_CURRETN_A_CHANNEL | (ADC_CURRETN_C_CHANNEL << 4) | (ADC_CURRETN_A_CHANNEL << 8) | (ADC_CURRETN_C_CHANNEL << 12);
    struFOC_CurrLoop.ADC_B_C_CurrentSamp = ADC_CURRETN_B_CHANNEL | (ADC_CURRETN_C_CHANNEL << 4) | (ADC_CURRETN_B_CHANNEL << 8) | (ADC_CURRETN_C_CHANNEL << 12);
}


/*******************************************************************************
 �������ƣ�    void MCPWM0_RegUpdate(void)
 ����������    ����MCPWMģ��ռ�ձ�ֵ������MCPWMģ��ADC������Ĵ���ֵ
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void MCPWM0_RegUpdate(void)
{
    MCPWM_TH00 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;
    MCPWM_TH01 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseU;

    MCPWM_TH10 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;
    MCPWM_TH11 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseV;

    MCPWM_TH20 = -struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;
    MCPWM_TH21 = struFOC_CurrLoop.mVoltUVW_PWM.nPhaseW;

}

#endif

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* ------------------------------END OF FILE------------------------------------ */
