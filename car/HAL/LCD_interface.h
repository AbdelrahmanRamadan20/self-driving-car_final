


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_Configuration.h"

#include "DIO_interface.h"
#include "LCD_private.h"


//#define  F_CPU 16000000

#include "util/delay.h"



void LCD_init(void);
void LCD_Write_CMD(u8 CMD);
void LCD_Write_CHAR(u8 CHAR);
void LCD_GOTO( u8 row, u8 col);

void  LCD_Write_STR(const u8* str);

// void LCD_Initialization(void);
 void LCD_Clear(void);
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_Write_String(uint8_t* str);
void LCD_Write_Number(uint32_t number);
//void LCD_Write_Float_Number(f32_t Fnumber);
//void LCD_Location(uint8_t row, uint8_t column);
// void LCD_SpecialCharacter(uint8_t* customChatacter, uint8_t length, uint8_t loc[2]);
#endif /* LCD_INTERFACE_H_ */