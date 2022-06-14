/*
 * ADC.h
 *
 * Created: 3/25/2022 11:44:15 AM
 *  Author: Ali
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_Cfg.h"
#include "BIT_Math.h"
#include "STD.h"
#include "ATMEGA32_Regs.h"



#define   ADC_VREF_VCC                  0
#define   ADC_VREF_AREF                 1
#define   ADC_VREF_INTERNAL             2

#define  ADC_CHANNEL_1                  1

#define  ADC_PRESCALER_128              1

#define ADC_CONVERSION_AUTO_TRIGGER     1

#define ADC_INTERRUPT_DISABLED          1

#define ADC_LEFT_ADJUCT                 0
#define ADC_RIGHT_ADJUCT                0


void ADC_Init(void);
void ADC_Select_Channel(uint8 channel);
uint16  ADC_ReadAnalogValue(void);



#endif /* ADC_H_ */