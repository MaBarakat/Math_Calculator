/*
 * LCD_4B_private.h
 *
 * Created: 30/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef LCD_4B_PRIVATE_H_
#define LCD_4B_PRIVATE_H_


static u16 power_fun(u16 number,u8 power);
static LCD4B_ErrorStatus_t private_writeHalfPort(u8 LCD_4BId,u8 value);


#endif /* LCD_4B_PRIVATE_H_ */