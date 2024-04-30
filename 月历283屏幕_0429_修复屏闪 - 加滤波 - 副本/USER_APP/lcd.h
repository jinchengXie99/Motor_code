#ifndef __LCD_H
#define __LCD_H


#include "lks32mc03x_i2c.h"
#include "lks32mc03x_DMA.h"
#include "lks32mc03x_sys.h"

#include "USER_APP.h"

void IIC_Write_Reg(uint8_t address,uint8_t data); 


// 初始化 亮度 扫描行数 清除所有LCD数据 buffer  点开常亮灯
void lcd_init(void);   
void lcd_show_all_clean(void);// 所有数据清零 



// 显示数字
void lcd_show_all_number(int16_t Temp );


void lcd_show_ones(uint8_t* grx,uint8_t ones);


//  速度档位  参数 iTargetGear
void lcd_show_speed(uint16_t igear);

// 恒温1开启   0关闭
void lcd_show_constant_temperature(uint16_t on);


//  风温档 参数 TempGear
void lcd_show_temp_gear(uint8_t temp_gear); 

void lcd_show_all_data(void);

#endif
