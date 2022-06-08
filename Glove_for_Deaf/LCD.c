/*
 * LCD.c
 *
 * Created: 3/5/2022 10:42:02 PM
 *  Author: Arrow
 */ 

#include "LCD.h"

void LCD_Init(void)
{
	#if   LCD_MODE == 8
	DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_DIR_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT, DIO_PORT_DIR_OUTPUT);
	
	_delay_ms(100);
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0E);
	LCD_WriteCommand(0x01);
	_delay_ms(20);
	
	#elif LCD_MODE == 4
	DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_DIR_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D4, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D5, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D6, DIO_PIN_DIR_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D7, DIO_PIN_DIR_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x33); // 4 bit mode
	LCD_WriteCommand(0x32); // 4 bit mode
	LCD_WriteCommand(0x28); // 4 bit mode
	LCD_WriteCommand(0x0C); // display on, cursor off
	LCD_WriteCommand(0x01); // clear LCD
	LCD_WriteCommand(0x06); // shift cursor to right
	LCD_WriteCommand(0x02); // return home
	_delay_ms(20);
	#endif
}
void LCD_WriteCommand(Uint8 cmd)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT, LCD_E_PIN,  DIO_PIN_LOW);
	
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F); // send high bits
	DIO_SetPinVal(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_LOW);
	
	PORTA = (cmd << 0x04) | (PORTA & 0x0F); // send low bits
	DIO_SetPinVal(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_LOW);
	_delay_ms(5);
}
void LCD_WriteChar(Uint8 data)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_RS_PIN ,DIO_PIN_HIGH);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_RW_PIN ,DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_LOW);
	
	PORTA = (data & 0xF0) | (PORTA & 0X0F);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_LOW);
	
	PORTA = (data << 0x04) | (PORTA & 0X0F);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,DIO_PIN_LOW);
	
	_delay_ms(5);
}
void LCD_Goto(Uint8 row, Uint8 col)
{
	Uint8 pos[2] = {0x80 , 0xC0};
	
	LCD_WriteCommand(pos[row]+col);
}
void LCD_WriteString(Uint8* data)
{
	Uint8 i = 0;
	while(data[i] != '\0')
	{
		LCD_WriteChar(data[i]);
		i++;
	}
}
void LCD_WriteInteger(Sint32 data)
{
	Sint32 y = 1;

	if(data < 0)
	{
		LCD_WriteChar('-');
		data *= -1;
	}

	while(data > 0)
	{
		y = ((y*10) + (data%10));
		data /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
}


void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}