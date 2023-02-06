/*
 * DIO_Configurations.h
 *
 * Created: 2/1/2023 4:15:32 AM
 *  Author: abdel
 */ 




#ifndef DIO_CONFIGURATIONS_H_
#define DIO_CONFIGURATIONS_H_
//Include configuration library (IO, Delay, Interrupt, BitMath, StdTypes)
#include "Configuration.h"
//Define Port type
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}PORT_TYPE;
//Define Pin type
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}PIN_TYPE  ;
//Define State type
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}DIR_TYPE;
//Define Status type
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}IO_TYPE ;
//Define Boolean type
typedef enum
{
	FALSE = 0,
	TRUE = 1
}boolean;




#endif /* DIO_CONFIGURATIONS_H_ */