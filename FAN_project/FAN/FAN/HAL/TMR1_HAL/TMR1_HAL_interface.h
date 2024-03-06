/*
 * TMR1_HAL_HAL_interface.h
 *
 * Created: 02/02/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef TMR1_HAL_INTERFACE_H_
#define TMR1_HAL_INTERFACE_H_

/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	TMR1_HALNoError,
	TMR1_HALModeError,
	TMR1_HALOC1ModeError,
	TMR1_HALNULLPtrError
}TMR1_HAL_ErrorStatus_t;

/***** TIMER MODE *****/
#define TMR1_HAL_NORMALMODE		0
#define TMR1_HAL_PWM_8BIT		1
#define TMR1_HAL_PWM_9BIT		2
#define TMR1_HAL_PWM_10BIT		3
#define TMR1_HAL_CTC_OCR1A		4
#define TMR1_HAL_FASTPWM_8BIT	5
#define TMR1_HAL_FASTPWM_9BIT	6
#define TMR1_HAL_FASTPWM_10BIT	7
#define TMR1_HAL_PFCPWM_ICR1	8
#define TMR1_HAL_PFCPWM_OCR1A	9
#define TMR1_HAL_PWM_ICR1		10
#define TMR1_HAL_PWM_OCR1A		11
#define TMR1_HAL_CTC_ICR1		12
#define TMR1_HAL_FASTPWM_ICR1	14
#define TMR1_HAL_FASTPWM_OCR1A	15

/*Compare Match Output Mode */
#define TMR1_HAL_NORMALPORT     (u8)0 // OC1 disconnected.
#define TMR1_HAL_TOGGLE_OC1     (u8)1 //in PWM is Reserved.
#define TMR1_HAL_CLEAR_OC1      (u8)2 //Clear OC1 on compare match (when up-counting),Non-Inverted.
#define TMR1_HAL_SET_OC1		(u8)3 //Set OC1 on compare match (when up-counting),Inverted.

/*************** APIS PROTOTYPES ***************/
TMR1_HAL_ErrorStatus_t TMR1_HAL_init(u8 TMR1_HALMode,u8 OC1Mode);// initialization

void TMR1_HAL_start(void);//start timer 0
void TMR1_HAL_stop(void);//Stop timer 0
void TMR1_HAL_reset(void);//Reset timer 0

void TMR1_HAL_writePreloadValue(u16 preloadValue);//to write the pre_load(new zero)
void TMR1_HAL_writeComparingValueA(u16 compValue);//comparing value to write the OCR1A
void TMR1_HAL_writeComparingValueB(u16 compValue);//comparing value to write the OCR1B
void TMR1_HAL_writeCapturingValue(u16 CaptValue);//comparing value to write the ICR1

//INT enable &disable
void TMR1_HAL_OVRIntEnable(void);//overflow INT enable
void TMR1_HAL_OVRIntDisable(void);//overflow INT disable
void TMR1_HAL_CAPtIntEnable(void);//Input Capture INT enable
void TMR1_HAL_CAPtIntDisable(void);//Input Capture INT disable
void TMR1_HAL_COMPAIntEnable(void);//comparing A INT enable
void TMR1_HAL_COMPAIntDisable(void);//comparing A INT disable
void TMR1_HAL_COMPBIntEnable(void);//comparing B INT enable
void TMR1_HAL_COMPBIntDisable(void);//comparing B INT disable

//ISR FUNs 
TMR1_HAL_ErrorStatus_t TMR1_HAL_OVFISRPtrFun (void  (*TMR1_callbackOVFISRPtrFun) (void));//for overflow In normal and CTC modes
TMR1_HAL_ErrorStatus_t TMR1_HAL_CAPISRPtrFun (void  (*TMR1_callbackCAPISRPtrFun) (void));//for overflow off ICR
TMR1_HAL_ErrorStatus_t TMR1_HAL_CTCAISRPtrFun(void (*TMR1_callbackCTCAISRPtrFun)(void));//for compare match on OC1A
TMR1_HAL_ErrorStatus_t TMR1_HAL_CTCBISRPtrFun(void (*TMR1_callbackCTCBISRPtrFun)(void));//for compare match on OC1B





#endif /* TMR1_HAL_INTERFACE_H_ */