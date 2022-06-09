/*
 * DIO.c
 *
 * Created: 3/5/2022 11:05:11 AM
 *  Author: Yasser & Mahmoud
 */ 

#include "DIO.h"

void DIO_SetPinDir(Uint8 Port, Uint8 Pin, Uint8 Dir)
{
	switch(Dir)
	{
		case DIO_PIN_DIR_OUTPUT:
		switch(Port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, Pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(DDRB, Pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(DDRC, Pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(DDRD, Pin);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PIN_DIR_INPUT:
		switch(Port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, Pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(DDRB, Pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(DDRC, Pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(DDRD, Pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}
void DIO_SetPortDir(Uint8 Port, Uint8 Dir)
{
	switch(Port)
	{
		case DIO_PORTA:
		DDRA = Dir;
		break;
		
		case DIO_PORTB:
		DDRB = Dir;
		break;
		
		case DIO_PORTC:
		DDRC = Dir;
		break;
		
		case DIO_PORTD:
		DDRD = Dir;
		break;
		
		default:
		break;
	}
}

void DIO_SetPinVal(Uint8 Port, Uint8 Pin, Uint8 Val)
{
	switch(Val)
	{
		case DIO_PIN_HIGH:
		switch(Port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, Pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB, Pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC, Pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD, Pin);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PIN_LOW:
		switch(Port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, Pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(PORTB, Pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(PORTC, Pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(PORTD, Pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}
void DIO_SetPortVal(Uint8 Port, Uint8 Val)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA = Val;
		break;
		
		case DIO_PORTB:
		PORTB = Val;
		break;
		
		case DIO_PORTC:
		PORTC = Val;
		break;
		
		case DIO_PORTD:
		PORTD = Val;
		break;
		
		default:
		break;
	}
}

Uint8 DIO_ReadPinVal(Uint8 Port, Uint8 Pin)
{
	Uint8 Val = 0;
	
	switch(Port)
	{
		case DIO_PORTA:
		Val = GET_BIT(PINA, Pin);
		break;
		
		case DIO_PORTB:
		Val = GET_BIT(PINB, Pin);
		break;
		
		case DIO_PORTC:
		Val = GET_BIT(PINC, Pin);
		break;
		
		case DIO_PORTD:
		Val = GET_BIT(PIND, Pin);
		break;
		
		default:
		break;
	}
	
	return Val;
}
Uint8 DIO_ReadPortVal(Uint8 Port)
{
	Uint8 Val = 0;
	
	switch(Port)
	{
		case DIO_PORTA:
		Val = PORTA;
		break;
		
		case DIO_PORTB:
		Val = PORTB;
		break;
		
		case DIO_PORTC:
		Val = PORTC;
		break;
		
		case DIO_PORTD:
		Val = PORTD;
		break;
		
		default:
		break;
	}
	
	return Val;
}

void DIO_SetPullUP(Uint8 Port, Uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, Pin);
		break;
		
		case DIO_PORTB:
		SET_BIT(PORTB, Pin);
		break;
		
		case DIO_PORTC:
		SET_BIT(PORTC, Pin);
		break;
		
		case DIO_PORTD:
		SET_BIT(PORTD, Pin);
		break;
		
		default:
		break;
	}
}
void DIO_TogglePin(Uint8 Port, Uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		TOGGLE_BIT(PORTA, Pin);
		break;
		
		case DIO_PORTB:
		TOGGLE_BIT(PORTB, Pin);
		break;
		
		case DIO_PORTC:
		TOGGLE_BIT(PORTC, Pin);
		break;
		
		case DIO_PORTD:
		TOGGLE_BIT(PORTD, Pin);
		break;
		
		default:
		break;
	}
}
