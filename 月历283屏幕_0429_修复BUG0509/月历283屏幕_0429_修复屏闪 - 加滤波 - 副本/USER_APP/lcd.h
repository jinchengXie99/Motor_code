#ifndef __LCD_H
#define __LCD_H


#include "lks32mc03x_i2c.h"
#include "lks32mc03x_DMA.h"
#include "lks32mc03x_sys.h"

#include "USER_APP.h"

void IIC_Write_Reg(uint8_t address,uint8_t data); 


// ��ʼ�� ���� ɨ������ �������LCD���� buffer  �㿪������
void lcd_init(void);   
void lcd_show_all_clean(void);// ������������ 



// ��ʾ����
void lcd_show_all_number(int16_t Temp );


void lcd_show_ones(uint8_t* grx,uint8_t ones);


//  �ٶȵ�λ  ���� iTargetGear
void lcd_show_speed(uint16_t igear);

// ����1����   0�ر�
void lcd_show_constant_temperature(uint16_t on);


//  ���µ� ���� TempGear
void lcd_show_temp_gear(uint8_t temp_gear); 

void lcd_show_all_data(void);

#endif
