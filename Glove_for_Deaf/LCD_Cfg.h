/*
 * LCD_Cfg.h
 *
 * Created: 3/5/2022 10:41:46 PM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"

#define LCD_MODE      4


#define LCD_8BIT_CMD_PORT     DIO_PORTC
#define LCD_8BIT_DATA_PORT    DIO_PORTD

#define LCD_4BIT_CMD_PORT     DIO_PORTB
#define LCD_4BIT_DATA_PORT    DIO_PORTA

#define LCD_RS_PIN            DIO_PIN_1
#define LCD_RW_PIN            DIO_PIN_2
#define LCD_E_PIN             DIO_PIN_3

#define LCD_D0                DIO_PIN_0
#define LCD_D1                DIO_PIN_1
#define LCD_D2                DIO_PIN_2
#define LCD_D3                DIO_PIN_3
#define LCD_D4                DIO_PIN_4
#define LCD_D5                DIO_PIN_5
#define LCD_D6                DIO_PIN_6
#define LCD_D7                DIO_PIN_7

#define CLEAR_SCREEN 0x01
#define RETURN_HOME  0x02

#define DECREMENT_CURSOR 0x01
#define INCREMENT_CURSOR 0x01

#define SHIFT_DISPLAY_RIGHT 0x01
#define SHIFT_DISPLAY_LEFT  0x01

#define DISPLAY_OFF_CURSOR_OFF     0x08
#define DISPLAY_OFF_CURSOR_ON      0x0A
#define DISPLAY_ON_CURSOR_OFF      0x0C
#define DISPLAY_ON_CURSOR_ON       0x0E
#define DISPLAY_ON_CURSOR_BLINKING 0x0F

#define SHIFT_CURSOR_RIGHT 0x01
#define SHIFT_CURSOR_LEFT  0x01

#define FORCE_CURSOR_TO_BEGINNING_OF_1ST_LINE 0x80
#define FORCE_CURSOR_TO_BEGINNING_OF_2ND_LINE 0xC0

#endif /* LCD_CFG_H_ */