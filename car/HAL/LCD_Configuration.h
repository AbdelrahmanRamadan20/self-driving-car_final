#include "DIO_interface.h"

#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_


#define LCD_CMD_PORT  DIO_PORTB

#define LCD_RS_PIN    PIN1
#define LCD_RW_PIN    PIN2
#define LCD_E_PIN     PIN3

#define LCD_DATA_PORT  DIO_PORTA

#define LCD_D4_PIN  PIN4
#define LCD_D5_PIN  PIN5
#define LCD_D6_PIN  PIN6
#define LCD_D7_PIN  PIN7

#define LCD_INITIAL_FUNCTION_SET       CMD_LCD_4Bit_Mode_2_Line_5X8_FONT


//Ports
#define LCD_DATA_PORT DIO_PORTA//Data port
#define LCD_CTRL_PORT DIO_PORTB//Command port
//Control pins
#define LCD_RS   DIO_PIN1//Register select
#define LCD_RW   DIO_PIN2//Read-Write
#define LCD_EN   DIO_PIN3//Enable
//Data pins
#define LCD_D4   DIO_PIN4
#define LCD_D5   DIO_PIN5
#define LCD_D6   DIO_PIN6
#define LCD_D7   DIO_PIN7
//Output
#define LCD_OUT  DIO_OUTPUT
//State
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

//Commands
#define BITSequence1   0x33
#define BITSequence2   0x32
#define BITSequence3   0x28  //n=1 f=0
#define ReturnHome     0x02
#define DisplayON      0x0C
#define ClearScreen    0x01
#define IncrementRight 0x06

#endif /* LCD_CONFIGURATION_H_ */