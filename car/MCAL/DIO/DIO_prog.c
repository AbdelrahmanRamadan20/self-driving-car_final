/*
 * DIO_private.h
 *
 * Created: 2/1/2023 3:38:58 AM
 *  Author: abdelrahman
 */


#include "DIO_interface.h"

void DIO_SetPinDirection(PORT_TYPE port ,PIN_TYPE pin , DIR_TYPE dir){
	switch (dir)
	{
		case DIO_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}

void DIO_SetPinValue(PORT_TYPE port ,PIN_TYPE pin, IO_TYPE val ){
	
	
	switch(port){
		case DIO_PORTA :
		(val==DIO_HIGH)?  SET_BIT(PORTA,pin):CLR_BIT(PORTA,pin) ;
		break;
		case DIO_PORTB :
		(val==DIO_HIGH)?  SET_BIT(PORTB,pin):CLR_BIT(PORTB,pin) ;
		break;
		
		case DIO_PORTC:
		(val==DIO_HIGH)?  SET_BIT(PORTC,pin):CLR_BIT(PORTC,pin) ;
		break;
		case DIO_PORTD:
		(val==DIO_HIGH)?  SET_BIT(PORTD,pin):CLR_BIT(PORTD,pin) ;
		break;
	}
}


// IO_TYPE DIO_GetPinValue(PORT_TYPE port ,PIN_TYPE pin ){
// 	switch(port){
// 		case DIO_PORTA :    return GET_BIT(PINA,pin);
// 		case DIO_PORTB :    return GET_BIT(PINB,pin);
// 		case DIO_PORTC :    return GET_BIT(PINC,pin);
// 		case DIO_PORTD :    return GET_BIT(PIND,pin);
// 		
// 	}
// }



void DIO_TogglePinValue(PORT_TYPE port ,PIN_TYPE pin){
	
	
	switch (port)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA,pin) ;
		break;
		
		case DIO_PORTB:
		TOG_BIT(PORTB,pin) ;
		break;
		
		case DIO_PORTC:
		TOG_BIT(PORTC,pin) ;
		break;
		
		case DIO_PORTD:
		TOG_BIT(PORTD,pin) ;
		break;
	}
	
	
	
}


void DIO_SetPortDirection(u8 Port , u8 Dir)
{


	switch(Port)
	{

		case DIO_PORTA :

		DDRA = Dir;

		break;

		case DIO_PORTB :

		DDRB = Dir;

		break;

		case DIO_PORTC :

		DDRC = Dir;

		break;

		case DIO_PORTD :

		DDRD = Dir;

		break;

		default:
		break;
	}

}











void DIO_WritePort(u8 Port , u8 Val)
{

	switch (Port)
	{
		case DIO_PORTA :

		PORTA = Val;

		break;

		case DIO_PORTB :

		PORTB = Val;

		break;

		case DIO_PORTC :

		PORTB = Val;

		break;

		case DIO_PORTD :

		PORTD = Val;

		break;

		default:
		break;
	}

}









void DIO_ReadPort(u8 Port , u8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :

		*Val = PINA;

		break;

		case DIO_PORTB :

		*Val = PINB;

		break;

		case DIO_PORTC :

		*Val = PINC;

		break;

		case DIO_PORTD :

		*Val = PIND;

		break;

		default:
		break;
	}

}





void DIO_ReadPin (u8 Port ,u8 Pin, u8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :

		*Val =  GET_BIT(PINA,Pin);

		break;

		case DIO_PORTB :

		*Val = GET_BIT(PINB,Pin);

		break;

		case DIO_PORTC :

		*Val = GET_BIT(PINC,Pin);

		break;

		case DIO_PORTD :

		*Val = GET_BIT(PIND,Pin);

		break;

		default:
		break;
	}

}



void DIO_SetPullUp(u8 Port ,u8 Pin )
{
	switch(Port)
	{

		case DIO_PORTA :

		SET_BIT(PORTA,Pin);

		break;

		case DIO_PORTB :

		SET_BIT(PORTB,Pin);

		break;

		case DIO_PORTC :

		SET_BIT(PORTC,Pin);

		break;

		case DIO_PORTD :

		SET_BIT(PORTD,Pin);

		break;

		default:
		break;
	}
}