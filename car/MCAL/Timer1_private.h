

#ifndef SOURCE_01_MCAL_TIMER1_INC_TIMER1_PRIVATE_H_
#define SOURCE_01_MCAL_TIMER1_INC_TIMER1_PRIVATE_H_

#include "STD_TYPES.h"

// Time/counter control reg
#define TCCR1A_REG	(*(volatile u8* )(0x4F))
// Timer/Counter Reg   
#define TCCR1B_REG	 (*(volatile u8* )(0x4E))
// Output compare reg  
#define OCR1AH_REG	(*(volatile u8* )(0x4B))
#define OCR1AL_REG	(*(volatile u8* )(0x4A))
#define ICR1H_REG	(*(volatile u8* )(0x47))
#define ICR1L_REG	(*(volatile u8* )(0x46))
					  
#define TCNT1H_REG	(*(volatile u8* )(0x4D))
#define TCNT1L_REG	(*(volatile u8* )(0x4C))
 
//-----TCCR0-------------
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

//---------TIMSK--------------
#define OCIE0 1
#define TOIE0  0

/*
 * TIMER1_MODE_NONE
 * TIMER1_MODE_NORMAL
 * TIMER1_MODE_PWM_PHASE_CONTROL
 * TIMER1_MODE_CTC
 * TIMER1_MODE_FAST_PWM
 * */

#define TIMER1_MODE_NONE
#define TIMER1_MODE_NORMAL
#define TIMER1_MODE_PWM_PHASE_CONTROL
#define TIMER1_MODE_CTC
#define TIMER1_MODE_FAST_PWM

#define TIMER1_MODE_SELECTED	TIMER1_MODE_NONE

#endif /* SOURCE_01_MCAL_TIMER1_INC_TIMER1_PRIVATE_H_ */
