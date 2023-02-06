/*
 * DIO.h
 *
 * Created: 2/1/2023 4:12:07 AM
 *  Author: abdelrahman
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//#include "DIO_Address.h"
#include "DIO_Configurations.h"

//Prototypes for functions for pin only

void DIO_SetPortDirection(u8 Port , u8 Dir);
void DIO_SetPinDirection (PORT_TYPE port ,PIN_TYPE pin , DIR_TYPE dir);

void DIO_SetPinValue (PORT_TYPE port ,PIN_TYPE pin, IO_TYPE val);

// IO_TYPE DIO_GetPinValue(PORT_TYPE port ,PIN_TYPE pin );
void DIO_TogglePinValue(PORT_TYPE port ,PIN_TYPE pin);

void DIO_WritePort(u8 Port , u8 Val);
void DIO_WritePin(u8 Port ,u8 Pin, u8 Val);

void DIO_ReadPort(u8 Port , u8* Val);
void DIO_ReadPin (u8 Port ,u8 Pin, u8* Val);

void DIO_SetPullUp(u8 Port ,u8 Pin );



#endif /* DIO_INTERFACE_H_ */