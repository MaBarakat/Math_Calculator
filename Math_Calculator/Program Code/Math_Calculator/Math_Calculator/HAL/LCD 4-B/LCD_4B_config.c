/*
 * LCD_4B_config.c
 *
 * Created: 30/12/2023
 *  Author: Mahmoud Barakat
 */ 
/* SERVICE */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"

/* MCAL */
/* DIO */
#include "../../MCAL/DIO/DIO_interface.h"

/* HAL */
/* LCD */
#include "LCD_4B_config.h"

//Control Ports and Pins
u8 Rs_4B_port[LCD_4B_num]={DIO_PORTB};
u8 Rs_4B_pin[LCD_4B_num]={DIO_PIN1};

u8 Rw_4B_port[LCD_4B_num]={DIO_PORTB};
u8 Rw_4B_pin[LCD_4B_num]={DIO_PIN2};

u8 E_4B_port[LCD_4B_num]={DIO_PORTB};
u8 E_4B_pin[LCD_4B_num]={DIO_PIN3};

//Data Ports and Pins
u8 LCD_4B_port[LCD_4B_num*4]=
{
	LCD_4B_PORTA,LCD_4B_PORTA,LCD_4B_PORTA,LCD_4B_PORTA
};

u8 LCD_4B_PINS[LCD_4B_num*4]=
{
	LCD_4B_PIN4,LCD_4B_PIN5,LCD_4B_PIN6,LCD_4B_PIN7			//LCD_4B_ONE
};