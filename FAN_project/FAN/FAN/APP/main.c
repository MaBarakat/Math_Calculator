/*
 * FAN.c
 *
 * Created: 07/02/2024
 * Author : Mahmoud Barakat
 */ 

#define F_CPU  16000000UL
#include <util/delay.h>
/*****SERVICE*****/
/**UTILES_LIB**/
#include "../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../SERVICE/UTILES_LIB/BIT_MATH.h"


/*****HAL*****/
#include "../HAL/SW/SW_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/TMR1_HAL/TMR1_HAL_interface.h"
#include "../HAL/DCM/DCM_interface.h"
#include "../HAL/SERVOMOTOR/SERVO_interface.h"
#include "../HAL/SEVEN_SEGMENT_BCD/SEVEN_SEGMENT_BCD_interface.h"

int main(void)
{u8 Buttonon=0 ,ButtonRoll=0, speadcount=0, rollcount=0,anglecount=0;s8 angle=0;
	////switches
	SW_init(SW_PORTB,SW_PIN0);//Button on & Speed
    SW_init(SW_PORTD,SW_PIN6);//ButtonRoll
	////leds
	LED_init(LED_PORTC,LED_PIN2);//LED on & Speed
	LED_init(LED_PORTC,LED_PIN7);//LEDRoll
	//TIMER 1 (motors control)
	TMR1_HAL_init(TMR1_HAL_FASTPWM_ICR1,TMR1_HAL_CLEAR_OC1);
	TMR1_HAL_start();
	////DC
	DCM_init(DCM_MOTOR_A);
	////Servo
	SERVO_init();
	////ServSEVEN SEGMENT
	SEVEN_SEGMENT_BCD_init(SEVEN_SEGMENT_BCD_ONE,dipnotused);
	
	
    while (1) 
    {
		//reading part
	SW_getSwitchPinValue(SW_PORTB,SW_PIN0,&Buttonon);
	SW_getSwitchPinValue(SW_PORTD,SW_PIN6,&ButtonRoll);
		
	if (Buttonon == 1)
	{
		while(Buttonon == 1)//debouncing 
		{
			SW_getSwitchPinValue(SW_PORTB,SW_PIN0,&Buttonon);
		}
		speadcount++;
		if (speadcount > 3)
		{
			speadcount = 0;
		}
	}else
	{
		//no thing
	}
	
	if (ButtonRoll == 1)
	{
		while(ButtonRoll == 1)
		{
			SW_getSwitchPinValue(SW_PORTD,SW_PIN6,&ButtonRoll);
		}
		rollcount++;
		if (rollcount == 2)
		{
			rollcount = 0;
		}
	}else
	{
		//no thing
	}	
	
		//doing part
	
	if (speadcount > 0)
	{
		LED_on(LED_PORTC,LED_PIN2);
		SEVEN_SEGMENT_BCD_write(SEVEN_SEGMENT_BCD_ONE,speadcount);
		switch (speadcount)
		{
			case 1:
			DCM_onControlSpeed(DCM_MOTOR_A,DCM_COUNTER_CLOCK_WISE,30);
			break;
			
			case 2:
			DCM_onControlSpeed(DCM_MOTOR_A,DCM_COUNTER_CLOCK_WISE,60);
			break;
			
			case 3:
			DCM_onControlSpeed(DCM_MOTOR_A,DCM_COUNTER_CLOCK_WISE,90);
			break;
			
			default:
			//no thing
			break;
						
		}
	} 
	else
	{
		LED_off(LED_PORTC,LED_PIN2);
		DCM_off(DCM_MOTOR_A);
		SEVEN_SEGMENT_BCD_write(SEVEN_SEGMENT_BCD_ONE,speadcount);
		SEVEN_SEGMENT_BCD_off(SEVEN_SEGMENT_BCD_ONE);
		
	}
	
	
	if (rollcount == 1 && (speadcount > 0))
	{	
		_delay_ms(50);
		LED_on(LED_PORTC,LED_PIN7);
		if (angle == -90)
		{
			anglecount =0;
		} 
		else if (angle == 90)
		{
			anglecount =1;
		}
		
		if (anglecount == 0)
		{
			angle++;
		} 
		else
		{
			angle--;
		}
			SERVO_angle(SERVO90,angle);
		
	}
	else
	{
		LED_off(LED_PORTC,LED_PIN7);
		SERVO_angle(SERVO90,angle);
	}
		
    }
}

