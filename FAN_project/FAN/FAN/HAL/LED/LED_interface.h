/*
 * LED_interface.h
 *
 * Created: 26/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/*************** MACROS FOR PIN ***************/

/* Macros For Pin Id */
#define LED_PIN0     0
#define LED_PIN1     1
#define LED_PIN2     2
#define LED_PIN3     3
#define LED_PIN4     4
#define LED_PIN5     5
#define LED_PIN6     6
#define LED_PIN7     7

/*************** MACROS FOR PORT ***************/

/* Macros For Port Id */
#define LED_PORTA    0
#define LED_PORTB    1
#define LED_PORTC    2
#define LED_PORTD    3
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	LEDNoError,
	LEDPinIdError,
	LEDPortIdError	
}LED_ErrorStatus_t;
/*************** APIS PROTO TYPES ***************/
LED_ErrorStatus_t LED_init  (u8 LedPort, u8 LedPin);
LED_ErrorStatus_t LED_on    (u8 LedPort, u8 LedPin);
LED_ErrorStatus_t LED_off   (u8 LedPort, u8 LedPin);
LED_ErrorStatus_t LED_toggle(u8 LedPort, u8 LedPin);



#endif /* LED_INTERFACE_H_ */