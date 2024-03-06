/*
 * TMR1_HAL_program.c
 *
 * Created: 02/02/2024
 *  Author: Mahmoud Barakat
 */ 

/* SERVICE LAYER */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"

/* MCAL */
/* DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/* TMR1 */
#include "../../MCAL/TMR1/TMR1_interface.h"

/* HAL LAYER */
/* TMR1 */
#include "TMR1_HAL_interface.h"

/*************** APIS  ***************/
TMR1_HAL_ErrorStatus_t TMR1_HAL_init(u8 TMR1Mode,u8 OC1Mode)// initialization
{
//	if (OC1Mode != TMR1_HAL_NORMALPORT)
//	{
//		DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
//		DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
//	}
	return TMR1_init(TMR1Mode,OC1Mode);
}

void TMR1_HAL_start(void)//start timer 0
{
	TMR1_start();
}
void TMR1_HAL_stop(void)//Stop timer 0
{
	TMR1_stop();
}
void TMR1_HAL_reset(void)//Reset timer 0
{
	TMR1_reset();	
}

void TMR1_HAL_writePreloadValue(u16 preloadValue)//to write the pre_load(new zero)
{
	TMR1_writePreloadValue(preloadValue);
}
void TMR1_HAL_writeComparingValueA(u16 compValue)//comparing value to write the OCR1A
{
	TMR1_writeComparingValueA(compValue);
}
void TMR1_HAL_writeComparingValueB(u16 compValue)//comparing value to write the OCR1B
{
	TMR1_writeComparingValueB(compValue);
}
void TMR1_HAL_writeCapturingValue(u16 CaptValue)//comparing value to write the ICR1
{
	TMR1_writeCapturingValue(CaptValue);	
}

//INT enable &disable
void TMR1_HAL_OVRIntEnable(void)//overflow INT enable
{
	TMR1_OVRIntEnable();
}
void TMR1_HAL_OVRIntDisable(void)//overflow INT disable
{
	TMR1_OVRIntDisable();
}
void TMR1_HAL_CAPtIntEnable(void)//Input Capture INT enable
{
	TMR1_CAPtIntEnable();
}
void TMR1_HAL_CAPtIntDisable(void)//Input Capture INT disable
{
	TMR1_CAPtIntDisable();
}
void TMR1_HAL_COMPAIntEnable(void)//comparing A INT enable
{
	TMR1_COMPAIntEnable();
}
void TMR1_HAL_COMPAIntDisable(void)//comparing A INT disable
{
	TMR1_COMPAIntDisable();
}
void TMR1_HAL_COMPBIntEnable(void)//comparing B INT enable
{
	TMR1_COMPBIntEnable();
}
void TMR1_HAL_COMPBIntDisable(void)//comparing B INT disable
{
	TMR1_COMPBIntDisable();		
}

//ISR FUNs
TMR1_HAL_ErrorStatus_t TMR1_HAL_OVFISRPtrFun (void  (*TMR1_callbackOVFISRPtrFun) (void))//for overflow In normal and CTC modes
{
	if (TMR1_callbackOVFISRPtrFun != NULL)
	{
	TMR1_OVFISRPtrFun = TMR1_callbackOVFISRPtrFun;
	}
	else
	{
		return TMR1_HALNULLPtrError;
	}
	return TMR1_HALNoError;
}
TMR1_HAL_ErrorStatus_t TMR1_HAL_CAPISRPtrFun (void  (*TMR1_callbackCAPISRPtrFun) (void))//for overflow off ICR
{
	if (TMR1_callbackCAPISRPtrFun != NULL)
	{
	TMR1_CAPISRPtrFun = TMR1_callbackCAPISRPtrFun;
	}
	else
	{
		return TMR1_HALNULLPtrError;
	}
	return TMR1_HALNoError;	
}
TMR1_HAL_ErrorStatus_t TMR1_HAL_CTCAISRPtrFun(void (*TMR1_callbackCTCAISRPtrFun)(void))//for compare match on OC1A
{
	if (TMR1_callbackCTCAISRPtrFun != NULL)
	{
	 TMR1_CTCAISRPtrFun = TMR1_callbackCTCAISRPtrFun;
	}
	else
	{
		return TMR1_HALNULLPtrError;
	}
	return TMR1_HALNoError;
}
TMR1_HAL_ErrorStatus_t TMR1_HAL_CTCBISRPtrFun(void (*TMR1_callbackCTCBISRPtrFun)(void))//for compare match on OC1B
{
	if (TMR1_callbackCTCBISRPtrFun != NULL)
	{
		TMR1_CTCBISRPtrFun	= 	TMR1_callbackCTCBISRPtrFun;
	}
	else
	{
		return TMR1_HALNULLPtrError;
	}
	return TMR1_HALNoError;

}