

#ifndef SOURCE_01_MCAL_TIMER1_INC_TIMER1_INTERFACE_H_
#define SOURCE_01_MCAL_TIMER1_INC_TIMER1_INTERFACE_H_

#include "Timer1_private.h"
#include "Bit_Math.h"
#include "Timer1_Types.h"
#include "GIE.h"
#include "DIO_interface.h"

void PWM1_Init(void);

void PWM1_Start(void);

void PWM1_SetDutyCycle(u8 Duty_Cycle);

void Timer1_Init(void);
void Timer1_Start(void);
void Timer1_Stop(void);

// For PWM Modes
void Timer1_SetDuty(u32 dutyPercentage);
void Timer1_SetFrequency(u8 frequency);

#endif /* SOURCE_01_MCAL_TIMER1_INC_TIMER1_INTERFACE_H_ */
