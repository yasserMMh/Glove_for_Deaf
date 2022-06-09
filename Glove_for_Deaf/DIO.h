/*
 * DIO.h
 *
 * Created: 3/5/2022 10:59:54 AM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "ATmega32.h"
#include "math_bits.h"
#include "STD_TYPES.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PIN_DIR_INPUT  0
#define DIO_PIN_DIR_OUTPUT 1

#define DIO_PORT_DIR_INPUT  0x00
#define DIO_PORT_DIR_OUTPUT 0xFF

#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

#define DIO_PORT_LOW  0x00
#define DIO_PORT_HIGH 0xFF

void DIO_SetPinDir(Uint8 Port, Uint8 Pin, Uint8 Dir);
void DIO_SetPortDir(Uint8 Port, Uint8 Dir);

void DIO_SetPinVal(Uint8 Port, Uint8 Pin, Uint8 Val);
void DIO_SetPortVal(Uint8 Port, Uint8 Val);

Uint8 DIO_ReadPinVal(Uint8 Port, Uint8 Pin);
Uint8 DIO_ReadPortVal(Uint8 Port);

void DIO_SetPullUP(Uint8 Port, Uint8 Pin);
void DIO_TogglePin(Uint8 Port, Uint8 Pin);



#endif /* DIO_H_ */