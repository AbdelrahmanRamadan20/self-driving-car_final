
#include "LCD_interface.h"
// #include <stdio.h>
// #include <math.h>
/*
* LCD_prog.c
*
* Created: 2/5/2023 3:42:23 PM
*  Author: abdelrahman
*/

void LCD_init(){
	DIO_SetPinDirection(LCD_CMD_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CMD_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_CMD_PORT,LCD_E_PIN,DIO_OUTPUT);
	
	DIO_SetPinDirection(LCD_DATA_PORT,LCD_D4_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT,LCD_D5_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT,LCD_D6_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT,LCD_D7_PIN,DIO_OUTPUT);
	
	_delay_ms(15);
	LCD_Write_CMD(0x33);
	_delay_ms(1);
	LCD_Write_CMD(0x32);
	_delay_ms(1);
	LCD_Write_CMD(LCD_INITIAL_FUNCTION_SET);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Display_ON_Cursor_Blink_OFF);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Clear_Display);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Return_Home);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(1);
	
	
	
}
void LCD_Write_CMD(u8 CMD){
	
	
	DIO_SetPinValue(LCD_CMD_PORT,LCD_RS_PIN,DIO_LOW);	 //SELECT INSTRUCTION REGISTER
	DIO_SetPinValue(LCD_CMD_PORT,LCD_RW_PIN,DIO_LOW);	 // SELECT WRITING OPERATION
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);	 //INITIAL VALUE OF ENABLE PIN
	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_HIGH);	 // SET E PIN TO HIGH TO  START WRITING DATA
	
	//SELECT PORT ACCORDING TO CONFIG PARAMETER AT LCD_CONFIG.H FILE
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CMD & 0xF0) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CMD & 0xF0) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CMD & 0xF0) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CMD & 0xF0) | (PORTD & 0x0F) ;
	
	#endif
	// MAKING A FALING EADGE AT E PIN TO TRIGER MPU TO GET DATA FROM DATA PORT
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);

	_delay_ms(2);
	
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CMD <<4) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CMD <<4) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CMD <<4) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CMD <<4) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);
	
	_delay_ms(1);
	
	
	
	
	
	
	
}
void LCD_Write_CHAR(u8 CHR){
	
	
	
	DIO_SetPinValue(LCD_CMD_PORT,LCD_RS_PIN,DIO_HIGH);	// SELECT DATA REG
	DIO_SetPinValue(LCD_CMD_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CHR & 0xF0) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CHR & 0xF0) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CHR & 0xF0) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CHR & 0xF0) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);

	_delay_ms(2);
	
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CHR <<4) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CHR <<4) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CHR <<4) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CHR <<4) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinValue(LCD_CMD_PORT,LCD_E_PIN,DIO_LOW);
	
	_delay_ms(1);
	
	
	
	
	
}




void LCD_GOTO( u8 row, u8 col){
	
	
	if(row==0)
	LCD_Write_CMD   (   LCD_Line1_1stAddress + col );
	else if (row==1)
	LCD_Write_CMD   (   LCD_Line2_1stAddress + col  );
	
	
	
	
	
}



void  LCD_Write_STR(const u8 * str){
	
	while(*str != '\0'){
		
		LCD_Write_CHAR(*str);
		str++;
		
		
	}
	
	
}




// void reverse(char* str, int len)
// {
// 	int i = 0, j = len - 1, temp;
// 	while (i < j) {
// 		temp = str[i];
// 		str[i] = str[j];
// 		str[j] = temp;
// 		i++;
// 		j--;
// 	}
// }
// int intToStr(int x, char str[], int d)
// {
// 	int i = 0;
// 	while (x) {
// 		str[i++] = (x % 10) + '0';
// 		x = x / 10;
// 	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
// 	while (i < d)
// 	str[i++] = '0';
// 	
// 	reverse(str, i);
// 	str[i] = '\0';
// 	return i;
// }
// void ftoa(float n, char* res, int afterpoint)
// {
// 	// Extract integer part
// 	int ipart = (int)n;
// 	
// 	// Extract floating part
// 	float fpart = n - (float)ipart;
// 	
// 	// convert integer part to string
// 	int i = intToStr(ipart, res, 0);
// 	
// 	// check for display option after point
// 	if (afterpoint != 0) {
// 		res[i] = '.'; // add dot
// 		
// 		// Get the value of fraction part upto given no.
// 		// of points after dot. The third parameter
// 		// is needed to handle cases like 233.007
// 		fpart = fpart * pow(10, afterpoint);
// 		
// 		intToStr((int)fpart, res + i + 1, afterpoint);
// 	}
// }
// void LCD_Initialization(void)
// {
// 	/*Define direction for control pins*/
// 	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS, LCD_OUT);
// 	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RW, LCD_OUT);
// 	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN, LCD_OUT);
// 	/*Define direction for data pins*/
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D4, LCD_OUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D5, LCD_OUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D6, LCD_OUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_D7, LCD_OUT);
// 	/*Define commands needed to choose 4Bit mode*/
// 	LCD_Write_Command(BITSequence1);/*Define working in 4BIT mode*/
// 	LCD_Write_Command(BITSequence2);/*Define working in 4BIT mode*/
// 	LCD_Write_Command(BITSequence3);/*Use 4BIT mode*/
// 	LCD_Write_Command(ReturnHome);/*Return home*/
// 	LCD_Write_Command(DisplayON);/*Display ON, Cursor OFF*/
// 	LCD_Write_Command(ClearScreen);/*Clear screen*/
// 	LCD_Write_Command(IncrementRight);/*Increment cursor right*/
// 
// }
void LCD_Clear(void)
{
	LCD_Write_Command(ClearScreen);
}
void LCD_Write_Command(uint8_t command)
{
	/*Register Select pin will select control register*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS, LCD_LOW);
	/*Read/Write pin will be write on LCD*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RW, LCD_LOW);
	/*Be sure that enable is disabled*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Send high nipple of the command, without changing old PORTA pins(0-3)*/
	PORTA = (command & 0xF0) | (PORTA & 0x0F);
	/*Send High pulse for 1 millisecond*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Send low nipple of the command, without changing old PORTA pins(0-3)*/
	PORTA = (command << 4) | (PORTA & 0x0F);
	/*Send High pulse for 1 millisecond*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Wait controller to finish command*/
	_delay_ms(5);
}
void LCD_Write_Character(uint8_t character)
{
	/*Register Select pin will select data register*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS, LCD_HIGH);
	/*Read/Write pin will be write on LCD*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RW, LCD_LOW);
	/*Be sure that enable is disabled*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Send high nipple of the command, without changing old PORTA pins(0-3)*/
	PORTA = (character & 0xF0) | (PORTA & 0x0F);
	/*Send High pulse for 1 millisecond*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Send low nipple of the command, without changing old PORTA pins(0-3)*/
	PORTA = (character << 4) | (PORTA & 0x0F);
	/*Send High pulse for 1 millisecond*/
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN, LCD_LOW);
	/*Wait controller to finish command*/
	_delay_ms(5);
}
void LCD_Write_String(uint8_t* str)
{
	while(*str != '\0')
	{
		LCD_Write_Character(*str);
		_delay_ms(10);
		str++;
	}
}
// void LCD_Write_Number(uint32_t number)
// {
// 	uint8_t num[10];
// 	intToStr(number, (uint8_t*)num, 10);//Long To ASCII
// 	LCD_Write_String(num);
// }
// void LCD_Write_Float_Number(f32_t Fnumber)
// {
// 	char num[10];
// 	ftoa(Fnumber, num, 3);//Float to ASCII
// 	LCD_Write_String((uint8_t*)num);
// }
// void LCD_Location(uint8_t row, uint8_t column)
// {
// 	uint8_t location_row0 = 0x80;
// 	uint8_t location_row1 = 0xC0;
// 	switch(row)
// 	{
// 		case 0:
// 		if(column < 16)
// 		{
// 			location_row0 += column;
// 			LCD_Write_Command(location_row0);
// 		}
// 		else
// 		{
// 			LCD_Write_Command(location_row0);
// 		}
// 		break;
// 		case 1:
// 		if(column < 16)
// 		{
// 			location_row1 += column;
// 			LCD_Write_Command(location_row1);
// 		}
// 		else
// 		{
// 			LCD_Write_Command(location_row1);
// 		}
// 		break;
// 		default:
// 		LCD_Write_Command(0x80);//Wrong row number
// 		break;
// 	}
// }

// void LCD_SpecialCharacter(uint8_t* customChatacter, uint8_t length, uint8_t loc[2])
// {
// 	uint8_t iter = 0;
// 	/*Start by write on location 0 in CGRAM*/
// 	LCD_Write_Command(0x40);
// 	/*Write Array will be sent by the user*/
// 	for(iter = 0; iter < length; iter++)
// 	{
// 		LCD_Write_Character(customChatacter[iter]);
// 	}
// 	/*Choose location*/
// 	LCD_Location(loc[0], loc[1]);
// }