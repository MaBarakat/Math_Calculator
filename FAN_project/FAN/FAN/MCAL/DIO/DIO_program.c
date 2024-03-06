/*
 * DIO_program.c
 *
 * Created: 25/12/2023
 *  Author: Mahmoud Barakat
 */ 

/* SERVICE LAYER */
/* UTILES_LIB */
#include "../../SERVICE/UTILES_LIB/STD_TYPES.h"
#include "../../SERVICE/UTILES_LIB/BIT_MATH.h"

/* MCAL LAYER */
/* DIO */
#include "DIO_interface.h"
#include "DIO_private.h"

/* Pin APIS */
DIO_ErrorStatus_t DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if(PortId<=3)
	{
		if (PinId<=7)
		{
			if ((PinDirection==DIO_PIN_OUTPUT)||(PinDirection==DIO_PIN_INPUT))
			{
				switch(PortId)
				{
					case DIO_PORTA:
					if(PinDirection == DIO_PIN_OUTPUT)
					{
						SET_BIT(DDRA,PinId);
					}
					else
					{
						CLR_BIT(DDRA,PinId);
					}
					break;
					
					case DIO_PORTB:
					if(PinDirection == DIO_PIN_OUTPUT)
					{
						SET_BIT(DDRB,PinId);
					}
					else
					{
						CLR_BIT(DDRB,PinId);
					}
					break;
					
					case DIO_PORTC:
					if(PinDirection == DIO_PIN_OUTPUT)
					{
						SET_BIT(DDRC,PinId);
					}
					else
					{
						CLR_BIT(DDRC,PinId);
					}
					break;
					
					case DIO_PORTD:
					if(PinDirection == DIO_PIN_OUTPUT)
					{
						SET_BIT(DDRD,PinId);
					}
					else
					{
						CLR_BIT(DDRD,PinId);
					}
					break;
				}
			}else
			{
				return PinDirError;
			}
			
		}else
		{
			return PinIdError;
		}
	}else
	{
		return PortIdError;
	}
	return NoError;	
}


DIO_ErrorStatus_t DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	if(PortId<=3)
	{
		if (PinId<=7)
		{
			if ((PinValue==DIO_PIN_HIGH)||(PinValue==DIO_PIN_LOW))
			{
				switch(PortId)
				{
					case DIO_PORTA:
					if(DIO_PIN_HIGH == PinValue)
					{
						SET_BIT(PORTA,PinId);
					}
					else
					{
						CLR_BIT(PORTA,PinId);
					}
					break;
					
					case DIO_PORTB:
					if(DIO_PIN_HIGH == PinValue)
					{
						SET_BIT(PORTB,PinId);
					}
					else
					{
						CLR_BIT(PORTB,PinId);
					}
					break;
					
					case DIO_PORTC:
					if(DIO_PIN_HIGH == PinValue)
					{
						SET_BIT(PORTC,PinId);
					}
					else
					{
						CLR_BIT(PORTC,PinId);
					}
					break;
					
					case DIO_PORTD:
					if(DIO_PIN_HIGH == PinValue)
					{
						SET_BIT(PORTD,PinId);
					}
					else
					{
						CLR_BIT(PORTD,PinId);
					}
					break;
				}
			}else
			{
				return PinValError;
			}
		}else
		{
			return PinIdError;
		}
		
	}
	else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_togglePinValue(u8 PortId, u8 PinId)
{
	if(PortId<=3)
	{
		if (PinId<=7)
		{
			switch(PortId)
			{
				case DIO_PORTA:
				TOG_BIT(PORTA,PinId);
				break;
				
				case DIO_PORTB:
				TOG_BIT(PORTB,PinId);
				break;
				
				case DIO_PORTC:
				TOG_BIT(PORTC,PinId);
				break;
				
				case DIO_PORTD:
				TOG_BIT(PORTD,PinId);
				break;
			}
		}else
		{
			return PinIdError;
		}
	}
	else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	if(PortId<=3)
	{
		if (PinId<=7)
		{
			if (PinValue!= NULL)
			{
				switch(PortId)
				{
					case DIO_PORTA:
					*PinValue = GET_BIT(PINA,PinId);
					break;
					
					case DIO_PORTB:
					*PinValue = GET_BIT(PINB,PinId);
					break;
					
					case DIO_PORTC:
					*PinValue = GET_BIT(PINC,PinId);
					break;
					
					case DIO_PORTD:
					*PinValue = GET_BIT(PIND,PinId);
					break;
				}
			}else
			{
				return NullPtrError;
			}
		}else
		{
			return PinIdError;
		}
		
	}
	else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_activePinInPullUpResistance(u8 PortId, u8 PinId)
{
	if(PortId<=3)
	{
		if (PinId<=7)
		{
			switch(PortId)
			{
				case DIO_PORTA:
				SET_BIT(PORTA,PinId);
				break;
				
				case DIO_PORTB:
				SET_BIT(PORTB,PinId);
				break;
				
				case DIO_PORTC:
				SET_BIT(PORTC,PinId);
				break;
				
				case DIO_PORTD:
				SET_BIT(PORTD,PinId);
				break;
			}
		}else
		{
			return PinIdError;
		}
	}
	else
	{
		return PortIdError;
	}
	return NoError;
}



/* Port APIS */
DIO_ErrorStatus_t DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	if(PortId<=3)
	{
		if ((DIO_PORT_OUTPUT == PortDirection) || (DIO_PORT_INPUT == PortDirection))
		{
					switch(PortId)
					{
						case DIO_PORTA:
						if(DIO_PORT_OUTPUT == PortDirection)
						{
							DDRA = DIO_PORT_OUTPUT;
						}
						else
						{
							DDRA = DIO_PORT_INPUT;
						}
						break;

						case DIO_PORTB:
						if(DIO_PORT_OUTPUT == PortDirection)
						{
							DDRB = DIO_PORT_OUTPUT;
						}
						else
						{
							DDRB = DIO_PORT_INPUT;
						}
						break;

						case DIO_PORTC:
						if(DIO_PORT_OUTPUT == PortDirection)
						{
							DDRC = DIO_PORT_OUTPUT;
						}
						else
						{
							DDRC = DIO_PORT_INPUT;
						}
						break;

						case DIO_PORTD:
						if(DIO_PORT_OUTPUT == PortDirection)
						{
							DDRD = DIO_PORT_OUTPUT;
						}
						else
						{
							DDRD = DIO_PORT_INPUT;
						}
						break;
					}
			
		}else
		{
			return PortDirError;
		}

	}else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_setPortValue(u8 PortId, u8 PortValue)
{
	if(PortId<=3)
	{
		if ((PortValue == DIO_PORT_HIGH)||(PortValue == DIO_PORT_LOW))
		{
			switch(PortId)
			{
				case 0:
				PORTA = PortValue;
				break;

				case 1:
				PORTB = PortValue;
				break;

				case 2:
				PORTC = PortValue;
				break;

				case 3:
				PORTD = PortValue;
				break;
			}
		}else
		{
			return PortValError;
		}
	}else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_getPortValue(u8 PortId, u8* PortValue)
{
	if(PortId<=3)
	{
		if (PortValue!= NULL)
		{
			switch(PortId)
			{
				case 0:
				*PortValue = PINA;
				break;

				case 1:
				*PortValue = PINB;
				break;

				case 2:
				*PortValue = PINC;
				break;

				case 3:
				*PortValue = PIND;
				break;
			}
		}else
		{
			return NullPtrError;
		}
	}else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_togglePortValue(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = ~PORTA;
			break;

			case 1:
			PORTB = ~PORTB;
			break;

			case 2:
			PORTC = ~PORTC;
			break;

			case 3:
			PORTD = ~PORTD;
			break;
		}
	}else
	{
		return PortIdError;
	}
	return NoError;
}


DIO_ErrorStatus_t DIO_activePortInPullUpResistance(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = 0xff;
			break;

			case 1:
			PORTB = 0xff;
			break;

			case 2:
			PORTC = 0xff;
			break;

			case 3:
			PORTD = 0xff;
			break;
		}
	}else
	{
		return PinIdError;
	}
	return NoError;
}