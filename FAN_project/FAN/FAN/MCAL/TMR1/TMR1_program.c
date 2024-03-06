/*
 * TMR1_program.c
 *
 * Created: 14/01/2024
 *  Author: Mahmoud Barakat
 */ 
/* SERVICE LAYER */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"
/* MCAL */
/* ADC */
#include "TMR1_private.h"
#include "TMR1_config.h"
#include "TMR1_interface.h"

#define ISR(vector)											            \
void vector(void) __attribute__((signal,used,externally_visible));       \
void vector(void)
ISR(__vector_6)
{
	TMR1_CAPISRPtrFun();	
}
ISR(__vector_7)
{
	TMR1_CTCAISRPtrFun();
}
ISR(__vector_8)
{
	TMR1_CTCBISRPtrFun();
}
ISR(__vector_9)
{
	TMR1_OVFISRPtrFun();
}

/*************** APIS PROTOTYPES ***************/
TMR1_ErrorStatus_t TMR1_init(u8 TMR1Mode,u8 OC1Mode)// initialization
{
	if (TMR1Mode < 16 && TMR1Mode != 13)
	{
		switch (TMR1Mode)
		{
			case TMR1_NORMALMODE    :
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PWM_8BIT		:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PWM_9BIT		:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PWM_10BIT		:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_CTC_OCR1A		:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_FASTPWM_8BIT	:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_FASTPWM_9BIT	:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_FASTPWM_10BIT	:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PFCPWM_ICR1	:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PFCPWM_OCR1A	:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PWM_ICR1		:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_PWM_OCR1A		:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_CTC_ICR1		:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_FASTPWM_ICR1	:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			case TMR1_FASTPWM_OCR1A	:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			
			
			
		}
		
		if (OC1Mode < 4)
		{
			switch (OC1Mode)
			{
				case TMR1_NORMALPORT: 
				CLR_BIT(TCCR1A,COM1A0);
				CLR_BIT(TCCR1A,COM1A1);
				CLR_BIT(TCCR1A,COM1B0);
				CLR_BIT(TCCR1A,COM1B1);
				break; 
				
				case TMR1_TOGGLE_OC1: 
				SET_BIT(TCCR1A,COM1A0);
				CLR_BIT(TCCR1A,COM1A1);
				SET_BIT(TCCR1A,COM1B0);
				CLR_BIT(TCCR1A,COM1B1);
				break;
				
				case TMR1_CLEAR_OC1 :
				CLR_BIT(TCCR1A,COM1A0);
				SET_BIT(TCCR1A,COM1A1);
				CLR_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;
				
				case TMR1_SET_OC1	:
				SET_BIT(TCCR1A,COM1A0);
				SET_BIT(TCCR1A,COM1A1);
				SET_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
				break;
			}
		} 
		else
		{
			return TMR1OC1ModeError;
		}
	} 
	else
	{
		return TMR1ModeError;
	}
	return TMR1NoError;
}

void TMR1_start(void)//start timer 0
{
	TCCR1B|=TMR1_CLOCKSELECT;
}
void TMR1_stop(void)//Stop timer 0
{
	TCCR1B|=TMR1_STOPPED;
}
void TMR1_reset(void)//Reset timer 0
{
	TCNT1_u16 =(u8)0x00;
}

void TMR1_writePreloadValue(u16 preloadValue)//to write the pre_load(new zero)
{
	TCNT1_u16 =preloadValue;
}
void TMR1_writeComparingValueA(u16 compValue)//comparing value to write the OCR1A
{
	OCR1A_u16 = compValue;
}
void TMR1_writeComparingValueB(u16 compValue)//comparing value to write the OCR1B
{
	OCR1B_u16 = compValue;
}
void TMR1_writeCapturingValue(u16 CaptValue)//comparing value to write the ICR1
{
	ICR1_u16 = CaptValue;
}

u8 TMR1_tickTimemicro(void)
{u16 prescaller;
	switch(TMR1_CLOCKSELECT)
	{
		case TMR1_NOPRESCALING		:
		prescaller = 1;
		break;
		case TMR1_PRESCALING_8   	:
		prescaller =8;
		break;
		case TMR1_PRESCALING_64  	:
		prescaller=64;
		break;
		case TMR1_PRESCALING_256 	:
		prescaller =256;
		break;
		case TMR1_PRESCALING_1024	:
		prescaller = 1024;
		break;
	}
return	(prescaller/16);
}

//INT enable &disable
void TMR1_OVRIntEnable(void)//overflow INT enable
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE1);
}
void TMR1_OVRIntDisable(void)//overflow INT disable
{
	CLR_BIT(TIMSK,TOIE1);
}

void TMR1_CAPtIntEnable(void)//Input Capture INT enable
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TICIE1);
}
void TMR1_CAPtIntDisable(void)//Input Capture INT disable
{
	CLR_BIT(TIMSK,TICIE1);
}

void TMR1_COMPAIntEnable(void)//comparing A INT enable
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE1A);
}
void TMR1_COMPAIntDisable(void)//comparing A INT disable
{
	CLR_BIT(TIMSK,OCIE1A);
}

void TMR1_COMPBIntEnable(void)//comparing B INT enable
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE1B);
}
void TMR1_COMPBIntDisable(void)//comparing B INT disable
{
	CLR_BIT(TIMSK,OCIE1B);
}

//TIMER NOISE FUNS
void TIMER1_NONoise(void)
{
	CLR_BIT(TCCR1B,ICNC1);//Noise canceler off
}
void TIMER1_INCAPFalling(void)
{
	SET_BIT(TCCR1B,ICNC1);//Noise canceler on
	CLR_BIT(TCCR1B,ICES1);
}
void TIMER1_INCAPRissing(void)
{
	SET_BIT(TCCR1B,ICNC1);//Noise canceler on
	SET_BIT(TCCR1B,ICES1);
}