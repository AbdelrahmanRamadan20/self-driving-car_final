

#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "Servo_Motor_Configuration.h"
#include "Timer1_interface.h"

// void ServoMotor_Initialization(void);
// void ServoMotor_Rotate(u8 angle);

void Servo_Init(void);

void Servo_SetDegree(u8 Degree);


#endif /* SERVO_MOTOR_H_ */