

#include "Servo_Motor.h"

// void ServoMotor_Initialization(void)
// {
// // 	Define Direction of OC1A
// // 		SET_BIT(DDRD, PD5);
// // 		//Choose mode of the timer (Input capture mode)
// // 		SET_BIT(TCCR1B, WGM13);SET_BIT(TCCR1B, WGM12);SET_BIT(TCCR1A, WGM11);CLR_BIT(TCCR1A, WGM10);
// // 		//Choose non-inverting mode
// // 		SET_BIT(TCCR1A, COM1A1);CLR_BIT(TCCR1A, COM1A0);
// // 		//Choose pre-scaler
// // 		SET_BIT(TCCR1B, CS12);CLR_BIT(TCCR1B, CS11);CLR_BIT(TCCR1B, CS10);
// // 		//Set new value for top
// // 		ICR1 = 1250;
// 	
// }
// void ServoMotor_Rotate(u8 angle)
// {
// 	//OCR1A = ((angle * ICR1) / 100) - 1;
// 	
// }
#include "Servo.h"

void Servo_Init(void)
{
	PWM1_Init();
	PWM1_Start();
}

void Servo_SetDegree(u8 Degree)
{
	u16 duty_cycle = 0;
	
	duty_cycle = 5 + (Degree / 36);
	
	PWM1_SetDutyCycle(duty_cycle);
}