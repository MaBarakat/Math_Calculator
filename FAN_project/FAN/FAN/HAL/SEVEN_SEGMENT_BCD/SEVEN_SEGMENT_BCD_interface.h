/*
 * SEVEN_SEGMENT_BCD_interface.h
 *
 * Created: 31/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef SEVEN_SEGMENT_BCD_INTERFACE_H_
#define SEVEN_SEGMENT_BCD_INTERFACE_H_

/*************** macros use DIP ***************/
#define dipused 1
#define dipnotused 0
/*************** macros SEVEN SEGMENT id ***************/
#define SEVEN_SEGMENT_BCD_ONE	0
#define SEVEN_SEGMENT_BCD_TWO	1
#define SEVEN_SEGMENT_BCD_THREE 2
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	SEVEN_SEGMENT_BCDNoError,
	SEVEN_SEGMENT_BCDIdError,
}SEVEN_SEGMENT_BCDStatus_t;
/*************** APIS PROTO TYPES ***************/
SEVEN_SEGMENT_BCDStatus_t SEVEN_SEGMENT_BCD_init(u8 SEVEN_SEGMENTId,u8 dipstatus);
SEVEN_SEGMENT_BCDStatus_t SEVEN_SEGMENT_BCD_write(u8 SEVEN_SEGMENTId,u8 data);
SEVEN_SEGMENT_BCDStatus_t SEVEN_SEGMENT_BCD_off(u8 SEVEN_SEGMENTId);
SEVEN_SEGMENT_BCDStatus_t SEVEN_SEGMENT_BCD_DPon(u8 SEVEN_SEGMENTId);
SEVEN_SEGMENT_BCDStatus_t SEVEN_SEGMENT_BCD_DPoff(u8 SEVEN_SEGMENTId);



#endif /* SEVEN_SEGMENT_BCD_INTERFACE_H_ */