/*
 * SW_program.c
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
#include "SW_interface.h"

/*************** APIS ***************/
SW_ErrorStatus_t SW_init(u8 swport,u8 swpin)
{
	return DIO_setPinDirection(swport,swpin,DIO_PORT_INPUT);
}

SW_ErrorStatus_t SW_getSwitchPinValue(u8 swport,u8 swpin,u8* swpinvalue)
{
	return DIO_getPinValue(swport,swpin,swpinvalue);
}

SW_ErrorStatus_t SW_activeSwitchPinInPullUpResistance(u8 swport, u8 swpin)
{
	return DIO_activePinInPullUpResistance(swport,swpin);
}
