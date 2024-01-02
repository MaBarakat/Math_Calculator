/*
 * KEYPAD_interface.h
 *
 * Created: 31/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KEYPAD_NOT_PRESSED          0xff

// Macros For KEYPAD Id
#define KEYPAD_ONE		0 
#define KEYPAD_TWO		1
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	KEYPADNoError,
	KEYPADIdError,
	KEYPADNULLPtrError
}KEYPAD_ErrorStatus_t;

/*************** APIS PROTO TYPES ***************/

KEYPAD_ErrorStatus_t KEYPAD_init    (u8 KEYPADId);
KEYPAD_ErrorStatus_t KEYPAD_getValue(u8 KEYPADId,u8* returnedValue);


#endif /* KEYPAD_INTERFACE_H_ */