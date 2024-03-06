/*
 * DIO_interface.h
 *
 * Created: 25/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*************** MACROS FOR PIN ***************/

/* Macros For Pin Id */
#define DIO_PIN0                 0
#define DIO_PIN1                 1
#define DIO_PIN2                 2
#define DIO_PIN3                 3
#define DIO_PIN4                 4
#define DIO_PIN5                 5
#define DIO_PIN6                 6
#define DIO_PIN7                 7

/* Macros For Pin Direction */
#define DIO_PIN_INPUT            0
#define DIO_PIN_OUTPUT           1

/* Macros For Pin state */
#define DIO_PIN_LOW              0
#define DIO_PIN_HIGH             1


/*************** MACROS FOR PORT ***************/

/* Macros For Port Id */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

/* Macros For Port Direction */
#define DIO_PORT_INPUT      0x00
#define DIO_PORT_OUTPUT     0xff

/* Macros For Port state */
#define DIO_PORT_LOW        0x00
#define DIO_PORT_HIGH       0xff

/*************** APIS POSSIBLE ERRORS ***************/
typedef enum 
{
	NoError,
	PinIdError,
	PinDirError,
	PinValError,
	PortIdError,
	PortDirError,
	PortValError,
	NullPtrError
	
}DIO_ErrorStatus_t;

/*************** APIS PROTO TYPES ***************/

/* Pin APIS */
DIO_ErrorStatus_t DIO_setPinDirection            (u8 PortId, u8 PinId, u8 PinDirection);
DIO_ErrorStatus_t DIO_setPinValue                (u8 PortId, u8 PinId, u8 PinValue);
DIO_ErrorStatus_t DIO_togglePinValue             (u8 PortId, u8 PinId);
DIO_ErrorStatus_t DIO_getPinValue                (u8 PortId, u8 PinId, u8* PinValue);
DIO_ErrorStatus_t DIO_activePinInPullUpResistance(u8 PortId, u8 PinId);


/* Port APIS */
DIO_ErrorStatus_t DIO_setPortDirection            (u8 PortId, u8 PortDirection);
DIO_ErrorStatus_t DIO_setPortValue                (u8 PortId, u8 PortValue);
DIO_ErrorStatus_t DIO_togglePortValue             (u8 PortId);
DIO_ErrorStatus_t DIO_getPortValue                (u8 PortId, u8* PortValue);
DIO_ErrorStatus_t DIO_activePortInPullUpResistance(u8 PortId);



#endif /* DIO_INTERFACE_H_ */