/*
 * SERVO_program.c
 *
 * Created: 07/02/2024
 *  Author: Mahmoud Barakat
 */ 

/* SERVICE LAYER */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"
#include "../../SERVICE/UTILES_LIB/MATH_EQs.h"
/* MCAL */
/* DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/* TMR1 */
#include "../../MCAL/TMR1/TMR1_interface.h"

/* HAL LAYER */
/* SERVO */
#include "SERVO_interface.h"

/*************** APIS PROTOTYPES ***************/

void SERVO_init()
{
	u8 tickTime=TMR1_tickTimemicro();
	u16 topvalue=20000/tickTime;
	//TMR1_init(TMR1_FASTPWM_ICR1,TMR1_CLEAR_OC1);
	TMR1_writeCapturingValue(topvalue);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
}
void SERVO_angle(u8 ServoType,s8 angle)
{
	if (ServoType < 2)
	{s8 minAngle  = 0,maxAngle = 180;
		switch (ServoType)
		{
			case SERVO90  :
			minAngle = -90;
			maxAngle =  90;
			break;
			case SERVO180 :
			minAngle = 0;
			maxAngle = 180;
			break;
		}
		 if (angle >= minAngle && angle <= maxAngle)
		 {
		 	u8 tickTime=TMR1_tickTimemicro();
			 //from data sheet servo motor (1000 : 2000 )
			 //in Egypt servo motor  (750 : 2500 )
		 	u16 minTmrVal=1000/tickTime;
		 	u16 maxTmrVal=2000/tickTime;
		 	u16 TmrVal =MAP (angle,minAngle,maxAngle,minTmrVal,maxTmrVal);
		 	TMR1_writeComparingValueA((u16)TmrVal);
		 //	TMR1_start();
		 }

	}
		
}