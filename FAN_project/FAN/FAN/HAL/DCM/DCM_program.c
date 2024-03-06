/*
 * DCM_program.c
 *
 * Created: 17/01/2024
 *  Author: Mahmoud Barakat
 */ 
/* SERVICE */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"
#include "../../SERVICE/UTILES_LIB/MATH_EQs.h"

/* MCAL */
/* DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/* Timer 0*///using in specify speed of DC motor
#include "../../MCAL/TMR1/TMR1_interface.h"

/* HAL */
/* DC Motor */
#include "DCM_config.h"
#include "DCM_interface.h"

DCM_ErrorStatus_t DCM_init  (u8 motorId)
{
	if (motorId < DCM_NUM)
	{u8 DCM_Counter;
		for (DCM_Counter=(motorId*3);DCM_Counter<((motorId+1)*3);DCM_Counter++)
		{
			DIO_setPinDirection(DCM_Ports[DCM_Counter],DCM_Pins[DCM_Counter],DIO_PIN_OUTPUT);
		}
	} 
	else
	{
		return DCMIdError;
	}
	return DCMNoError;
}
DCM_ErrorStatus_t DCM_on  (u8 motorId, u8 motorDirection)
{
	if (motorId < DCM_NUM)
	{
		switch (motorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_setPinValue(DCM_Ports[(motorId*3)],DCM_Pins[(motorId*3)],DIO_PIN_HIGH);
			DIO_setPinValue(DCM_Ports[((motorId*3)+1)],DCM_Pins[((motorId*3)+1)],DIO_PIN_HIGH);
			DIO_setPinValue(DCM_Ports[((motorId*3)+2)],DCM_Pins[((motorId*3)+2)],DIO_PIN_LOW);
			break;			
			case DCM_COUNTER_CLOCK_WISE:
			DIO_setPinValue(DCM_Ports[(motorId*3)],DCM_Pins[(motorId*3)],DIO_PIN_HIGH);
			DIO_setPinValue(DCM_Ports[((motorId*3)+1)],DCM_Pins[((motorId*3)+1)],DIO_PIN_LOW);
			DIO_setPinValue(DCM_Ports[((motorId*3)+2)],DCM_Pins[((motorId*3)+2)],DIO_PIN_HIGH);			
			break;
			default:
			return DCMDirError;
			break;			
		}
	} 
	else
	{
		return DCMIdError;
	}
	return DCMNoError;
}
DCM_ErrorStatus_t DCM_onControlSpeed(u8 motorId, u8 motorDirection, u8 motorSpeed)
{
	if (motorId < DCM_NUM)
	{
	   if (motorSpeed <= 100)
	   {
	   
		switch (motorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_setPinValue(DCM_Ports[((motorId*3)+1)],DCM_Pins[((motorId*3)+1)],DIO_PIN_HIGH);
			DIO_setPinValue(DCM_Ports[((motorId*3)+2)],DCM_Pins[((motorId*3)+2)],DIO_PIN_LOW);
			break;
			case DCM_COUNTER_CLOCK_WISE:
			DIO_setPinValue(DCM_Ports[((motorId*3)+1)],DCM_Pins[((motorId*3)+1)],DIO_PIN_LOW);
			DIO_setPinValue(DCM_Ports[((motorId*3)+2)],DCM_Pins[((motorId*3)+2)],DIO_PIN_HIGH);
			break;
			default:
			return DCMDirError;
			break;
		}
		//the Enable pin is OC0 put it in DCM_config.c
				//TMR0_init(FAST_PWM_MODE,CLEAR_OC0);
				//TMR0_setDutyCyclePercent(motorSpeed);
				//TMR0_start();
		u16 DCVel =MAP (motorSpeed,0,100,0,5000);
		TMR1_writeComparingValueB((u16)DCVel);
	   }
	   else
	   {
		   return DCMSpeedError;
	   }
	}
	else
	{
		return DCMIdError;
	}
	return DCMNoError;
}
DCM_ErrorStatus_t DCM_off  (u8 motorId)
{
	
	if (motorId < DCM_NUM)
	{
		DIO_setPinValue(DCM_Ports[((motorId*3)+1)],DCM_Pins[((motorId*3)+1)],DIO_PIN_LOW);
		DIO_setPinValue(DCM_Ports[((motorId*3)+2)],DCM_Pins[((motorId*3)+2)],DIO_PIN_LOW);
	} 
	else
	{
		return DCMIdError;
	}
	return DCMNoError;
}