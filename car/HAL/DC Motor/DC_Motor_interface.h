

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DC_Motor_Configuration.h"

void Motor_Initialization(void);
void Motor_Start(Motor motor, Motor_Dir direction);
void Motor_Stop(Motor motor);


#endif /* DC_MOTOR_H_ */