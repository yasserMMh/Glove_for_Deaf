/*
 * ATmega32.h
 *
 * Created: 3/5/2022 9:47:13 AM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/**************************************   DIO Registers  ******************************************/
#define  PINA   *((volatile Uint8*)(0x39))
#define  DDRA   *((volatile Uint8*)(0x3A))
#define  PORTA  *((volatile Uint8*)(0x3B))

#define  PINB   *((volatile Uint8*)(0x36))
#define  DDRB   *((volatile Uint8*)(0x37))
#define  PORTB  *((volatile Uint8*)(0x38))

#define  PINC   *((volatile Uint8*)(0x33))
#define  DDRC   *((volatile Uint8*)(0x34))
#define  PORTC  *((volatile Uint8*)(0x35))

#define  PIND   *((volatile Uint8*)(0x30))
#define  DDRD   *((volatile Uint8*)(0x31))
#define  PORTD  *((volatile Uint8*)(0x32))
/***************************************************************************************************/

/*******************************   External Interrupt Registers  ***********************************/
#define SREG   *((volatile Uint8*)(0x5F))

#define GICR   *((volatile Uint8*)(0x5B))

#define GIFR   *((volatile Uint8*)(0x5A))

#define MCUCR  *((volatile Uint8*)(0x55))

#define MCUCSR *((volatile Uint8*)(0x54))
/***************************************************************************************************/

/**************************************   ADC Registers  ******************************************/
#define ADMUX       (*(volatile Uint8 *)(0x27))
#define ADCSRA      (*(volatile Uint8 *)(0x26))
#define ADCH        (*(volatile Uint8 *)(0x25))
#define ADCL        (*(volatile Uint8 *)(0x24))
#define ADC_Adjust	(*(volatile Uint16*)(0x24))
#define SFIOR       (*(volatile Uint8 *)(0x50))
/***************************************************************************************************/

/**************************************   Timer 0  ******************************************/
#define TCNT0  (*(volatile Uint8*)(0x52))
#define TCCR0  (*(volatile Uint8*)(0x53))
#define OCR0   (*(volatile Uint8*)(0x5C))
#define TIMSK  (*(volatile Uint8*)(0x59))
#define TIFR   (*(volatile Uint8*)(0x58))
/***************************************************************************************************/

/**************************************   Timer 1  ******************************************/
#define TCCR1A  (*(volatile Uint8*)(0x4F))
#define TCCR1B  (*(volatile Uint8*)(0x4E))
#define OCR1A   (*(volatile Uint8*)(0x4A))
/***************************************************************************************************/


#endif /* ATMEGA32_H_ */