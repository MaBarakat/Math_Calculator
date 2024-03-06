/*
 * DCM_interface.h
 *
 * Created: 17/01/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_
//DC motor by H-Bridge
/*************** APIS POSSIBLE ERRORS ***************/
typedef enum
{
	DCMNoError,
	DCMIdError,
	DCMDirError,
	DCMSpeedError
}DCM_ErrorStatus_t;
#define DCM_MOTOR_A                      0
#define DCM_MOTOR_B                      1
#define DCM_MOTOR_C                      2
#define DCM_MOTOR_D                      3

#define DCM_CLOCK_WISE                   0
#define DCM_COUNTER_CLOCK_WISE           1

DCM_ErrorStatus_t DCM_init          (u8 motorId);
DCM_ErrorStatus_t DCM_on            (u8 motorId, u8 motorDirection);
DCM_ErrorStatus_t DCM_onControlSpeed(u8 motorId, u8 motorDirection, u8 motorSpeed);
DCM_ErrorStatus_t DCM_off           (u8 motorId);



#endif /* DCM_INTERFACE_H_ */