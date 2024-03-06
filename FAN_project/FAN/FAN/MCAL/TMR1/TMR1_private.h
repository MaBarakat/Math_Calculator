﻿/*
 * TMR1_private.h
 *
 * Created: 14/01/2024
 *  Author: Mahmoud Barakat
 */ 


#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_

			/* TIMER1 REGISTERS*/
// Timer/Counter1 Control Register A
#define TCCR1A             (*(volatile u8*)0x4F)
#define WGM10              0
#define WGM11              1
#define FOC1B              2
#define FOC1A              3
#define COM1B0             4
#define COM1B1             5
#define COM1A0             6
#define COM1A1             7

// Timer/Counter1 Control Register B
#define TCCR1B             (*(volatile u8*)0x4E)
#define CS10               0
#define CS11               1
#define CS12               2
#define WGM12              3
#define WGM13              4
#define ICES1              6
#define ICNC1              7

// Timer/Counter1
#define TCNT1_u16          (*(volatile u16*)0x4C)

// Output Compare Register 1 A
#define OCR1A_u16          (*(volatile u16*)0x4A)

// Output Compare Register 1 B
#define OCR1B_u16          (*(volatile u16*)0x48)

// Input Capture Register 1
#define ICR1_u16           (*(volatile u16*)0x46)

// Timer/Counter Interrupt Mask Register
#define TIMSK              (*(volatile u8*)0x59)
#define TOIE1              2
#define OCIE1B             3
#define OCIE1A             4
#define TICIE1             5

// Timer/Counter Interrupt Flag Register
#define TIFR     *((volatile u8 *) 0x58 )
#define TOV1              2
#define OCF1B             3
#define OCF1A             4
#define ICF1              5

//Status Register
// use to GIE enable
#define SREG    *((volatile u8 *)0x5F)
#define GIE     (u8)7

//Special Function IO Register
// use to Reset the pre_scaler of timer0,1
#define SFIOR   *((volatile u8 *)0x50)
#define PSR10   (u8)0




#endif /* TMR1_PRIVATE_H_ */