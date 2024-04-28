/*******************************************************************************
 * °æÈ¨ËùÓÐ (C)2019, LINKO SEMICONDUCTOR Co.ltd
 *
 * ÎÄ¼þÃû³Æ£º parameter.h
 * ÎÄ¼þ±êÊ¶£º
 * ÄÚÈÝÕªÒª£º parameter config
 * ÆäËüËµÃ÷£º ÎÞ
 * µ±Ç°°æ±¾£º V1.0
 * ×÷    Õß£º Andrew kong, Howlet Li
 * Íê³ÉÈÕÆÚ£º 2020Äê8ÔÂ18ÈÕ
 *
 *******************************************************************************/
 
/*------------------------------prevent recursive inclusion -------------------*/ 
#ifndef __PARAMETER_H
#define __PARAMETER_H

#include "basic.h"
#include "MC_Type.h"

/* -----------------------------Hardware Parameter---------------------------- */
#define ADC_SUPPLY_VOLTAGE             (3.6)              /* µ¥Î»: V  ADC»ù×¼µçÑ¹£¬3.6»òÕß2.4,´ó²¿·ÖÓ¦ÓÃÑ¡Ôñ3.6 */
#define AMPLIFICATION_GAIN             (18.18)            /* ÔË·Å·Å´ó±¶Êý */   //18.18
#define RSHUNT                         (0.100)             /* µ¥Î»: ¦¸  ²ÉÑùµç×è×èÖµ */
#define VOLTAGE_SHUNT_RATIO            (6.8/(470.0*2+6.8)) /* Ä¸ÏßµçÑ¹·ÖÑ¹±È */
#define BEMF_SHUNT_RATIO               (1.0/(100.0*2 + 1.0)) /* ·´µçÊÆµçÑ¹·ÖÑ¹±È */

#define CURRENT_SAMPLE_TYPE            CURRENT_SAMPLE_2SHUNT /* µçÁ÷²ÉÑù·½Ê½Ñ¡Ôñ */

#define ROTOR_SENSOR_TYPE              ROTOR_SENSORLESS  /* µç»úÎ»ÖÃ´«¸ÐÆ÷ÀàÐÍÑ¡Ôñ */

/* ------------------------------Rated Parameter------------------------------ */

#define U_RATED_VOLTAGE                (310.0)               /* µ¥Î»:V, µç»ú¶î¶¨¹¤×÷µçÑ¹£¬ÉèÖÃÎªÕý³£¹¤×÷µçÑ¹ */
#define U_RATED_CURRENT                (0.8)                /* µ¥Î»:A, µç»ú¶î¶¨¹¤×÷µçÁ÷£¬ÏàµçÁ÷×î´óÖµ */
#define U_MAX_FREQ                     (3000.0)            /* µ¥Î»:Hz,  µç»ú×î¸ßÔËÐÐ×ªËÙ */

/* ------------------------------Motor Parameter------------------------------ */
#define U_MOTOR_PP                     (1.0)              //µç»ú¼«¶ÔÊý   áâ·Òµç»ú 1¶Ô¼« 220V
#define U_MOTOR_RS                     (24.5)           //µ¥Î»: ¦¸ µç»úÏàµç×è
#define U_MOTOR_LD                     (1900.3)           //µ¥Î»: uH µç»údÖáµç¸Ð
#define U_MOTOR_LQ                     (2300.4)           //µ¥Î»: uH µç»úqÖáµç¸Ð


//#define U_MOTOR_PP                     (1.0)              //µç»ú¼«¶ÔÊý   ²ð»úµç»ú 1¶Ô¼« 220V
#define U_MOTOR_RS1                     (24.321)           //µ¥Î»: ¦¸ µç»úÏàµç×è
#define U_MOTOR_LD1                     (2008.6)           //µ¥Î»: uH µç»údÖáµç¸Ð
#define U_MOTOR_LQ1                     (2557.8)           //µ¥Î»: uH µç»úqÖáµç¸Ð

//#define U_MOTOR_PP                     (1.0)              //µç»ú¼«¶ÔÊý   ½ñºèÐÇ»Ôµç»ú 1¶Ô¼« 220V
//#define U_MOTOR_RS                     (21.887)           //µ¥Î»: ¦¸ µç»úÏàµç×è
//#define U_MOTOR_LD                     (1951.985)           //µ¥Î»: uH µç»údÖáµç¸Ð
//#define U_MOTOR_LQ                     (2569.775)           //µ¥Î»: uH µç»úqÖáµç¸Ð

//#define U_MOTOR_PP                     (1.0)              //µç»ú¼«¶ÔÊý   º£ºÍµç»ú 1¶Ô¼« 110V
//#define U_MOTOR_RS                     (6.055)           //µ¥Î»: ¦¸ µç»úÏàµç×è
//#define U_MOTOR_LD                     (453.29)           //µ¥Î»: uH µç»údÖáµç¸Ð
//#define U_MOTOR_LQ                     (693.62)           //µ¥Î»: uH µç»úqÖáµç¸Ð

/* µç»ú´ÅÁ´³£Êý ¼ÆËã¹«Ê½£ºVpp/2/sqrt(3)/(2*PI)/f£¬ÆäÖÐVppÎªµçÑ¹·å·åÖµ£¬fÎªµçÆµÂÊ 
   ´Ë²ÎÊý½öÓ°ÏìË³Äæ·çÆô¶¯µÄËÙ¶È¼ì²â£¬½Ç¶È¹ÀËã²»Ê¹ÓÃÐ©²ÎÊý */
#define U_MOTOR_FLUX_CONST             (0.00142328)

#define PWM_FREQ_HI                    ((u16)22000) 

/* ----------------------IPD ×ª×Ó³õÊ¼Î»ÖÃ¼ì²â Âö³å×¢ÈëÊ±¼äÉèÖÃ---------------- */
#define SEEK_POSITION_STATUS           (FALSE)             /* ³õÊ¼Î»ÖÃ¼ì²â×´Ì¬ TRUEÎªÊ¹ÄÜ, FALSEÎª²»Ê¹ÄÜ */
#define U_START_ANGLE_COMP             (0)                /* µ¥Î»:¶È ³õÊ¼Î»ÖÃ¼ì²â²¹³¥½Ç¶È */

#define IPD_PLUS_TIME_SETTING          (1)              /* Âö³å×¢ÈëÊ±¼ä¿í¶ÈÉèÖÃ µ¥Î»us */
#define IPD_WAIT_TIME_SETTING          (50)              /* Âö³å¿ÕÏÐµÈ´ýÊ±¼ä¿í¶ÈÉèÖÃ µ¥Î»us */

#define IPD_PLUS_TIME_WIDTH            (u32)(IPD_PLUS_TIME_SETTING*(MCU_MCLK/1000000))   /* Âö³å×¢ÈëÊ±¼ä¿í¶ÈÉèÖÃ µ¥Î»clk */
#define IPD_PLUS_WAIT_TIME             (u32)(IPD_WAIT_TIME_SETTING*(MCU_MCLK/1000000))   /* Âö³å¿ÕÏÐµÈ´ýÊ±¼ä¿í¶ÈÉèÖÃ µ¥Î»clk */

/* -------------------------------HALL×ÔÑ§Ï°ÉèÖÃ------------------------------- */
#define HALL_LEARN_CURRENT_SETTINT     (1.0)              /* HALL×ÔÑ§Ï°µçÁ÷Éè¶¨,µ¥Î»: A */

/* ----------------------------direction check Parameter----------------------- */
#define CW                             (0)                /* µç»ú×ªÏò£ºË³Ê±Õë */ 
#define CCW                            (1)                /* µç»ú×ªÏò£ºÄæÊ±Õë*/

/* ------------------------------ADCÐ£×¼Ïà¹Ø²ÎÊýÉèÖÃ---------------------------- */
#define CALIB_SAMPLES                  (512)              /* ADCÆ«ÖÃÐ£×¼´ÎÊý£¬²»¿ÉÐÞ¸Ä */
#define OFFSET_ERROR                   (3500)             /* ADCÆ«ÖÃÎó²îãÐÖµ£¬²»ÓÃÐÞ¸Ä */

/* ----------------------------Ô¤Çý×Ô¾ÙµçÈÝÔ¤³äµç²ÎÊý--------------------------- */
#define CHARGE_TIME                    (100)              /* Ã¿ÏàÔ¤³äµçÊ±¼ä£¬¸ù¾ÝÊµ¼ÊÓ²¼þ²ÎÊýÐÞ¸Ä */

/* -------------------------------- Ë³Äæ·ç¼ì²â²ÎÊý------------------------------ */
#define SPEED_TRACK_DELAYTIME          (100)              /* µ¥Î»: ms Ë³Äæ·ç¼ì²âÊ±¼ä  */
#define SPEED_TRACK_ON_FREQ_THH        (10)               /* µ¥Î»: Hz Ë³·çÇÐ±Õ»·ÆµÂÊ */
#define EBRK_ON_FREQ_THH               (20)               /* µ¥Î»: Hz Äæ·çÉ²³µÆµÂÊ */

#define MOTOR_STOP_CUR_THD             (120)              /* µç»úÍ£Ö¹¼ì²âµçÁ÷ãÐÖµ */
#define MOTOR_STOP_CUR_DIF_THD         (12)               /* µç»úÍ£Ö¹¼ì²âµçÁ÷²îãÐÖµ */

#define STOP_TIME                      (250)               /* µ¥Î»£ºms µç»úÍ£Ö¹¼ì²âÂË²¨Ê±¼ä£¬¸ù¾ÝÊµ¼Ê¸ºÔØÐÞ¸Ä  É²³µºó¸ÄÎªidle×´Ì¬Ê±¼ä*/
#define STOP_DELAY_TIME                (200)              /* µ¥Î»: ms µç»úÍ£Ö¹ºóÑÓ³ÙÊ±¼ä£¬¸ù¾ÝÊµ¼Ê¸ºÔØÐÞ¸Ä¡£ÐÞ¸ÄÒÀ¾Ý£ºµç»úÔÚÅÐ¶¨ÎªÍ£Ö¹ºó»¹ÔÚ×ª¶¯¾Í¼Ó´óÑÓ³ÙÊ±¼ä */

#define CLOSE_VOLT                     (1000)              /**/
/*------------------------------------Ô¤¶¨Î»²ÎÊý---------------------------------*/
#define ALIGN_ANGLE                    (0)                /* µ¥Î»:¶È Ô¤¶¨Î»½Ç¶È */
#define U_START_CUR_SET_F              (0.0)              /* µ¥Î»: A µÚÒ»¶Î¶¨Î»µçÁ÷ */
#define U_START_CUR_SET_S              (0.55)              /* µ¥Î»: A µÚ¶þ¶Î¶¨Î»µçÁ÷ */
#define DC_HOLDTIME_TIME_LENTH         (10)               /* µ¥Î»: ms µÚÒ»¶Î¶¨Î»Ê±¼ä */
#define DC_HOLDTIME_TIME_LENTH_STAGE1  (10)               /* µ¥Î»: ms µÚ¶þ¶Î¶¨Î»Ê±¼ä */
#define DC_ALIGN_TOTAL_LENTH            \
       (DC_HOLDTIME_TIME_LENTH + DC_HOLDTIME_TIME_LENTH_STAGE1)/* ¶¨Î»×ÜÊ±³¤ */

#define ALIGN_CURRENT_ACC              (0.01)              /* µ¥Î»: (1/8)A/ms  ¶¨Î»µçÁ÷¼ÓËÙµ÷ÕûÖµ  ³õÊ¼Î»ÖÃ¼ì²âÊ¹ÄÜºó¸øµ½×î´óÖµ£¬²»ÄÜ³¬¹ý30£¬·ñÔòÊý¾Ý»áÒç³ö¡£ */
#define ALIGN_CURRENT_DEC              (0.01)              /* µ¥Î»: (1/8)A/ms  ¶¨Î»µçÁ÷¼õËÙµ÷ÕûÖµ  ³õÊ¼Î»ÖÃ¼ì²âÊ¹ÄÜºó¸øµ½×î´óÖµ£¬²»ÄÜ³¬¹ý30£¬·ñÔòÊý¾Ý»áÒç³ö¡£ */

/*---------------------------------¿ª»·²ÎÊý------------------------------------*/
#define OPEN_ANGLE_TAG_FREQ            (60.0)             /* µ¥Î»£ºHz ¿ª»·ÍÏ¶¯×îÖÕÆµÂÊ */   
#define FREQ_ACC                       (0.0)              /* µ¥Î»£º(1/128)Hz/ms ¿ª»·ÍÏ¶¯ÆµÂÊ¼ÓËÙµ÷ÕûÖµ */
#define FREQ_DEC                       (20.0)              /* µ¥Î»£º(1/128)Hz/ms ¿ª»·ÍÏ¶¯ÆµÂÊ¼õËÙµ÷ÕûÖµ */

#define OPEN_RUN_STATUS                (FALSE)            /* ¿ª»·×´Ì¬ TRUE = ¿ª»·ÔËÐÐ, FALSE = ±Õ»·ÔËÐÐ */
  
#define MATCH_TIME                     (5)                /* ¹ÀËãºÍ¸ø¶¨µçÁ÷Æ¥Åä´ÎÊý */ 

/*---------------------- -----¿ª»·±Õ»·ÇÐ»»¹ý¶É²ÎÊý------------------------------*/
#define OPEN2CLOSE_RUN_COV_TIME        (2)               /* ¿ª»·±Õ»·ÇÐ»»¹ý¶ÉÊ±¼ä£ºµ¥Î»£ºmS */
#define OPEN2CLOSE_RUN_CURRENT_RAMP    (0.1)             /* ¿ª»·±Õ»·ÇÐ»»¹ý¶ÉÄÚ£¬D,QÖáµçÁ÷±ä»¯Ð±ÂÊ¡£µ¥Î»£ºA/ms */

/*-----------------------------------»·Â·Ñ¡Ôñ----------------------------------*/
#define CURRENT_LOOP                   (0)                /* µçÁ÷»· */
#define SPEED_LOOP                     (1)                /* ËÙ¶È»· */
#define POWER_LOOP                     (2)                /* ¹¦ÂÊ»· */
#define CLOSE_LOOP                     (SPEED_LOOP)      /* »·Â·Ñ¡Ôñ */

/* ------------------------------Æô¶¯²ÎÊý----------------------------- */
#define IQ_START                       (0.1)               /* µ¥Î» */

#define PLL_KP_GAIN                    (0)                 /* PLL_Kp ¹ÀËãÆ÷Kp  start*/ //800
#define PLL_KI_GAIN                    (0)                  /* PLL_Ki ¹ÀËãÆ÷Ki */  //300

#define PLL_KP_GAIN_L                  (1600)                  /* PLL_Kp ¹ÀËãÆ÷Kp */ //800
#define PLL_KI_GAIN_L                  (100)                  /* PLL_Ki ¹ÀËãÆ÷Ki */ //50


#define PLL_KP_GAIN_L1                  (1200)                  /* PLL_Kp ¹ÀËãÆ÷Kp */ //800
#define PLL_KI_GAIN_L1                  (100)                  /* PLL_Ki ¹ÀËãÆ÷Ki */ //50
//#define PLL_KP_GAIN_H                  (1000)                 /* PLL_Kp ¹ÀËãÆ÷Kp */ //400
//#define PLL_KI_GAIN_H                  (200)                  /* PLL_Ki ¹ÀËãÆ÷Ki */ //10

#define PI_MATCH_FREQ                  (30.0)              /* µ¥Î»£ºHz PI²ÎÊýµ÷ÕûÆµÂÊ */
#define CLOSE_FREQ                     (200.0)              /* µ¥Î»£ºHz ÇÐÈë¹¦ÂÊ»·µÄÆµÂÊ */

#define OBS_MIN_OUT_SPEED              (150)                  /* ¹Û²âÆ÷×îÐ¡Êä³öµçÆµÂÊ£¬µ¥Î»£º0.1Hz*/  //50
#define OBS_MAX_OUT_SPEED              0//(3000)                /* ¹Û²âÆ÷×îÐ¡Êä³öµçÆµÂÊ£¬µ¥Î»£º0.1Hz*/  //2000

#define START_DIVISOR                  (5.0)               /*Æô¶¯²ÎÊý--ÒÆÎ»*/  //3
#define START_OBSFACTOR                (30.0)              /*Æô¶¯²ÎÊý--ÏµÊý*/ //65

#define OBS_COEF                        FRAC16(0.05)        /* ¹Û²âÆ÷ÂË²¨ÏµÊý 0~1  */  //0.25

/*----------------------------------µçÁ÷»·²ÎÊý---------------------------------*/
#define IQ_SET                         (0.40)              /* µ¥Î»£ºA IqRef£¬Iq¸ø¶¨Öµ */
 
#define VQMAX                          (6000)             /* QÖá×î´óÊä³öÏÞÖÆ£¬Q15¸ñÊ½£¬È¡Öµ·¶Î§0~6000 */
#define VQMIN                          (-VQMAX)            /* QÖá×îÐ¡Êä³öÏÞÖÆ£¬Q15¸ñÊ½£¬È¡Öµ·¶Î§0~-6000 */

#define VDMAX                          (VQMAX)             /* DÖá×î´óÊä³öÏÞÖÆ£¬Q15¸ñÊ½£¬È¡Öµ·¶Î§0~6000 */
#define VDMIN                          (-VQMAX)            /* DÖá×îÐ¡Êä³öÏÞÖÆ£¬Q15¸ñÊ½£¬È¡Öµ·¶Î§0~6000 */

#define P_CURRENT_KP                   4500               /* µçÁ÷»·Kp£¬Êµ¼ÊÔËÓÃµÄKp»á¸ù¾ÝÕâ¸öÖµºÍµç»ú²ÎÊý¼ÆËã³ö×îÖÕµÄKp */
#define P_CURRENT_KI                   700                /* µçÁ÷»·Ki£¬Êµ¼ÊÔËÓÃµÄKp»á¸ù¾ÝÕâ¸öÖµºÍµç»ú²ÎÊý¼ÆËã³ö×îÖÕµÄKi */

#define P_CURRENT_KP_H                 2000              /* ¸ßËÙµçÁ÷»·Kp£¬ 1500= 1.5±¶*/  //1200
#define P_CURRENT_KI_H                 10000               /* ¸ßËÙ µçÁ÷»·Ki£¬1500= 1.5±¶ */ //1200

#define AUTO_FW_LIM                    ((s16)0)        /* ×Ô¶¯Èõ´ÅDÖáµçÁ÷ÏÞÖÆ£¬Q12¸ñÊ½£¬×î´óÖµ 4096 */

#define TORQUE_MODE_CURRENT_CHANGE_ACC (0.2)              /* µ¥Î»£ºA/ms µçÁ÷¼ÓËÙµ÷ÕûÖµ */
#define TORQUE_MODE_CURRENT_CHANGE_DEC (0.2)              /* µ¥Î»£ºA/ms µçÁ÷¼õËÙµ÷ÕûÖµ */

/*----------------------------------ËÙ¶È»·²ÎÊý-------------------------------*/
#define POWER_LIMIT_STATUS             (FALSE)            /* ÏÞ¹¦ÂÊ×´Ì¬£¬TRUE = Ê¹ÄÜ£¬FALSE = ²»Ê¹ÄÜ */
#define POWER_LIMIT_VALUE              (40.0)             /* µ¥Î»£ºW   ÏÞÖÆ¹¦ÂÊµÄ´óÐ¡ */
#define POWER_LIMIT_TIME               (5)                /* µ¥Î»£ºËÙ¶È»·ÖÜÆÚ£¬  ÏÞ¹¦ÂÊ¼ÆËãÖÜÆÚ */
#define POWER_LIMIT_SPEED              (10)               /* µ¥Î»£ºHz  ÏÞ¹¦ÂÊ×ªËÙ¸ø¶¨£¬¸ù¾ÝÊµ¼ÊÓ¦ÓÃÀ´ÉèÖÃ£¬ */



#define SPEED_SET                      (1834)               /* µ¥Î»£ºHz  ËÙ¶È¸ø¶¨Öµ  1450 1834 */
#define SPEED_LOOP_CNTR                (0)                /* µ¥Î»£ºms  ËÙ¶È»·Â·¼ÆËãÖÜÆÚ */

#define STATE04_WAITE_TIME             (2)              /* Unit: ms ËÙ¶È±äÁ¿³õÊ¼»¯Ê±¼ä */

#define P_ASR_KP                      4000 //4000//2000//(3000)             /* ËÙ¶È»·Kp */
#define P_ASR_KI                      6000//6000//3000//(5000)              /* ËÙ¶È»·Ki */

#define IQMAX                          (0.6)                /* µ¥Î»:A, ËÙ¶È»·Êä³ö×î´óÖµ */
#define IQMIN                          (-0.4)               /* µ¥Î»:A, ËÙ¶È»·Êä³ö×îÐ¡Öµ */

#define SPEED_RUN_ACC                  (3.0)            /* µ¥Î» (1/128)Hz ËÙ¶È¼ÓËÙµ÷ÕûÖµ */
#define SPEED_RUN_DEC                  (3.0)              /* µ¥Î» (1/128)Hz ËÙ¶È¼õËÙµ÷ÕûÖµ */

/* É²³µ²ÎÊý */
#define BRAKE_IQ_EN                    (1)             /* IQÉ²³µ TRUEÎªÊ¹ÄÜ, FALSEÎª²»Ê¹ÄÜ */ 
#define BRAKE_CURRENT                  (-0.55)             /* µ¥Î»£ºA É²³µµçÁ÷ */
#define BRAKE_SPEED                    (350)              /* µ¥Î»£ºHz É²³µ×ªËÙ */
#define BRAKE_P_CURRENT_KP              100                /* É²³µµçÁ÷»·Kp */
#define BRAKE_P_CURRENT_KI              44                /* É²³µµçÁ÷»·Ki */

/* ÇÐ5¶ÎÊ½²ÎÊý */
#define SVPWM_Type_EN                    (0)             /* IQÉ²³µ TRUEÎªÊ¹ÄÜ, FALSEÎª²»Ê¹ÄÜ */ 

/*------------------------------------¹¦ÂÊ»·²ÎÊý-------------------------------*/
#define SPPED_LIMIT_STATUS             (FALSE)            /*  ÏÞ×ªËÙ×´Ì¬£¬TRUE = Ê¹ÄÜ£¬FALSE = ²»Ê¹ÄÜ */
#define SPEED_LIMIT_VALUE              (200.0)            /* µ¥Î»£ºHz  ÏÞÖÆ×ªËÙµÄ´óÐ¡ */
#define SPEED_LIMIT_TIME               (5)                /* µ¥Î»£ºms  ¹¦ÂÊ»·ÖÜÆÚ£¬ ÏÞ×ªËÙ¼ÆËãÖÜÆÚ */
#define SPEED_LIMIT_POWER_VALUE        (10)               /* µ¥Î»£ºW   ÏÞ×ªËÙ¹¦ÂÊ¸ø¶¨ */

#define POWER_SET                      (30.0)               /* µ¥Î»£ºW  ¹¦ÂÊ¸ø¶¨Öµ */
#define POWER_LOOP_CNTR                (1)                /* µ¥Î»£ºms  ¹¦ÂÊ»·Â·¼ÆËãÖÜÆÚ */
                                                                  
#define POWER_KP                       (6000)             /* ¹¦ÂÊ»·Kp */
#define POWER_KI                       (600)              /* ¹¦ÂÊ»·Ki */

#define POWER_IQMAX                    (3.8)              /* µ¥Î»:A, ¹¦ÂÊ»·Êä³ö×î´óÖµ */
#define POWER_IQMIN                    (-3.8)             /* µ¥Î»:A, ¹¦ÂÊ»·Êä³ö×îÐ¡Öµ */
                                                                   
#define POWER_RUN_ACC                  (2.0)              /* µ¥Î» w ¹¦ÂÊ¼ÓËÙµ÷ÕûÖµ ×¢ÒâPOWER_RUN_ACCºÍPOWER_RUN_DEC²»ÄÜÌ«Ð¡£¬½áºÏÄâºÏ²ÎÊýÉèÖÃ£¬Êµ¼Ê³ÌÐòÖÐµÄ¼Ó¼õËÙÖµ²»ÄÜÄÜÐ¡ÓÚ0. */
#define POWER_RUN_DEC                  (2.0)              /* µ¥Î» w ¹¦ÂÊ¼õËÙµ÷ÕûÖµ */

/*------------------------------------FaultDetection---------------------------*/
/* ¹ýÁ÷¼ì²â²ÎÊý */
#define I_PH_OVERCURRENT_FAULT         (3.0)              /* µ¥Î»£ºA Èí¼þ¹ýÁ÷¼ì²âÉè¶¨Öµ */

/* ¹ýÇ·Ñ¹¼ì²â²ÎÊý */
#define U_DCB_OVERVOLTAGE_FAULT        (350.0)               /* µ¥Î»£ºV ¹ýÑ¹¼ì²âÉè¶¨Öµ *///350-270  
#define U_DCB_OVERVOLTAGE_RECOVER      (365.0)               /* µ¥Î»£ºV ¹ýÑ¹»Ö¸´Éè¶¨Öµ *///360-254  365-
#define U_DCB_UNDERVOLTAGE_FAULT       (240.0)               /* µ¥Î»£ºV Ç·Ñ¹¼ì²âÉè¶¨Öµ */// //247-179  240-
#define U_DCB_UNDERVOLTAGE_RECOVER     (255.0)               /* µ¥Î»£ºV Ç·Ñ¹»Ö¸´Éè¶¨Öµ *///  270-193  260-187 255-

/* ÀëË®¿Õ×ª²ÎÊý */
#define I_PH_EMPTY_FAULT               (0.15)              /* µ¥Î»£ºA ¿Õ×ª¼ì²âµçÁ÷Éè¶¨Öµ */
#define SPEED_EMPTY_FAULT              (180.0)             /* µ¥Î»£ºHz ¿Õ×ª¼ì²â×ªËÙÉè¶¨Öµ  */

/* ÎÂ¶È¼ì²â²ÎÊý */
#define TEMP_FAULT                      (285)              /* ³¬ÎÂ¼ì²âÉè¶¨Öµ */
#define TEMP_OVER1                      (130)              /* ¹ýÎÂ¼ì²âÉè¶¨Öµ */
#define TEMP_OVER1min                     (150)              /* ¹ýÎÂ¼ì²âÉè¶¨Öµ */
//#define TEMP_OVER2                      (195) 
#define TEMP_RECOVER1                   (205)              /* ¹ýÎÂ»Ö¸´Éè¶¨Öµ */
//#define TEMP_RECOVER2                   (180)
#define TEMP_BREAK                       (200)             /* NTC¿ªÂ·Éè¶¨Öµ */
#define TEMP_short                       (30000)             /* NTC¿?Â·Éè¶¨Öµ */  
#define TEMP_short1                       (29995)             /* NTC¿?Â·Éè¶¨Öµ */  


/* ¶Â×ª¼ì²â²ÎÊý */
#define SPEED_STALL_MAX_FAULT          (2200.0)           /* µ¥Î»£ºHz ¶Â×ª¼ì²â×ªËÙ×î´óÖµ */
#define SPEED_STALL_MIN_FAULT          (50.0)             /* µ¥Î»£ºHz ¶Â×ª¼ì²â×ªËÙ×îÐ¡Öµ */

#define I_PH_STALL_FAULT               (1.4)              /* µ¥Î»£ºA ¶Â×ª¼ì²âµçÁ÷Éè¶¨Öµ */

#define SPEED_STALL_FAULT              (30.0)             /* µ¥Î»£ºHz ¶Â×ª¼ì²â×ªËÙÉè¶¨Öµ */
#define IQ_STALL_FAULT                 (0.1)              /* µ¥Î»£ºA ¶Â×ª¼ì²âµçÁ÷Éè¶¨Öµ */

#define STALL_CHCEK_TIME               (150)               /* µ¥Î»£º5ms ¶Â×ª¼ì²âÊ±¼ä*/   //100


#define POWER_CHECK                    (41)               /* µ¥Î»£º¹¦ÂÊÐ£ÕýÖµ */
#define POWER_CHECK1                   (34)               /* µ¥Î»£º¹¦ÂÊÐ£ÕýÖµ */
#define  STALL_POWER1                  (78)               /* µ¥Î»£ºw ¶Â¿×¹¦ÂÊ1*/   //100
#define  STALL_POWER2                  (117)               /* µ¥Î»£ºW ¶Â¿×¹¦ÂÊ2*/   //100
#define  RESTART_CNT                    (2)                  // ÔÊÐíÖØÆô´ÎÊý

/* ¶þ´ÎÆô¶¯¼ì²â²ÎÊý */
#define START_TIME_FAULT               (100)              /* µ¥Î»£º5ms ¿ª»·Ö®ºó1sÄÚ»¹²»½øÈë±Õ»·¾ÍÖØÆô£¬1sÕâ¸öÊ±¼ä¸ù¾ÝÊµ¼ÊÓ¦ÓÃµ÷Õû */
#define STARTUP_FAILED_TIME_5MS        (100)
/* È±Ïà¼ì²â²ÎÊý */
#define I_PHASE_LOSS_FAULT             (3000)             /* Êý×ÖÁ¿£¬¸ù¾ÝÊµ¼Ê²âÊÔÖÐstruCurrentAmplitude.nPhA/struCurrentAmplitude.nPhB/struCurrentAmplitude.nPhC */
                                                          /* µÄ¼ÆËãÖµÀ´Éè¶¨£¬ÔÚÈ±ÏàºÍÕý³£ÔËÐÐµÄÖÐ¼äÈ¡Öµ¡£ */
#define PHASE_CHCEK_TIME               (40)               /* µ¥Î»£º5ms È±Ïà¼ì²âÊ±¼ä*/

/* ¹ÊÕÏ»Ö¸´Ê±¼ä */
#define VOLT_FAULT_RECOVER_TIME        (300)             /* µ¥Î»£ºms  ¹ýÇ·Ñ¹»Ö¸´Ê±¼ä */
#define CURRENT_FAULT_RECOVER_TIME     (300)             /* µ¥Î»£ºms  ¹ýÁ÷»Ö¸´Ê±¼ä */
#define STALL_FAULT_RECOVER_TIME       (300)             /* µ¥Î»£ºms  ¶Â×ª»Ö¸´Ê±¼ä */
#define PHASELOSS_FAULT_RECOVER_TIME   (300)             /* µ¥Î»£ºms  È±Ïà»Ö¸´Ê±¼ä */
#define TEMP_FAULT_RECOVER_TIME        (2000)             /* µ¥Î»£ºms  ¹ýÎÂ»Ö¸´Ê±¼ä */
#define START_FAULT_RECOVER_TIME       (300)             /* µ¥Î»£ºms  ¶þ´ÎÆô¶¯»Ö¸´Ê±¼ä */
#define EMPTY_FAULT_RECOVER_TIME       (300)             /* µ¥Î»£ºms  ÀëË®¿Õ×ª»Ö¸´Ê±¼ä */



#endif  /* __PARAMETER_H */

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* -----------------------------------END OF FILE------------------------------- */

