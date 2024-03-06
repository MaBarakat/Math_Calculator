/*
 * SW_interface.h
 *
 * Created: 26/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_
/*************** MACROS FOR PIN ***************/

/* Macros For Pin Id */
#define SW_PIN0     0
#define SW_PIN1     1
#define SW_PIN2     2
#define SW_PIN3     3
#define SW_PIN4     4
#define SW_PIN5     5
#define SW_PIN6     6
#define SW_PIN7     7

/*************** MACROS FOR PORT ***************/

/* Macros For Port Id */
#define SW_PORTA    0
#define SW_PORTB    1
#define SW_PORTC    2
#define SW_PORTD    3
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	SWNoError,
	SWPinIdError,
	SWPortIdError,
	SWNullPtrError
}SW_ErrorStatus_t;

/*************** APIS PROTO TYPES ***************/
SW_ErrorStatus_t SW_init(u8 swport,u8 swpin);
SW_ErrorStatus_t SW_getSwitchPinValue(u8 swport,u8 swpin,u8* swpinvalue);
SW_ErrorStatus_t SW_activeSwitchPinInPullUpResistance(u8 swport, u8 swpin);
#endif /* SW_INTERFACE_H_ */