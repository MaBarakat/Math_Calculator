/*
 * KEYPAD_program.c
 *
 * Created: 31/12/2023
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
/* KEYPAD */
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

extern u8 KEYPAD_pattern [KEYPAD_ROWPINSNUM][KEYPAD_COLPINSNUM];
 
extern u8 ROW_Ports[KEYPAD_ROWPINSNUM*KEYPAD_NUM];
extern u8 COL_Ports[KEYPAD_COLPINSNUM*KEYPAD_NUM];
 
extern u8 ROW_Pins[KEYPAD_ROWPINSNUM*KEYPAD_NUM];
extern u8 COL_Pins[KEYPAD_COLPINSNUM*KEYPAD_NUM];

/*************** APIS ***************/

KEYPAD_ErrorStatus_t KEYPAD_init (u8 KEYPADId)
{
	if (KEYPADId < KEYPAD_NUM)
	{u8 ROW_counter=0,COL_counter=0;
		
		//ROWS >> input
		for (ROW_counter=0;ROW_counter<KEYPAD_ROWPINSNUM;ROW_counter++)
		{
			DIO_setPinDirection(ROW_Ports[ROW_counter],ROW_Pins[ROW_counter],DIO_PIN_INPUT);
		}
		
		//COLS >> output
		for (COL_counter=0;COL_counter<KEYPAD_COLPINSNUM;COL_counter++)
		{
			DIO_setPinDirection(COL_Ports[COL_counter],COL_Pins[COL_counter],DIO_PIN_OUTPUT);
		}
		
		//active internal pull up (ROWS initial value are ones)
		for (ROW_counter=0;ROW_counter<KEYPAD_ROWPINSNUM;ROW_counter++)
		{
			DIO_activePinInPullUpResistance(ROW_Ports[ROW_counter],ROW_Pins[ROW_counter]);
		}
	}else
	{
		return KEYPADIdError;
	}
	return KEYPADNoError;
}
KEYPAD_ErrorStatus_t KEYPAD_getValue(u8 KEYPADId,u8* returnedValue)
{
	if (KEYPADId < KEYPAD_NUM)
	{
			if(returnedValue != NULL)
			{
				*returnedValue = KEYPAD_NOT_PRESSED;
				
				u8 colsCounter,rowsCounter;
				u8 pinValue,pinFlag=0;
				for(colsCounter=0;colsCounter<KEYPAD_COLPINSNUM;colsCounter++)
				{
					// Activate Each cols
					DIO_setPinValue(COL_Ports[colsCounter],COL_Pins[colsCounter],DIO_PIN_LOW);
					
					for(rowsCounter=0;rowsCounter<KEYPAD_ROWPINSNUM;rowsCounter++)
					{
						DIO_getPinValue(ROW_Ports[rowsCounter],ROW_Pins[rowsCounter],&pinValue);
						if(0 == pinValue)//pressed
						{
							while(0 == pinValue)
							{
								DIO_getPinValue(ROW_Ports[rowsCounter],ROW_Pins[rowsCounter],&pinValue);
							}
							*returnedValue = KEYPAD_pattern[rowsCounter][colsCounter];
							pinFlag=1;
							break;
						}else
						{
							//do nothing
						}
					}
					
					if(1 == pinFlag)
					{
						break;
					}
					// Deactivate current cols
					DIO_setPinValue(COL_Ports[colsCounter],COL_Pins[colsCounter],DIO_PIN_HIGH);
				}
			}
			else
			{
				return KEYPADNULLPtrError;
			}		
	}else
	{
		return KEYPADIdError;
	}
	return KEYPADNoError;	
}
