/*
 * LED_program.c
 *
 * Created: 26/12/2023
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
/* LED */
#include "LED_interface.h"

/*************** APIS ***************/
LED_ErrorStatus_t LED_init(u8 LedPort, u8 LedPin)
{
	return DIO_setPinDirection(LedPort,LedPin,DIO_PIN_OUTPUT);
}


LED_ErrorStatus_t LED_on(u8 LedPort, u8 LedPin)
{
	return DIO_setPinValue(LedPort,LedPin,DIO_PIN_HIGH);
}


LED_ErrorStatus_t LED_off(u8 LedPort, u8 LedPin)
{
	return DIO_setPinValue(LedPort,LedPin,DIO_PIN_LOW);
}


LED_ErrorStatus_t LED_toggle(u8 LedPort, u8 LedPin)
{
	return DIO_togglePinValue(LedPort,LedPin);
}