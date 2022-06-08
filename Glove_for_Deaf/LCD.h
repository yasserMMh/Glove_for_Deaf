/*
 * LCD.h
 *
 * Created: 3/5/2022 10:41:10 PM
 *  Author: Arrow
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void LCD_Init(void);
void LCD_WriteCommand(Uint8 cmd);
void LCD_WriteChar(Uint8 data);
void LCD_Goto(Uint8 row, Uint8 col);
void LCD_WriteString(Uint8* data);
void LCD_WriteInteger(Sint32 data);
void LCD_Clear(void);


#endif /* LCD_H_ */