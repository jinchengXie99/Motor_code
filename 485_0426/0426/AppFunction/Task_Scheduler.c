/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� Time_Process.c
 * �ļ���ʶ��
 * ����ժҪ�� ��ʱ��غ���
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet Li
 * ������ڣ� 2020��8��16��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2020��8��16��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�Howlet Li
 * �޸����ݣ�����
 *
 *******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "basic.h"
#include "Global_Variable.h"
#include "math.h"
#include "Time_Process.h"
#include "hardware_config.h"
#include "fault_detection.h"
#include "PowerCalculation.h"
#include "USER_APP.h"
#include "HeatControl.h"
void Sys_State_Machine(void);
void NTCAD_tempreal(void);
void StartUpProcess(void);

/*******************************************************************************
 �������ƣ�    void Task_Scheduler(void)
 ����������    ��ʱ��Ƭ������Ⱥ���
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
 u16 heat=0;
void Task_Scheduler(void)
{
    volatile u32 t_data;
	
    heat=CELSIUS_0_ADC_B ;
    if (struTaskScheduler.bTimeCnt1ms >= TASK_SCHEDU_1MS)
    {
        /* 1�����¼���������� */

        struTaskScheduler.bTimeCnt1ms = 0;

        SetTime_CountDown();  /* ������������ʱ���� */

        FaultCheck();    //ÿ5ms����һ����ϼ�⼰��Ӧ���ϵ��� ������Ƿѹ��� case1-��Ƿѹ case2-��ת��� case3-�¶ȼ�� case4-ȱ���� case5-����ʧ��  ���������AD�ж�  Ӳ�������ڱȽ����ж�
			
		USER_APP_vTick1ms(); //���ٷ��°������ �����ź��Ƿ�����
					
		GetVdcSpeed();  //�ٶȸ��� ��������Ż��ڴ˺���
		
        if(stru_Faults.R != 0)   //���ֹ��������FAULT״̬
        {
            struFOC_CtrProc.eSysState = FAULT;
        }
		
        Sys_State_Machine(); /* ���0״̬������ */
				

        DcVoltPerUnitCalc(struFOC_CurrLoop.nBusVoltage);  /* ֱ��ĸ�ߵ�ѹ���ۻ����� */
        
    }

    if (struTaskScheduler.nTimeCnt10ms >= TASK_SCHEDU_10MS)
    {
        /* 10�����¼���������� */
        struTaskScheduler.nTimeCnt10ms = 0;
			NTCAD_tempreal();  //NTCʵ���¶�ֵ
				USER_APP_vTick10ms();  //���ʼ��� ����ת�л�  ����˿NTC��� IPM NTC��� �ػ�����
        #if ((ROTOR_SENSOR_TYPE == ROTOR_HALL_SENSOR) || (ROTOR_SENSOR_TYPE == ROTOR_HALL2SENSORLESS))
        Hall_learn_Process();   /* Hall��ѧϰ�㷨 */
        #endif
    }
    if (struTaskScheduler.nTimeCnt100ms >= TASK_SCHEDU_100MS)
    {
        /* 100�����¼���������� */
        struTaskScheduler.nTimeCnt100ms = 0;
			
			#if (TEMP_CONSTANT_FUNCTION == FUNCTION_ON)  //����˿���¿����Ƿ��
			  if(FRSControl.TurnOnOffFlag == 1)   
				{
			     HeaterTemperature_Control();  ////����˿���������������� �����С�޷�
					
				}
//				HeaterTemperature_Control();
			#endif
    }
		
		
		
    if (struTaskScheduler.nTimeCnt500ms >= TASK_SCHEDU_500MS)
    {
        /* 500�����¼���������� */
        struTaskScheduler.nTimeCnt500ms = 0;
		
//		if(UserSys.RunTime<5000)
//		{
//			UserSys.RunTime++;
//		}
//		if(FRSControl.CrossDownAcState==1)
//		{
//			UserSys.RunTime=0;
//		}
     
		
			#ifdef  MemoryMode //lgh
					vLoadForFlashing();
		  #endif
			   USER_APP_vTick500ms();   //���³���
    }

    if(struTaskScheduler.bPWM_UpdateFlg)
    {
        /* ÿ��PWM���ڸ���һ�� */
        struTaskScheduler.bPWM_UpdateFlg = 0;

        #if ((ROTOR_SENSOR_TYPE == ROTOR_HALL_SENSOR) || (ROTOR_SENSOR_TYPE == ROTOR_HALL2SENSORLESS))
        Verify_Hall_State(HALL, &struHallProcess);  /* hall ������ */
        #endif

    }
	


}

/*******************************************************************************
 �������ƣ�    void SoftDelay(void)
 ����������    �����ʱ����
 ���������    ��
 ���������    ��
 �� �� ֵ��    ��
 ����˵����
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          ����
 *******************************************************************************/
void SoftDelay(u32 cnt)
{
    volatile u32 t_cnt;

    for(t_cnt = 0; t_cnt < cnt; t_cnt++)
    {
        __nop();
    }
}


/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* ------------------------------END OF FILE------------------------------------ */



