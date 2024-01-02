/*
 * KEYPAD_config.c
 *
 * Created: 31/12/2023
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
/* KEYPAD */
#include "KEYPAD_config.h"

u8 KEYPAD_pattern [KEYPAD_ROWPINSNUM][KEYPAD_COLPINSNUM] = {{'1','2','3','/'},
															{'4','5','6','+'},
															{'7','8','9','-'},
															{'*','0','C','='}};


u8 ROW_Ports[KEYPAD_ROWPINSNUM*KEYPAD_NUM]={DIO_PORTC,DIO_PORTC,DIO_PORTC,DIO_PORTC};//the port of pins of the keypads for row
u8 COL_Ports[KEYPAD_COLPINSNUM*KEYPAD_NUM]={DIO_PORTB,DIO_PORTB,DIO_PORTB,DIO_PORTB};//the port of pins of the keypads for col
	
u8 ROW_Pins[KEYPAD_ROWPINSNUM*KEYPAD_NUM]={DIO_PIN0,DIO_PIN1,DIO_PIN3,DIO_PIN4};//the pins of the keypads for row
u8 COL_Pins[KEYPAD_COLPINSNUM*KEYPAD_NUM]={DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7};//the pins of the keypads for col