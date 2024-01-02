/*
 * Math_Calculator.c
 *
 * Created: 02/01/2024 
 * Author : Mahmoud Barakat
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

/* SERVICE */
/* UTILES_LIB */
#include "../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../SERVICE/UTILES_LIB/BIT_MATH.h"

/* HAL */
#include "../HAL/LCD 4-B/LCD_4B_interface.h" /* LCD 4B */
#include "../HAL/KEYPAD/KEYPAD_interface.h" /* KEYPAD */

//n1 --> number1,n2 --> number2,op --> oprator
s32 calc (s32 n1,s32 n2,u8 op);//function of calculations

int main(void)
{u8 writenvalue;//the value from Keypad
	s32 n1=0,n2=0,res=0;
	u8 op=0;
	u8 opflag=0,n1flag=0,n2flag=0,eqflag=0;
	u8 negativeflagn1=0;u8 negativeflagn2=0;
	//initialization
	KEYPAD_init(KEYPAD_ONE);
	LCD_4B_init(LCD_4B_ONE);
	LCD_4B_sendCmnd(LCD_4B_ONE,CURSOR_ON_BLINKING_ON);
	
	while (1)
	{KEYPAD_getValue(KEYPAD_ONE,&writenvalue);//read the value
		if (writenvalue != KEYPAD_NOT_PRESSED)
		{
			if (writenvalue == '=')
			{LCD_4B_sendCmnd(LCD_4B_ONE,DISP_ON);
				if (negativeflagn1 == 1)
				{
					n1=n1*(-1);negativeflagn1 =0;
				}
				if (negativeflagn2 == 1)
				{
					n2=n2*(-1);negativeflagn2 =0;
				}
				res=calc(n1,n2,op);
				LCD_4B_goToSpecificPosition(LCD_4B_ONE,LCD_LINE_TWO,10);
				LCD_4B_writeNumber(LCD_4B_ONE,res);
				eqflag=1;
			}else if ((writenvalue == '+') || (writenvalue == '-') || (writenvalue == '*') || (writenvalue == '/'))
			{LCD_4B_sendCmnd(LCD_4B_ONE,CURSOR_ON_BLINKING_ON);
				if (opflag == 1 && n2flag == 1 )
				{
					if (negativeflagn1 == 1)
					{
						n1=n1*(-1);negativeflagn1 =0;
					}
					if (negativeflagn2 == 1)
					{
						n2=n2*(-1);negativeflagn2 =0;
					}
					
					res=calc(n1,n2,op);
					eqflag = 1;
				}
				if (eqflag == 1)
				{
					n1=res;n2=0;
					LCD_4B_clear(LCD_4B_ONE);
					LCD_4B_writeNumber(LCD_4B_ONE,n1);	
					n1flag = 1; eqflag=0; opflag = 0;n2flag = 0;
				}
						
				if (n1flag == 1 && eqflag==0 && opflag == 0)
				{	LCD_4B_sendChar(LCD_4B_ONE,writenvalue);
					opflag=1;
					op =writenvalue;
				}else if (n1flag == 0 && writenvalue == '-' && negativeflagn1==0)
				{
					LCD_4B_sendChar(LCD_4B_ONE,writenvalue);
					negativeflagn1=1;
				}else if (n1flag == 1 && opflag == 1 && writenvalue == '-' )
				{
					LCD_4B_sendChar(LCD_4B_ONE,'(');
					LCD_4B_sendChar(LCD_4B_ONE,writenvalue);
					negativeflagn2=1;
				}else
				{
					//nothing
				}
			}else if (writenvalue == 'C')
			{
				LCD_4B_clear(LCD_4B_ONE);
				n2=0;n1=0;res=0;
				opflag=0;n1flag =0;n2flag =0;eqflag=0;
				
			}else //the numbers(0:9)
			{LCD_4B_sendCmnd(LCD_4B_ONE,CURSOR_ON_BLINKING_ON);
				if (eqflag == 1)
				{	
					LCD_4B_clear(LCD_4B_ONE);
					eqflag = 0;
					opflag = 0;
				}
				
				if (eqflag == 0)
				{
					LCD_4B_sendChar(LCD_4B_ONE,writenvalue);
					if (opflag == 1)
					{
						if (n2flag == 1)
						{
							n2=n2*10+(writenvalue-'0');
						}else
						{
							n2 = writenvalue-'0';
							n2flag =1;
						}
						
						
					}else
					{
						if (n1flag == 1)
						{
							n1=n1*10+(writenvalue-'0');
						}else
						{
							n1 = writenvalue-'0';
							n1flag =1;
						}
					}
					}
				
			}
			
		}
		
		
	}
}

s32 calc (s32 n1,s32 n2,u8 op)
{s32 res=0;
	switch (op)
	{
		case '+':
		res=n1+n2;
		break;
		case '*':
		res=n1*n2;
		break;
		case '/':
		res=n1/n2;
		break;
		case '-':
		res=n1-n2;
		break;
		default:
		break;
	}
	return res;
}