/*
 * ADC.h
 *
 * Created: 3/25/2022 10:44:59 AM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_Cfg.h"
#include "math_bits.h"
#include "STD_TYPES.h"
#include "ATmega32.h"

#define ADC_VOLTAGE_REFERENCE_VCC			0
#define ADC_VOLTAGE_REFERENCE_AREF			1
#define ADC_VOLTAGE_REFERENCE_INTERNAL		2

#define ADC_CHANNEL_01		0
#define ADC_CHANNEL_02		1
#define ADC_CHANNEL_03		2
#define ADC_CHANNEL_04		3
#define ADC_CHANNEL_05		4
#define ADC_CHANNEL_06		5
#define ADC_CHANNEL_07		6
#define ADC_CHANNEL_08		7

#define ADC_PRESCALER_128	0

#define ADC_CONVERSION_AUTO_TRIGGER		0

#define ADC_INTERRUPT_DISABLED			0

#define ADC_LEFT_ADJUST			0
#define ADC_RIGHT_ADJUST		1

void ADC_Init(void);

void ADC_Select_Channel(Uint8 channel);

Uint16 ADC_ReadAnalogValue(void);


#endif /* ADC_H_ */