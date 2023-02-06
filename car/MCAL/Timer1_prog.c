

#include "Timer1_interface.h"

static u8 top = 0;

// static void Timer1_SetFastPWM()
// {
// 
// 	// Set Fast PWM, TOP in ICR1, Clear OC1A on compare match
// 	TCCR1A_REG = (1<<1)|(1<<7);
// 	TCCR1B_REG = (1<<3)|(1<<4);
// 
// 	TCNT1L_REG = 0;
// 	TCNT1H_REG = 0;
// 
// 	// Set DDR as output
// 	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
// 
// }

void PWM1_Init(void)
{
	DDRD |= 0x20; //OC1A output
	
	TCCR1A |= 0x02 ; //Select Mode 14
	TCCR1B |= 0x18;
	
	ICR1 = 625; // Set Top
	
}

void PWM1_Start(void)
{
	TCCR1B |= 0x04; // select 256 presc
}

void PWM1_SetDutyCycle(u8 Duty_Cycle)
{
	OCR1A = ((Duty_Cycle * 625) / 100) - 1;
}

void Timer1_Init(void)
{

// 	Global Interrupt
// 			GIE_EnableGlobalInterrupt();
// 		
// 			// Select Mode (waveform)
// 			switch(waveform)
// 			{
// 		
// 				//	case TIMER1_NORMAL:
// 				//		Timer1_SetNormal();
// 				//		break;
// 				//	case TIMER1_PWM_PHASE_CORRECT:
// 				//		Timer1_SetPWMPhaseControl();
// 				//		break;
// 				//	case TIMER1_CTC:
// 				//		Timer1_SetCTC();
// 				//		break;
// 		
// 				case TIMER1_FAST_PWM:
// 				Timer1_SetFastPWM();
// 				break;

SET_BIT(TCCR1B , 3 ); //Select CTC mode
SET_BIT(TIMSK , 4); //Enable Tmer1 Compare Match Interrupt
SET_BIT(SREG,7);//Enable Global Interrupt

	}



void Timer1_Start(void)
{

	// Clock select (Prescaler)
	//TCCR1B_REG |= clockSelect;
	TCCR1B_REG |= 0x05;

}

void Timer1_Stop(void)
{

// 	Stop Timer/Counter by clearing prescaler
// 		TCCR1B_REG &= 0xf8;
	
	CLR_BIT(TCCR1B_REG,0);
	CLR_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);

}


// For PWM Modes
void Timer1_SetDuty(u32 dutyPercentage)
{
//     u16 tmp = (top * ((f32_t) dutyPercentage / 100));
//     OCR1AL_REG = tmp;
//     OCR1AH_REG = tmp << 8;

	u8 Tick_Time = 1024/16 ;
	u32 Num_Ticks = (dutyPercentage * 1000) / Tick_Time;
	OCR1A = Num_Ticks - 1;

}

void Timer1_SetFrequency(u8 frequency)
{

	top = ( (16000000) / (frequency * 64) ) - 1;

	ICR1L_REG = top;
	ICR1H_REG = top << 8;

}

