

#include "main.h"
#include "Servo_Motor.h"
#define state_forward 1
#define state_backward 2
#define state state_forward

	volatile uint16_t distance_front_the_ultra=0;//variable to get the distance of object front the ultrasonic
	


int main(void)
{
				
	//LCD_Initialization();
	LCD_init();
	////////////////////////////////////////////////////////////////////////ServoMotor_Initialization();
	 Servo_Init();
	 //Servo_SetDegree(90);
	 
	Motor_Initialization();
	LCD_Clear();
	Ultrasonic_Init();
	
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	//ServoMotor_Rotate(Angle_P90);
	PWM1_SetDutyCycle(10);
			while(1){
				
		

			}

	while (1)
	{

		distance_front_the_ultra=Ultrasonic();//to get the distance of object front the ultrasonic=
		LCD_Clear();
		//ServoMotor_Rotate(Angle_0);
		LCD_Write_String((uint8_t*)"distance: ");
		LCD_Write_CMD(distance_front_the_ultra);
		LCD_GOTO(2,2);
		_delay_ms(250);
		

		 		if(distance_front_the_ultra <10 )
		 		{
					 		
		 			Motor_Start(Motor1, Motor_CLK);
					 _delay_ms(20);
		 			Motor_Start(Motor2, Motor_CLK);
					 
					 
		 		}
				else if (distance_front_the_ultra>=10 && distance_front_the_ultra<40)
						{

Motor_Start(Motor2,Motor_CLK);
					 _delay_ms(10);

Motor_Stop(Motor1);


						}
				else if (distance_front_the_ultra >=40 && distance_front_the_ultra <=100)
				 {

					 Motor_Start(Motor1,Motor_CLK);
					 					 _delay_ms(10);

Motor_Stop(Motor2);

				 }
				 else
				 {
					

				 }
							/*//ServoMotor_Rotate(Angle_P90);//rotate the servo 90 degree to the right
							distance_front_the_ultra=Ultrasonic();//to get new value after rotation
		                   if(distance_front_the_ultra>35)
							                    {
													 LCD_Clear();
													 LCD_Write_String((uint8_t*)"right");
								                       Motor_Start(Motor1,Motor_CLK);//move right
													    _delay_ms(150);//////////////////////////////////////////////////////////////
								                       ServoMotor_Rotate(Angle_0);//to return to the initial position
				
				
							                     }
												  else if (distance_front_the_ultra<35)
												   {
													   ServoMotor_Rotate(Angle_N90);//to rotate servo 90 degree to the left
												 	   distance_front_the_ultra=Ultrasonic();//to get new value after rotation
												 	  if (distance_front_the_ultra>35)
												 	  {
												 		   LCD_Clear();
												 		   LCD_Write_String((uint8_t*)"left");
												 		  Motor_Start(Motor1,Motor_CLK);//move left
												 		    _delay_ms(1500);//////////////////////////////////////////////////////////////
												 		  ServoMotor_Rotate(Angle_0);//to return to the initial position
												 	
												 	  }
													  else if (distance_front_the_ultra<35)
													   {
														    LCD_Clear();
														    LCD_Write_String((uint8_t*)"The car rotates 180 degrees");
														   Motor_Start(Motor1, Motor_CLK);
														   Motor_Start(Motor2, Motor_ACLK);//car rotate 180 degrees 
														   _delay_ms(200);
														    Motor_Stop(Motor1);
														    Motor_Stop(Motor2);//stop
														    ServoMotor_Rotate(Angle_0);//to return to the initial position
														    
													    }
														
												   }
						}*/
	}

}

