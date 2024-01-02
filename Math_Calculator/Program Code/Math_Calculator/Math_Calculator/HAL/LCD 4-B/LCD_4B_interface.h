/*
 * LCD_4B_interface.h
 *
 * Created: 30/12/2023
 *  Author: Mahmoud Barakat
 */ 


#ifndef LCD_4B_INTERFACE_H_
#define LCD_4B_INTERFACE_H_
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	LCD4BNoError,
	LCD4BIdError,
	LCD4BPositionError
}LCD4B_ErrorStatus_t;

// instructions
//assume any don't care bit by zero
#define CLEAR_DISP				(u8)0X01//after use in cmnd _delay_ms(2);
#define RETURN_HOME				(u8)0X02//after use in cmnd _delay_ms(2);
//after use in cmnd _delay_us(50); for all
#define ENTRY_MODE_INC			(u8)0X06//INCREMENTAC++
#define ENTRY_MODE_DEC			(u8)0X04//DECREMENT AC--
#define DISP_ON					(u8)0X0C	//CURSOR OFF can then write #define cursor_DISP 0X10 //to CURSOR On but  not needed use one instruction to do the two instructions is better
#define DISP_OFF				(u8)0X08
// instructions and Macros For LCD Shifting Direction
#define SHIFT_DISP_R			(u8)0X1C // to shift the display right not change in DDRAM
#define SHIFT_DISP_L			(u8)0X18 // to shift the display left not change in DDRAM
#define CURSOR_ON_BLINKING_OFF	(u8)0X0E //this is the one instruction to display on and cursor on but blinking off
#define CURSOR_ON_BLINKING_ON	(u8)0X0F //this is the one instruction to display on , cursor on and blinking on
#define LCD_4BITMODE			(u8)0X28//4bit mode LCD
#define ADD_CGRAM				(u8)0X40
#define ADD_DDRAM				(u8)0X80

// Macros For LCD Line Id
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

// Macros For LCD Id
#define LCD_4B_ONE			    0
#define LCD_4B_TWO			    1
#define LCD_4B_THREE		    2
#define LCD_4B_FOUR			    3

//Addresses off CGRAM
#define CGRAM_ADDRESS0			0
#define CGRAM_ADDRESS1		    1
#define CGRAM_ADDRESS2			2
#define CGRAM_ADDRESS3			3
#define CGRAM_ADDRESS4			4
#define CGRAM_ADDRESS5			5
#define CGRAM_ADDRESS6			6
#define CGRAM_ADDRESS7			7

/*************** APIS PROTO TYPES ***************/
LCD4B_ErrorStatus_t LCD_4B_init(u8 LCD_4BId);//initialization
//Write Instructions
LCD4B_ErrorStatus_t LCD_4B_sendCmnd(u8 LCD_4BId,u8 Cmnd);
LCD4B_ErrorStatus_t	LCD_4B_clear(u8 LCD_4BId);
LCD4B_ErrorStatus_t	LCD_4B_shift(u8 LCD_4BId,u8 shiftDirection);
LCD4B_ErrorStatus_t	LCD_4B_goToSpecificPosition(u8 LCD_4BId,u8 lineNumber, u8 Position);
LCD4B_ErrorStatus_t	LCD_4B_SavePatternInCGRAM(u8 LCD_4BId,u8*pattern,u8 Position );
//Write Data
LCD4B_ErrorStatus_t LCD_4B_sendChar(u8 LCD_4BId,u8 data);
LCD4B_ErrorStatus_t LCD_4B_writeString(u8 LCD_4BId,u8* String);
LCD4B_ErrorStatus_t LCD_4B_writeNumber(u8 LCD_4BId,s32 number);
LCD4B_ErrorStatus_t LCD_4B_writeFloatNumber(u8 LCD_4BId,f32 fnumber,u8 numofdigit);


#endif /* LCD_4B_INTERFACE_H_ */