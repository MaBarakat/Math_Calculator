/*
 * DCM_config.c
 *
 * Created: 17/01/2024
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
/* DC Motor */
#include "DCM_config.h"
//DCM_Ports[3*DCM_NUM]={Enable Port,IN1 PORT,IN2 PORT};
//DCM_Pins[3*DCM_NUM]={Enable Port,IN1 PORT,IN2 PORT};
u8 DCM_Ports[3*DCM_NUM]={DIO_PORTD,DIO_PORTC,DIO_PORTC};
u8 DCM_Pins[3*DCM_NUM]={DIO_PIN4,DIO_PIN3,DIO_PIN4};