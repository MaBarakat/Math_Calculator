/*
 * SERVO_interface.h
 *
 * Created: 07/02/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define SERVO90    0
#define SERVO180   1
/*************** APIS PROTOTYPES ***************/
void SERVO_init();
void SERVO_angle(u8 ServoType,s8 angle);



#endif /* SERVO_INTERFACE_H_ */