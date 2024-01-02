/*
 * LCD_4B_program.c
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
#include "LCD_4B_interface.h"
#include "LCD_4B_private.h"
//frequency and including drivers(delay)
#define F_CPU 16000000UL
#include <util/delay.h>

//Ports and Pins of LCD from Configuration
//Control Ports and Pins
extern u8 Rs_4B_port[LCD_4B_num];
extern u8 Rs_4B_pin[LCD_4B_num];
			 
extern u8 Rw_4B_port[LCD_4B_num];
extern u8 Rw_4B_pin[LCD_4B_num];

extern u8 E_4B_port[LCD_4B_num];
extern u8 E_4B_pin[LCD_4B_num];

//Data Ports and Pins
extern u8 LCD_4B_port[LCD_4B_num*4];

extern u8 LCD_4B_PINS[LCD_4B_num*4];

/*************** APIS  ***************/
LCD4B_ErrorStatus_t LCD_4B_init(u8 LCD_4BId)
{u8 LCD4B_counter=0;
	if (LCD_4BId < LCD_4B_num)//The first LCD_4BId is 0
	{//power on (Directions of LCD_4B Control and Data Pins)
		//Control Pins Direction
		DIO_setPinDirection(Rs_4B_port[LCD_4BId],Rs_4B_pin[LCD_4BId],DIO_PIN_OUTPUT);//RS
		DIO_setPinDirection(Rw_4B_port[LCD_4BId],Rw_4B_pin[LCD_4BId],DIO_PIN_OUTPUT);//RW
		DIO_setPinDirection(E_4B_port[LCD_4BId] ,E_4B_pin[LCD_4BId] ,DIO_PIN_OUTPUT);//E
		//Data Pins Direction
		for (LCD4B_counter=(LCD_4BId*4);LCD4B_counter<((LCD_4BId+1)*4);LCD4B_counter++)
		{
			DIO_setPinDirection(LCD_4B_port[LCD4B_counter],LCD_4B_PINS[LCD4B_counter],DIO_PIN_OUTPUT);
		}
		_delay_ms(40);//wait more than 30 ms
		//Function Set
		DIO_setPinValue(Rs_4B_port[LCD_4BId],Rs_4B_pin[LCD_4BId],DIO_PIN_LOW);//Write command
		DIO_setPinValue(Rw_4B_port[LCD_4BId],Rw_4B_pin[LCD_4BId],DIO_PIN_LOW);//Write
		private_writeHalfPort(LCD_4BId,(LCD_4BITMODE>>4));
		/* Enable Pulse *//* H => L */
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_LOW);
		LCD_4B_sendCmnd(LCD_4BId,LCD_4BITMODE);
		_delay_us(50);//wait more than 39 us
		//Display ON/OFF Control (Display On, Cursor off, Blink off)
		LCD_4B_sendCmnd(LCD_4BId,DISP_ON);
		_delay_us(50);//wait more than 39 us
		//Display Clear
		LCD_4B_sendCmnd(LCD_4BId,CLEAR_DISP);
		_delay_ms(2);//wait more than 1.53
		//Entry Mode Set
		LCD_4B_sendCmnd(LCD_4BId,ENTRY_MODE_INC);
		//End of initialization
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
	
}
//Write Instructions
LCD4B_ErrorStatus_t LCD_4B_sendCmnd(u8 LCD_4BId,u8 Cmnd)
{
	if (LCD_4BId < LCD_4B_num)
	{
	  //Function Set
	 DIO_setPinValue(Rs_4B_port[LCD_4BId],Rs_4B_pin[LCD_4BId],DIO_PIN_LOW);//Write command
	 DIO_setPinValue(Rw_4B_port[LCD_4BId],Rw_4B_pin[LCD_4BId],DIO_PIN_LOW);//Write
	 // Write The Most 4 bits Of command on Data Pins
	 private_writeHalfPort(LCD_4BId,(Cmnd>>4));
	 /* Enable Pulse *//* H => L */
	 DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_HIGH);
	 _delay_ms(1);
	 DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_LOW);
	 // Write The Least 4 bits Of command on Data Pins
	 private_writeHalfPort(LCD_4BId,Cmnd);
	 /* Enable Pulse *//* H => L */
	 DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_HIGH);
	 _delay_ms(1);
	 DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_LOW);
	 // most of commands need (39us to 43us) except clear and return home
	 _delay_us(50);
	}else
	{
		return LCD4BIdError;
	}	
		
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_clear(u8 LCD_4BId)
{
	if (LCD_4BId < LCD_4B_num)
	{
		// Clear Display
		LCD_4B_sendCmnd(LCD_4BId,CLEAR_DISP);
		_delay_ms(2);
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_shift(u8 LCD_4BId,u8 shiftDirection)
{
	if (LCD_4BId < LCD_4B_num)
	{	// shift Display
	 switch (shiftDirection)
	 {
	 	case SHIFT_DISP_L :
	 	LCD_4B_sendCmnd(LCD_4BId,SHIFT_DISP_L);
	 	break;
	 	case SHIFT_DISP_R:
	 	LCD_4B_sendCmnd(LCD_4BId,SHIFT_DISP_R);
	 	break;
	 }
		
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_goToSpecificPosition(u8 LCD_4BId,u8 lineNumber, u8 Position)
{
	if (LCD_4BId < LCD_4B_num)
	{if(Position<16)
		{
			switch(lineNumber)
			{
				case LCD_LINE_ONE:
				LCD_4B_sendCmnd(LCD_4BId,(ADD_DDRAM+Position));
				break;
				case LCD_LINE_TWO:
				LCD_4B_sendCmnd(LCD_4BId,(0xc0+Position));//0xc0 =ADD_DDRAM+0x40
				break;
			}
		}else
		{
			return LCD4BPositionError;
		}
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_SavePatternInCGRAM(u8 LCD_4BId,u8*pattern,u8 Position )
{u8 rowcounter=0;//8 rows in segment of CGRAM (but the 8th one does not be written on -DDRAM-LCD(5*7))
	if (LCD_4BId < LCD_4B_num)
	{
		LCD_4B_sendCmnd(LCD_4BId,(ADD_CGRAM+(Position*8)));
		for (rowcounter=0;rowcounter<8;rowcounter++)
		{
			LCD_4B_sendChar(LCD_4BId,*(pattern+rowcounter));
		}
		LCD_4B_sendCmnd(LCD_4BId,ADD_DDRAM);
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
//Write Data
LCD4B_ErrorStatus_t LCD_4B_sendChar(u8 LCD_4BId,u8 data)
{
	if (LCD_4BId < LCD_4B_num)
	{
		DIO_setPinValue(Rs_4B_port[LCD_4BId],Rs_4B_pin[LCD_4BId],DIO_PIN_HIGH);//write data
		DIO_setPinValue(Rw_4B_port[LCD_4BId],Rw_4B_pin[LCD_4BId],DIO_PIN_LOW);//write
		// Write The Most 4 bits Of data on Data Pins
		private_writeHalfPort(LCD_4BId,data>>4);
		/* Enable Pulse *//* H => L */
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_LOW);
		// Write The Least 4 bits Of command on Data Pins
		private_writeHalfPort(LCD_4BId,data);
		/* Enable Pulse *//* H => L */
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_setPinValue(E_4B_port[LCD_4BId], E_4B_pin[LCD_4BId], DIO_PIN_LOW);
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_writeString(u8 LCD_4BId,u8* String)
{u8 counter=0;
	if (LCD_4BId < LCD_4B_num)
	{
		while(String[counter]!='\0')
		{
			LCD_4B_sendChar(LCD_4BId,String[counter]);
			++counter;
		}
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_writeNumber(u8 LCD_4BId,s32 number)
{s32 reversedNum = 1;
	if (LCD_4BId < LCD_4B_num)
	{
		if(number == 0)
		{
			LCD_4B_sendChar(LCD_4BId,'0');
		}
		else
		{
			if (number < 0)
			{
				LCD_4B_sendChar(LCD_4BId,'-');
				
				number=number*-1;
			}else
			{
				//DO Nothing
			}
			// reverse
			while(number != 0)
			{
				reversedNum = (reversedNum*10)+(number%10);
				number/=10;
			}
			do
			{	LCD_4B_sendChar(LCD_4BId,((reversedNum%10)+'0'));
				reversedNum/=10;
			} while (reversedNum!=1);
		}
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}
LCD4B_ErrorStatus_t LCD_4B_writeFloatNumber(u8 LCD_4BId,f32 fnumber,u8 numofdigit)
{s32 integernumber;u16 mantissanumber, accuracy;
	
	if (LCD_4BId < LCD_4B_num)
	{
		if(fnumber == 0)
		{
			LCD_4B_sendChar(LCD_4BId,'0');
		}
		else
		{
			if (fnumber < 0)
			{
				LCD_4B_sendChar(LCD_4BId,'-');
				
				fnumber=fnumber*-1;
			}else
			{
				//DO Nothing
			}
			
			//integer part
			integernumber=(s32)fnumber;
			LCD_4B_writeNumber(LCD_4BId,integernumber);
			
			LCD_4B_sendChar(LCD_4BId,'.');
			accuracy =power_fun((u8)10,numofdigit);
			//mantissa part
			mantissanumber=(fnumber-(f32)integernumber)*accuracy;
			LCD_4B_writeNumber(LCD_4BId,(s32)mantissanumber);
		}
	}else
	{
		return LCD4BIdError;
	}
	
	return LCD4BNoError;
}


//private functions
static u16 power_fun(u16 number,u8 power)
{ u8 counter;u16 givennumber=number;//counter
	if (power==0)
	{
		number=1;
	}else
	{
		for (counter=1;counter<power;counter++)
		{
			number=number*givennumber;
		}
	}
	return number;
	
}

static LCD4B_ErrorStatus_t private_writeHalfPort(u8 LCD_4BId,u8 value)
{u8 LCD4B_bitCounter=0,value_bitCounter=0;
	if (LCD_4BId < LCD_4B_num )
	{
		for (LCD4B_bitCounter=(LCD_4BId*4);LCD4B_bitCounter<((LCD_4BId+1)*4);LCD4B_bitCounter++)
		{
			DIO_setPinValue(LCD_4B_port[LCD4B_bitCounter],LCD_4B_PINS[LCD4B_bitCounter],GET_BIT(value,value_bitCounter));
			value_bitCounter++;
		}
	}else
	{
		return LCD4BIdError;
	}
	return LCD4BNoError;
}