/*
 * TMR1_config.h
 *
 * Created: 14/01/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

/*---TIMER1 Clock Select---*/
#define TMR1_STOPPED            (u8)0   //No_Clock_Source
#define TMR1_NOPRESCALING   	(u8)1   //no prescaling
#define TMR1_PRESCALING_8   	(u8)2   //Clock/8
#define TMR1_PRESCALING_64  	(u8)3   //Clock/64
#define TMR1_PRESCALING_256 	(u8)4   //Clock/256
#define TMR1_PRESCALING_1024	(u8)5   //Clock/1024
#define TMR1_FALLINGEXTCLOCK	(u8)6   //(EVENT)using as Counter with S.W(clock on falling edge)
#define TMR1_RISINGEXTCLOCK		(u8)7   //(EVENT)using as Counter with S.W(clock on raising edge)

#define TMR1_CLOCKSELECT		TMR1_PRESCALING_64



#endif /* TMR1_CONFIG_H_ */