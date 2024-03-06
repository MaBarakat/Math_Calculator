/*
 * TMR1_interface.h
 *
 * Created: 14/01/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	TMR1NoError,
	TMR1ModeError,
	TMR1OC1ModeError
}TMR1_ErrorStatus_t;

/***** TIMER MODE *****/
#define TMR1_NORMALMODE		0
#define TMR1_PWM_8BIT		1
#define TMR1_PWM_9BIT		2
#define TMR1_PWM_10BIT		3
#define TMR1_CTC_OCR1A		4
#define TMR1_FASTPWM_8BIT	5
#define TMR1_FASTPWM_9BIT	6
#define TMR1_FASTPWM_10BIT	7
#define TMR1_PFCPWM_ICR1	8
#define TMR1_PFCPWM_OCR1A	9
#define TMR1_PWM_ICR1		10
#define TMR1_PWM_OCR1A		11
#define TMR1_CTC_ICR1		12
#define TMR1_FASTPWM_ICR1	14
#define TMR1_FASTPWM_OCR1A	15

/*Compare Match Output Mode */
#define TMR1_NORMALPORT     (u8)0 // OC1 disconnected.
#define TMR1_TOGGLE_OC1     (u8)1 //in PWM is Reserved.
#define TMR1_CLEAR_OC1      (u8)2 //Clear OC1 on compare match (when up-counting),Non-Inverted.
#define TMR1_SET_OC1		(u8)3 //Set OC1 on compare match (when up-counting),Inverted.

/*************** APIS PROTOTYPES ***************/
TMR1_ErrorStatus_t TMR1_init(u8 TMR1Mode,u8 OC1Mode);// initialization

void TMR1_start(void);//start timer 0
void TMR1_stop(void);//Stop timer 0
void TMR1_reset(void);//Reset timer 0

void TMR1_writePreloadValue(u16 preloadValue);//to write the pre_load(new zero)
void TMR1_writeComparingValueA(u16 compValue);//comparing value to write the OCR1A
void TMR1_writeComparingValueB(u16 compValue);//comparing value to write the OCR1B
void TMR1_writeCapturingValue(u16 CaptValue);//comparing value to write the ICR1
u8 TMR1_tickTimemicro(void);

//INT enable &disable
void TMR1_OVRIntEnable(void);//overflow INT enable
void TMR1_OVRIntDisable(void);//overflow INT disable

void TMR1_CAPtIntEnable(void);//Input Capture INT enable
void TMR1_CAPtIntDisable(void);//Input Capture INT disable

void TMR1_COMPAIntEnable(void);//comparing A INT enable
void TMR1_COMPAIntDisable(void);//comparing A INT disable

void TMR1_COMPBIntEnable(void);//comparing B INT enable
void TMR1_COMPBIntDisable(void);//comparing B INT disable

//ISR FUNs
void (*TMR1_OVFISRPtrFun)(void);//for overflow In normal and CTC modes
void (*TMR1_CAPISRPtrFun)(void);//for overflow of ICR 
void (*TMR1_CTCAISRPtrFun)(void);//for compare match on OC1A
void (*TMR1_CTCBISRPtrFun)(void);//for compare match on OC1B

//TIMER NOISE FUNS // Rarely used
void TIMER1_NONoise(void);
void TIMER1_INCAPFalling(void);
void TIMER1_INCAPRissing(void);


#endif /* TMR1_INTERFACE_H_ */