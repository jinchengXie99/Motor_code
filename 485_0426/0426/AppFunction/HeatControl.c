/*******************************************************************************
 * 版权所有 (C)2022, LINKO SEMICONDUCTOR Co.ltd
 *
 * 文件名称： HeatControl.c
 * 文件标识：
 * 内容摘要： KeyScan
 * 其它说明： 无
 * 当前版本： V1.0
 * 作    者： Robin Chen
 * 完成日期： 2022年12月13日
 *
 *******************************************************************************/
#include "HeatControl.h"
#include "USER_APP.h"
const uint8_t HotTab[2500]={  
	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0, /* 0 */
	1,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0, /* 1 */
	1,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,1,0,0,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,1,	0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0, /* 2 */
	1,0,0,0,0,	0,0,0,0,0,	0,0,1,0,0,	0,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0,	0,0,1,0,0,	0,0,0,0,0,	0,0,0,0,0, /* 3 */
	1,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,0,0,0, /* 4 */

	1,0,0,0,0,	0,0,0,1,0,	0,0,0,0,0,	0,1,0,0,0,	0,0,0,0,0,	1,0,0,0,0,	0,1,0,0,0,	0,0,0,0,0,	0,1,0,0,0,	0,0,0,0,0, /* 5 */
	1,0,0,0,0,	0,0,1,0,0,	0,0,0,0,1,	0,0,0,0,0,	0,1,0,0,0,	0,0,0,1,0,	0,0,0,0,0,	1,0,0,0,0,	0,0,1,0,0,	0,0,0,0,0, /* 6 */
	1,0,0,0,0,	0,0,1,0,0,	0,0,0,1,0,	0,0,0,0,1,	0,0,0,0,0,	1,0,0,0,0,	0,0,1,0,0,	0,0,0,1,0,	0,0,0,0,1,	0,0,0,0,0, /* 7 */
	1,0,0,0,0,	0,1,0,0,0,	0,1,0,0,0,	0,0,1,0,0,	0,0,1,0,0,	0,0,0,1,0,	0,0,0,1,0,	0,0,0,0,1,	0,0,0,0,1,	0,0,0,0,0, /* 8 */	
	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0,	1,0,0,0,0, /* 9 */

	1,0,0,0,0,	1,0,0,0,1,	0,0,0,0,1,	0,0,0,1,0,	0,0,0,1,0,	0,0,1,0,0,	0,0,1,0,0,	0,1,0,0,0,	0,1,0,0,0,	1,0,0,0,0, /* 10 */
	1,0,0,0,0,	1,0,0,0,1,	0,0,0,1,0,	0,0,1,0,0,	0,1,0,0,0,	1,0,0,0,0,	1,0,0,0,1,	0,0,0,1,0,	0,0,1,0,0,	0,1,0,0,0, /* 11 */
	1,0,0,1,0,	0,0,1,0,0,	0,1,0,0,0,	1,0,0,0,1,	0,0,0,1,0,	0,1,0,0,0,	1,0,0,0,1,	0,0,0,1,0,	0,0,1,0,0,	0,1,0,0,0, /* 12 */
	1,0,0,0,1,	0,0,1,0,0,	0,1,0,0,1,	0,0,0,1,0,	0,1,0,0,0,	1,0,0,1,0,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0,	0,1,0,0,0, /* 13 */
	1,0,0,0,1,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0, /* 14 */
	
	1,0,0,0,1,	0,0,1,0,0,	1,0,0,1,0,	0,1,0,0,1,	0,0,1,0,0,	1,0,0,0,1,	0,0,1,0,0,	1,0,0,1,0,	0,1,0,0,1,	0,0,1,0,0, /* 15 */
	1,0,0,1,0,	0,1,0,0,1,	0,0,1,0,0,	1,0,0,1,0,	0,1,0,0,1,	0,0,1,0,0,	1,0,0,1,0,	0,1,0,0,1,	0,0,1,0,0,	1,0,0,1,0, /* 16 */
	1,0,1,0,0,	1,0,0,1,0,	0,1,0,1,0,	0,1,0,0,1,	0,0,1,0,0,	1,0,1,0,0,	1,0,0,1,0,	0,1,0,1,0,	0,1,0,0,1,	0,0,1,0,0, /* 17 */
	1,0,1,0,0,	1,0,0,1,0,	1,0,0,1,0,	0,1,0,1,0,	0,1,0,0,1,	0,1,0,0,1,	0,0,1,0,1,	0,0,1,0,0,	1,0,1,0,0,	1,0,0,1,0, /* 18 */
	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0,	1,0,1,0,0, /* 19 */	
	
	1,0,0,1,0,	1,0,1,0,0,	1,0,1,0,1,	0,0,1,0,1,	0,1,0,0,1,	0,1,0,1,0,	0,1,0,1,0,	1,0,0,1,0,	1,0,1,0,0,	1,0,1,0,0, /* 20 */
	1,0,0,1,0,	1,0,1,0,0,	1,0,1,0,1,	0,1,0,0,1,	0,1,0,1,0,	1,0,0,1,0,	1,0,1,0,0,	1,0,1,0,1,	0,1,0,0,1,	0,1,0,1,0, /* 21 */
	1,0,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,0,1,0,1,	0,1,0,1,0, /* 22 */
	1,0,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0, /* 23 */
	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0, /* 24 */
	
	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,0,1,0,	1,0,1,0,0, /* 25 */
	1,1,0,1,0,	1,0,1,0,1,	0,1,0,1,1,	0,1,0,1,0,	1,0,1,0,1,	0,1,1,0,1,	0,1,0,1,0,	1,0,1,0,1,	1,0,1,0,1,	0,1,0,1,0, /* 26 */
	1,1,0,1,0,	1,0,1,1,0,	1,0,1,0,1,	0,1,1,0,1,	0,1,0,1,0,	1,1,0,1,0,	1,0,1,1,0,	1,0,1,0,1,	0,1,1,0,1,	0,1,0,1,0, /* 27 */
	0,1,1,0,1,  0,1,0,1,1,  0,1,0,1,0,  1,1,0,1,0,  1,0,1,1,0,  1,0,1,0,1,  1,0,1,0,1,  0,1,1,0,1,  0,1,0,1,1,  0,1,0,1,1, /* 28 */
	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1,	0,1,0,1,1, /* 29 */
	
	0,1,0,1,1,  0,1,1,0,1,  0,1,1,0,1,  1,0,1,0,1,  1,0,1,1,0,  1,0,1,1,0,  1,1,0,1,0,  1,1,0,1,1,  0,1,0,1,1,  0,1,1,0,1, /* 30 */
	0,1,0,1,1,  0,1,1,0,1,  1,0,1,0,1,  1,0,1,1,0,  1,1,0,1,1,  0,1,0,1,1,  0,1,1,0,1,  1,0,1,0,1,  1,0,1,1,0,  1,1,0,1,1, /* 31 */
	0,1,1,0,1,  1,0,1,1,0,  1,1,0,1,1,  0,1,1,0,1,  1,0,1,1,0,  1,1,0,1,1,  0,1,1,0,1,  1,0,1,1,0,  1,1,0,1,1,  0,1,1,0,1, /* 32 */
	0,1,1,1,0,  1,1,0,1,1,  0,1,1,0,1,  1,0,1,1,0,  1,1,0,1,1,  0,1,1,1,0,  1,1,0,1,1,  0,1,1,0,1,  1,0,1,1,0,  1,1,0,1,1, /* 33 */
	0,1,1,1,0,  1,1,0,1,1,  0,1,1,1,0,  1,1,0,1,1,  0,1,1,1,0,  1,1,0,1,1,  0,1,1,1,0,  1,1,0,1,1,  0,1,1,1,0,  1,1,0,1,1, /* 34 */
	
	0,1,1,1,0,	1,1,0,1,1,	1,0,1,1,0,	1,1,1,0,1,	1,0,1,1,1,	0,1,1,0,1,	1,1,0,1,1,	0,1,1,1,0,	1,1,0,1,1,  1,0,1,1,1, /* 35 */
	0,1,1,0,1,  1,1,0,1,1,	1,0,1,1,1,  0,1,1,1,0,  1,1,1,0,1,  1,0,1,1,1,  0,1,1,1,0,  1,1,1,0,1,  1,1,0,1,1,  1,0,1,1,1, /* 36 */
	0,1,1,1,1,	0,1,1,1,0,	1,1,1,0,1,	1,1,0,1,1,	1,0,1,1,1,	0,1,1,1,1,	0,1,1,1,0,	1,1,1,0,1,	1,1,0,1,1,	1,0,1,1,1, /* 37 */
	0,1,1,1,1,	0,1,1,1,0,	1,1,1,1,0,	1,1,1,0,1,	1,1,1,0,1,	1,1,0,1,1,	1,1,0,1,1,	1,0,1,1,1,	1,0,1,1,1,	0,1,1,1,1, /* 38 */
	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1,	0,1,1,1,1, /* 39 */
	
	0,1,1,1,1,	1,0,1,1,1,	1,0,1,1,1,	1,1,0,1,1,	1,1,0,1,1,	1,1,1,0,1,	1,1,1,0,1,	1,1,1,1,0,	1,1,1,1,0,	1,1,1,1,1, /* 40 */
	0,1,1,1,1,	1,1,0,1,1,	1,1,1,0,1,	1,1,1,1,0,	1,1,1,1,1,	0,1,1,1,1,	1,1,0,1,1,	1,1,1,0,1,	1,1,1,1,0,	1,1,1,1,1, /* 41 */
	0,1,1,1,1,	1,1,0,1,1,	1,1,1,1,0,	1,1,1,1,1,	1,0,1,1,1,	1,1,1,0,1,	1,1,1,1,1,	0,1,1,1,1,	1,1,0,1,1,	1,1,1,1,1, /* 42 */
	0,1,1,1,1,	1,1,1,0,1,	1,1,1,1,1,	1,0,1,1,1,	1,1,1,1,1,	0,1,1,1,1,	1,0,1,1,1,	1,1,1,1,1,	1,0,1,1,1,	1,1,1,1,1, /* 43 */
	1,1,1,1,0,	1,1,1,1,1,	1,1,1,1,0,	1,1,1,1,1,	1,1,1,1,0,	1,1,1,1,1,	1,1,1,1,0,	1,1,1,1,1,	1,1,1,1,0,	1,1,1,1,1, /* 44 */
	
	1,0,1,1,1,	1,1,1,1,1,	1,1,1,0,1,	1,1,1,1,1,	1,1,1,1,1,	1,0,1,1,1,	1,1,1,1,1,	1,1,1,0,1,	1,1,1,1,1,	1,1,1,1,1, /* 45 */
	1,0,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,0,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	0,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1, /* 46 */
	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,0,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,0, /* 47 */
	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,0, /* 48 */
	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1,	1,1,1,1,1, /* 49 */
};


HEAT_CONTROL FRSControl;
void HeaterControl(void);
void HeaterTemperature_Control(void);

/*****************************************************************************
 * Function:     void HeaterControl(void)
 * Description:  发热丝控制
 * Parameter:    no
 * Return:       no
 *****************************************************************************/
 /*****************************************************************************
 * Function:     void HeaterControl(void)
 * Description:  发热丝控制
 * Parameter:    no
 * Return:       no
 *****************************************************************************/
 u8 FRS_ON=0;
u8 ControlOFF;
u16 jj=0;
u8 reg=0;
s16 Ubusmax = 0;
u8  Ubusmaxcnt = 0;
u32 Ubusmaxsum = 0;
u16 Ubusmaxavg = 0;
u8  Ubusmaxsumcnt = 0;

extern u8 NTCorStaller;
void HeaterControl(void)
{
	 #if(FullWaveorHalfWave == TRUE)     //全波半波发热丝模式   TRUE-全波  false -半波
   {
      //电机正常工作 转速正常 开机延迟时间 无过温 无NTC短路 开路
			if((struFOC_CtrProc.eSysState == RUN)&&(struMotorSpeed.wSpeedEst > 15000)&&(stru_Faults.R == 0)&&(FRSControl.TurnOnDelayCnt>=HEATER_DELAY_ON_TIME)&&(UserSys.ucUserFunState == USERFUN_STATE_NORMAL)&&(TempOverFlag==0))  //判断发热丝工作条件
			{
				FRSControl.TurnOnOffFlag = 1;  //发热丝正常工作
			}
			else
			{
				FRSControl.TurnOnOffFlag = 0;  //发热丝工作关闭
			}

		
//			 FRSControl.ThrowWaveCnt = 16  ;
			if((FRSControl.CrossZeroStateLast == 1)&&(FRSControl.CrossZeroState == 0))  //过零信号发生下降沿
			{
				if(FRSControl.TurnOnOffFlag ==1)
				{
					FRSControl.ThrowWaveFlag =1;	

					FRSControl.CrossZeroCnt ++;    //过零次数计数

					if(FRSControl.ThrowWaveMode == ThrowHalfWave)   //半波丢波模式
					{
						if(FRSControl.CrossZeroCnt > 49)
						{
							FRSControl.CrossZeroCnt = 0;
						}
						FRSControl.ThrowWaveTabIndex= HotTab[(FRSControl.ThrowWaveCnt*50)+(FRSControl.CrossZeroCnt)];  //发热丝开通状态查表
					}
					else   //全波丢波模式
					{
						if(FRSControl.CrossZeroCnt > 99)
						{
							FRSControl.CrossZeroCnt = 0;
						}
						FRSControl.ThrowWaveTabIndex= HotTab[(FRSControl.ThrowWaveCnt*50)+(FRSControl.CrossZeroCnt>>1)];  //发热丝开通状态查表
					}
				}
				else
				{
		////			 HEATER_CONTROL_OFF();           //发热丝关
		//		   FRSControl.ThrowWaveDelayCnt = 0;
		//			 FRSControl.ThrowWaveFlag = 0;
				}
			}
			
			if(FRSControl.TurnOnOffFlag ==1)
			{
				if(FRSControl.ThrowWaveFlag == 1)
				{				
							FRSControl.ThrowWaveDelayCnt ++;  //丢波延时计数
							 
					if(FRSControl.ACFrequency == AC50Hz)
					{
						if(FRSControl.ThrowWaveDelayCnt >= FRSControl.AC50HzThrowWaveDelayCnt)  //丢波延时  //载波22K 50Hz10ms（220）
						{
							FRSControl.ThrowWaveDelayCnt = 0;
							if(FRSControl.ThrowWaveTabIndex == 1)    //此周期需要开可控硅
							{
								HEATER_CONTROL_ON();        //发热丝开
								FRSControl.ThrowWaveFlag = 0;
								FRS_ON = 1;
								FRSControl.activecnt =270;    //15ms左右
							}
							else
							{
								HEATER_CONTROL_OFF();       //发热丝关
								FRSControl.ThrowWaveFlag = 0;
								FRS_ON = 0;
							}
						}
					}
					else if(FRSControl.ACFrequency == AC60Hz)
					{

					}
					else
					{
		//							 HEATER_CONTROL_OFF();           //发热丝关
		//							 FRSControl.ThrowWaveDelayCnt = 0;
		//							 FRSControl.ThrowWaveFlag = 0;
					} 
				}
			}
			else
			{
				HEATER_CONTROL_OFF();           //发热丝关
				FRSControl.ThrowWaveDelayCnt = 0;
				FRSControl.ThrowWaveFlag = 0;
			}
		 
			if(FRS_ON)
			{
				if(FRSControl.activecnt >=1)
				{
					FRSControl.activecnt--;
				}
				if(FRSControl.activecnt==0)
				{
					HEATER_CONTROL_OFF();  
					FRS_ON = 0;		
				}
			}
			
			FRSControl.CrossZeroStateLast = FRSControl.CrossZeroState;
    }
    #elif (FullWaveorHalfWave == FALSE)  //全波半波发热丝模式   TRUE-全波  false -半波
		{
				if((struFOC_CtrProc.eSysState == RUN)&&(struMotorSpeed.wSpeedEst > 15000)&&(stru_Faults.R == 0)&&(FRSControl.TurnOnDelayCnt>=HEATER_DELAY_ON_TIME)&&(UserSys.ucUserFunState == USERFUN_STATE_NORMAL)&&(TempOverFlag ==0)&&(NTCorStaller==0)&&(NTCOPENErrorFlag==0)&&(NTCSHORTErrorFlag==0))  //判断发热丝工作条件
				{
					FRSControl.TurnOnOffFlag = 1;  //发热丝正常工作
				}
				else
				{
					FRSControl.TurnOnOffFlag = 0;  //发热丝工作关闭
				}
				 FRSControl.ThrowWaveCnt = 16  ;
				FRSControl.CrossZeroState = ZERO_SCR();    //读取过零信号电平
				if((FRSControl.CrossZeroStateLast == 1)&&(FRSControl.CrossZeroState == 0))  //过零信号发生上升沿
				{
					FRSControl.CrossZeroPosedge =1;
					FRSControl.ACFrequencyDetectCnt = 222;    //依据斩波频率计算  大概10ms左右的数值 例如16K-162 22k-222
				}
				if(FRSControl.ACFrequencyDetectCnt>0)
				{
					FRSControl.ACFrequencyDetectCnt--;
				}
				if(FRSControl.ACFrequencyDetectCnt==1)
				{
					FRSControl.CrossZeroPosedge =1;
				}
				
			//	FRSControl.ThrowWaveCnt=8;

				if(FRSControl.CrossZeroPosedge ==1 )
				{
					FRSControl.CrossZeroCnt ++;    //过零次数计数
					
					if(FRSControl.CrossZeroCnt >49)
					{
						FRSControl.CrossZeroCnt = 0;
					}
					FRSControl.ThrowWaveTabIndex= HotTab[(FRSControl.ThrowWaveCnt*50)+(FRSControl.CrossZeroCnt)];  //发热丝开通状态查表
					FRSControl.ThrowWaveFlag = 1;
					FRSControl.CrossZeroPosedge =0;
				}	
				if(FRSControl.TurnOnOffFlag ==1)
				{
					if(FRSControl.ThrowWaveFlag == 1)
					{
						FRSControl.ThrowWaveDelayCnt ++;  //丢波延时计数		 	
						if(FRSControl.ThrowWaveDelayCnt >= FRSControl.AC50HzThrowWaveDelayCnt)  //丢波延时  //载波22K 50Hz10ms（220）
						{
							FRSControl.ThrowWaveDelayCnt = 0;
							if(FRSControl.ThrowWaveTabIndex == 1)    //此周期需要开可控硅
							{
								HEATER_CONTROL_ON();        //发热丝开
							
								FRSControl.ThrowWaveFlag = 0;
								FRS_ON = 1;
								FRSControl.activecnt =29;
							}
							else
							{
								HEATER_CONTROL_OFF();       //发热丝关
							
								FRSControl.ThrowWaveFlag = 0;
								FRS_ON = 0;
							}
						}	
					}
				}
				else
				{
					HEATER_CONTROL_OFF();           //发热丝关
					
					FRSControl.ThrowWaveDelayCnt = 0;
					FRSControl.ThrowWaveFlag = 0;
				}
				if(FRS_ON)
				{
					if(FRSControl.activecnt >=1)
					{
						FRSControl.activecnt--;
					}
					if(FRSControl.activecnt==0)
					{
						HEATER_CONTROL_OFF(); 
								 ;			
						FRS_ON = 0;	
					}
				}
				FRSControl.CrossZeroStateLast = FRSControl.CrossZeroState;                   
		}
		#endif
	
	

	 
}


/*****************************************************************************
 * Function:     void HeaterTemperature_Control(void)
 * Description:  发热丝温度控制
 * Parameter:    no
 * Return:       no
 *****************************************************************************/
u8 xxxx = 0;
s16 testtemp=32000;
u16 startcnt=0;
void HeaterTemperature_Control(void)
{
	FRSControl.Ubusmaxavg_temp=(u32)(FRSControl.Ubusmaxavg/(32767.0)/VOLTAGE_SHUNT_RATIO*ADC_SUPPLY_VOLTAGE );   //FRSControl.Ubusmaxavg取最大电压值 用于根据电压限发热丝功率
	if(iTargetGear==0)
	{
	  if(TempGear ==1)   
		{
			FRSControl.TargetTemperature = NTCTempAD(TEM_SET1);
			FRSControl.TargetTemperaturereal = (TEM_SET1);
			FRSControl.ThrowWaveBase = 16;            //标定好的丢波基础值 
			FRSControl.ThrowWaveLimitMin =0;        //丢波下限值
			FRSControl.ThrowWaveLimitMax =18;         //丢波上限值   15低6   20-减10  17-高3 16-
			//FRSControl.ThrowWaveCnt =10;	
		}
		else if(TempGear==2)  //1100W左右
		{
			FRSControl.TargetTemperature =NTCTempAD(TEM_SET2);
			FRSControl.TargetTemperaturereal =(TEM_SET2);
			FRSControl.ThrowWaveBase = 35;            //标定好的丢波基础值  33低10  38-高5°  36-
			FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
			FRSControl.ThrowWaveLimitMax = 37;         //丢波上限值		
		}
		else 
		{
			FRSControl.TargetTemperature =0;
			FRSControl.TargetTemperaturereal =0;
			FRSControl.ThrowWaveBase = 0;            //标定好的丢波基础值 
			FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
			FRSControl.ThrowWaveLimitMax =0;         //丢波上限值							
		}
		
		
//		if(FRSControl.Ubusmaxavg_temp>311)
//		{
//			FRSControl.OverVloLimitMax=(s16)((FRSControl.Ubusmaxavg_temp-311)/K_Vol_ThrowWave*K_ThrowWave1);
//			FRSControl.ThrowWaveLimitMax-=FRSControl.OverVloLimitMax;			
//		}
//    else
//		{
//		 FRSControl.OverVloLimitMax=(s16)((311-FRSControl.Ubusmaxavg_temp)/K_Vol_ThrowWave*K_ThrowWave1);
//		 FRSControl.ThrowWaveLimitMax+=FRSControl.OverVloLimitMax;			
//		}
		
	}
	
	else if(iTargetGear==1)
	{
	  if(TempGear ==1)
		{
			FRSControl.TargetTemperature =NTCTempAD(TEM_SET3);
			FRSControl.TargetTemperaturereal =(TEM_SET3);
			FRSControl.ThrowWaveBase = 17;            //标定好的丢波基础值 
			FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
			FRSControl.ThrowWaveLimitMax = 19;         //丢波上限值
			//FRSControl.ThrowWaveCnt =10;	
		}
		else if(TempGear==2)
		{
			startcnt++;
//			startcnt=605;
			if(startcnt<=700)
			{
				FRSControl.TargetTemperature = NTCTempAD(TEM_SET4_1min);
				FRSControl.TargetTemperaturereal = (TEM_SET4_1min);
				FRSControl.ThrowWaveBase = 49;            //标定好的丢波基础值 
				FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
				FRSControl.ThrowWaveLimitMax = 49;         //丢波上限值		
			}
			else 
			{
				if(startcnt>800)
			   startcnt=805;
				FRSControl.TargetTemperature = NTCTempAD(TEM_SET4);
				FRSControl.TargetTemperaturereal = (TEM_SET4);
				FRSControl.ThrowWaveBase = 40;            //标定好的丢波基础值 
				FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
				FRSControl.ThrowWaveLimitMax = 41;         //丢波上限值	
			
			}
			
		}
		else
		{
			FRSControl.TargetTemperature =0;
			FRSControl.TargetTemperaturereal =0;
			FRSControl.ThrowWaveBase = 0;            //标定好的丢波基础值 
			FRSControl.ThrowWaveLimitMin = 0;        //丢波下限值
			FRSControl.ThrowWaveLimitMax =0;         //丢波上限值							
		}
//		if(FRSControl.Ubusmaxavg_temp>311)
//		{
//			FRSControl.OverVloLimitMax=(s16)((FRSControl.Ubusmaxavg_temp-311)/K_Vol_ThrowWave*K_ThrowWave2);
//			FRSControl.ThrowWaveLimitMax-=FRSControl.OverVloLimitMax;			
//		}
//    else
//		{
//		 FRSControl.OverVloLimitMax=(s16)((311-FRSControl.Ubusmaxavg_temp)/K_Vol_ThrowWave*K_ThrowWave2);
//		 FRSControl.ThrowWaveLimitMax+=FRSControl.OverVloLimitMax;			
//		}	
	}
	
	FRSControl.ThrowWaveLimitMax=(s16)(FRSControl.ThrowWaveLimitMax*(315)*(315)/FRSControl.Ubusmaxavg_temp/FRSControl.Ubusmaxavg_temp);
	
	if(FRSControl.ThrowWaveLimitMax>49)
		{
		FRSControl.ThrowWaveLimitMax=49;
		}
		
		if(TempGear==0)
			
		{
		FRSControl.ThrowWaveLimitMax=0;
		}
//	  if((FRSControl.ThrowWaveCnt > FRSControl.ThrowWaveLimitMax) || (FRSControl.ThrowWaveCnt < FRSControl.ThrowWaveLimitMin))
//		{
//		   FRSControl.ThrowWaveCnt = FRSControl.ThrowWaveBase;
//		}
//	
//		if(FRSControl.HEATER_NTCTemperature > FRSControl.TargetTemperature)
//		{   
//			  if(FRSControl.ThrowWaveCnt < FRSControl.ThrowWaveLimitMax)
//				{   
//					  if(FRSControl.ThrowWaveCnt < 49)
//						{
//                FRSControl.ThrowWaveCnt ++;
//						}
//				}
//		}
//		else if (FRSControl.HEATER_NTCTemperature < FRSControl.TargetTemperature)
//		{
//			  if(FRSControl.ThrowWaveCnt > FRSControl.ThrowWaveLimitMin)
//				{
//						if(FRSControl.ThrowWaveCnt > 0)
//						{
//                FRSControl.ThrowWaveCnt --;
//						}
//				}
//		}
}





void HeaterControl_1ms(void)                 //判断过零信号是否正常 
{
	FRSControl.ThrowWaveMode = ThrowHalfWave;  //丢波模式默认丢*波 半波：ThrowHalfWave  全波：ThrowFullWave

	if(FRSControl.CrossZeroState == 1)
	{
		if(FRSControl.CrossZeroVoltageCnt1 < CROSSZERO_CNT2)   //50
		{
			FRSControl.CrossZeroVoltageCnt1++;
		}		
	}
	else if(FRSControl.CrossZeroState==0)
	{
		if(FRSControl.CrossZeroVoltageCnt1>0)
		{
			if((FRSControl.CrossZeroVoltageCnt1 < CROSSZERO_CNT1)&&(FRSControl.CrossZeroVoltageCnt2 < CROSSZERO_CNT1))//15
			{
				if(FRSControl.CrossDownAcStateCnt<100)
				{
					FRSControl.CrossDownAcStateCnt++;
				}
			}

			FRSControl.CrossZeroVoltageCnt1=0;
			FRSControl.CrossZeroVoltageCnt2=0;
		}
		
		if(FRSControl.CrossZeroVoltageCnt2 < CROSSZERO_CNT2)
		{
			FRSControl.CrossZeroVoltageCnt2++;
		}				
	}
	
	if(FRSControl.CrossZeroVoltageCnt2 > CROSSZERO_CNT1)
	{
		FRSControl.CrossDownAcState=AC_ZERO_OFF;
		FRSControl.CrossDownAcStateCnt = 0;
	}

	if(FRSControl.CrossZeroVoltageCnt1 > CROSSZERO_CNT1) //15
	{
		FRSControl.CrossDownAcState=AC_ZERO_OFF;
		FRSControl.CrossDownAcStateCnt = 0;
	}
	
	if(FRSControl.CrossDownAcStateCnt>5)
	{
		FRSControl.CrossDownAcState = AC_ZERO_ON;
	}
		if(struFOC_CurrLoop.nBusVoltage > Ubusmax)
		{
		Ubusmax = struFOC_CurrLoop.nBusVoltage;
		}
    
    if(++Ubusmaxcnt > 20)
    {
      Ubusmaxcnt = 0;
      Ubusmaxsum += Ubusmax;
      if(++Ubusmaxsumcnt >= 16)
      {
        FRSControl.Ubusmaxavg = Ubusmaxsum >> 4;
        Ubusmaxsum = 0;
        Ubusmaxsumcnt = 0; 
      }
      Ubusmax = 0;
    }
}


s16 TempAD;
	s32 NTCResistor;
	s16 NTCResistor1;

s16 NTCTempAD(s16 TargetTemp)
{
	
//	NTCResistor = NTCResistor10(TargetTemp);
//	NTCResistor1 = NTCResistor*ParallResistor*10/(NTCResistor+ParallResistor*10);
//	TempAD = 45510*NTCResistor1/(PullUpResistor*10+NTCResistor1);
	
	NTCResistor = NTCResistor10(TargetTemp);
	//NTCResistor1 = PullDownResistor*10/(NTCResistor+PullUpResistor*10+PullDownResistor*10)   NTCResistor*ParallResistor*10/(NTCResistor+ParallResistor*10);
	TempAD = 45510*PullDownResistor*10/(NTCResistor+PullUpResistor*10+PullDownResistor*10);   
	
	
	return TempAD;
}
s32 NTCR;
s32 NTCResistor10(s16 TargetTemp)
{
 if((TargetTemp>-30)&&(TargetTemp<=-10))
	{
		NTCR = NTCn30C*10+(TargetTemp+30)*(NTCn10C-NTCn30C)/2;
	}
	else if((TargetTemp>-10)&&(TargetTemp<=0))
	{
		NTCR = NTCn10C*10+(TargetTemp+10)*(NTC00C-NTCn10C)/1;
	}
	else if((TargetTemp>0)&&(TargetTemp<=30))
	{
		NTCR = NTC00C*10+(TargetTemp-0)*(NTC30C-NTC00C)/3;
	}
	else if((TargetTemp>30)&&(TargetTemp<=50))
	{
		NTCR = NTC30C*10+(TargetTemp-30)*(NTC50C-NTC30C)/2;
	}
	else if((TargetTemp>50)&&(TargetTemp<=60))
	{
		NTCR = NTC50C*10+(TargetTemp-50)*(NTC60C-NTC50C);
	}
	else if((TargetTemp>60)&&(TargetTemp<=70))
	{
		NTCR = NTC60C*10+(TargetTemp-60)*(NTC70C-NTC60C);
	}
	else if((TargetTemp>70)&&(TargetTemp<=80))
	{
		NTCR = NTC70C*10+(TargetTemp-70)*(NTC80C-NTC70C);
	}
	else if((TargetTemp>80)&&(TargetTemp<=90))
	{
		NTCR = NTC80C*10+(TargetTemp-80)*(NTC90C-NTC80C);
	}
	else if((TargetTemp>90)&&(TargetTemp<=100))
	{
		NTCR = NTC90C*10+(TargetTemp-90)*(NTC100C-NTC90C);
	}
	else if((TargetTemp>100)&&(TargetTemp<=110))
	{
		NTCR = NTC100C*10+(TargetTemp-100)*(NTC110C-NTC100C);
	}
	else if((TargetTemp>110)&&(TargetTemp<=120))
	{
		NTCR = NTC110C*10+(TargetTemp-110)*(NTC120C-NTC110C);
	}
	else if((TargetTemp>120)&&(TargetTemp<=130))
	{
		NTCR = NTC120C*10+(TargetTemp-120)*(NTC130C-NTC120C);
	}
	else if((TargetTemp>130)&&(TargetTemp<=140))
	{
		NTCR = NTC130C*10+(TargetTemp-130)*(NTC140C-NTC130C);
	}
	else if((TargetTemp>140)&&(TargetTemp<=150))
	{
		NTCR = NTC140C*10+(TargetTemp-140)*(NTC150C-NTC140C);
	}
	else if((TargetTemp>150)&&(TargetTemp<=160))
	{
		NTCR = NTC150C*10+(TargetTemp-150)*(NTC160C-NTC150C);
	}
	else if((TargetTemp>160)&&(TargetTemp<=170))
	{
		NTCR = NTC160C*10+(TargetTemp-160)*(NTC170C-NTC160C);
	}
	else if((TargetTemp>170)&&(TargetTemp<=190))
	{
		NTCR = NTC170C*10+(TargetTemp-170)*(NTC190C-NTC170C)/2;
	}
	else if((TargetTemp>210)&&(TargetTemp<=230))
	{
		NTCR = NTC210C*10+(TargetTemp-210)*(NTC230C-NTC210C)/2;
	}
	else if((TargetTemp>230)&&(TargetTemp<=250))
	{
		NTCR = NTC230C*10+(TargetTemp-230)*(NTC250C-NTC230C)/2;
	}
	else if((TargetTemp>250)&&(TargetTemp<=260))
	{
		NTCR = NTC250C*10+(TargetTemp-250)*(NTC260C-NTC250C);
	}
	else if((TargetTemp>260)&&(TargetTemp<=270))
	{
		NTCR = NTC260C*10+(TargetTemp-260)*(NTC270C-NTC260C);
	}
	else if((TargetTemp>270)&&(TargetTemp<=280))
	{
		NTCR = NTC270C*10+(TargetTemp-270)*(NTC280C-NTC270C);
	}
	else if((TargetTemp>280)&&(TargetTemp<=290))
	{
		NTCR = NTC280C*10+(TargetTemp-280)*(NTC290C-NTC280C);
	}
	else if((TargetTemp>290)&&(TargetTemp<=300))
	{
		NTCR = NTC290C*10+(TargetTemp-290)*(NTC300C-NTC290C);
	}
	else
	{
		NTCR = NTC300C*10;
	}	
	return NTCR;
}

s16 CalTemperOffset(u16 base,u16 val, u16 warm, u16 cool)
{
  return(base - 25*(val-warm)/(cool-warm));
}
s16 HeatTmp_real=0;
s32 NTCAD_tempreal()
{	
	volatile static s16 Temp_adc_get_temp;
	volatile static uint16_t Temp_adc_get;
	volatile static s16 Temp_adc2;
	volatile static uint8_t temp = 0;
	
	Temp_adc_get_temp = GET_HEART_NTC_AD_VAL_RESULT;
	if(Temp_adc_get_temp < 0)
		Temp_adc_get_temp = 0;
	
	Temp_adc_get = (Temp_adc_get_temp + (int32_t)Temp_adc_get) >> 1;
	if(Temp_adc_get > AD_TEMP_MAX_VAL)
		Temp_adc_get = AD_TEMP_MAX_VAL;
	


    if(Temp_adc_get >= CELSIUS_0_ADC_B)
    {
			if(Temp_adc_get < CELSIUS_P25_ADC_B)
       HeatTmp_real = CalTemperOffset(25,Temp_adc_get,CELSIUS_P25_ADC_B,CELSIUS_0_ADC_B);
     // <50℃
     else if(Temp_adc_get < CELSIUS_P50_ADC_B)
       HeatTmp_real = CalTemperOffset(50,Temp_adc_get,CELSIUS_P50_ADC_B,CELSIUS_P25_ADC_B);
     // <75℃
     else if(Temp_adc_get < CELSIUS_P75_ADC_B)
       HeatTmp_real = CalTemperOffset(75,Temp_adc_get,CELSIUS_P75_ADC_B,CELSIUS_P50_ADC_B);
     // <100℃
     else if(Temp_adc_get < CELSIUS_P100_ADC_B)
       HeatTmp_real = CalTemperOffset(100,Temp_adc_get,CELSIUS_P100_ADC_B,CELSIUS_P75_ADC_B);
     // <125℃
     else if(Temp_adc_get < CELSIUS_P125_ADC_B)
       HeatTmp_real = CalTemperOffset(125,Temp_adc_get,CELSIUS_P125_ADC_B,CELSIUS_P100_ADC_B);
     // >125℃
     else if(Temp_adc_get< CELSIUS_P150_ADC_B)
       HeatTmp_real = CalTemperOffset(150,Temp_adc_get,CELSIUS_P150_ADC_B,CELSIUS_P125_ADC_B);
     else if(Temp_adc_get < CELSIUS_P175_ADC_B)
       HeatTmp_real = CalTemperOffset(175,Temp_adc_get,CELSIUS_P175_ADC_B,CELSIUS_P150_ADC_B);
     else if(Temp_adc_get < CELSIUS_P200_ADC_B)
       HeatTmp_real = CalTemperOffset(200,Temp_adc_get,CELSIUS_P200_ADC_B,CELSIUS_P175_ADC_B);
		 else if(Temp_adc_get < CELSIUS_P225_ADC_B)
       HeatTmp_real = CalTemperOffset(225,Temp_adc_get,CELSIUS_P225_ADC_B,CELSIUS_P200_ADC_B);
		 else if(Temp_adc_get < CELSIUS_P250_ADC_B)
       HeatTmp_real = CalTemperOffset(250,Temp_adc_get,CELSIUS_P250_ADC_B,CELSIUS_P225_ADC_B);
		 else
       HeatTmp_real = 250;
    }
  // <25℃
    else
    {
     HeatTmp_real = 0;
    }
    return HeatTmp_real;

}
	
	
	







