/*
 * ADC.c
 *
 * Created: 3/25/2022 10:44:47 AM
 *  Author: Yasser & Mahmoud
 */ 

#include "ADC.h"

void ADC_Init(void)
{
	#if ADC_VOLTAGE_REFERENCE == ADC_VOLTAGE_REFERENCE_VCC
	SET_BIT(ADMUX, 6);
	SET_BIT(ADMUX, 7);
	#elif ADC_VOLTAGE_REFERENCE == ADC_VOLTAGE_REFERENCE_AREF
	#elif ADC_VOLTAGE_REFERENCE == ADC_VOLTAGE_REFERENCE_INTERNAL
	#endif
	
	#if ADC_CONVERSION_TRIGGER == ADC_CONVERSION_AUTO_TRIGGER
	SET_BIT(ADCSRA, 5);
	
	#endif
	
	#if ADC_PRESCALER == ADC_PRESCALER_128
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	
	#endif
	
	#if ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLED
	SET_BIT(ADCSRA, 3);
	#endif
	
	#if ADC_ADJUST == ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX, 5);
	#endif
	
	SET_BIT(ADCSRA, 7);
}

void ADC_Select_Channel(Uint8 channel)
{
	switch(channel)
	{
		case 0:
		CLR_BIT(ADMUX, 0);
		CLR_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		CLR_BIT(ADMUX, 4);
		break;
		
		case 1:
		SET_BIT(ADMUX, 0);
		CLR_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		CLR_BIT(ADMUX, 4);
		break;
		
		case 2:
		CLR_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		CLR_BIT(ADMUX, 4);
		break;
		
		case 3:
		SET_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		CLR_BIT(ADMUX, 4);
		break;
		
		case 4:
		CLR_BIT(ADMUX, 0);
		CLR_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		CLR_BIT(ADMUX, 4);
		break;
		
		default:
		break;
	}
}

Uint16 ADC_ReadAnalogValue(void)
{
	Uint16 digital_value = 0;
	
	SET_BIT(ADCSRA, 6); // start conversion
	
	while(!GET_BIT(ADCSRA, 4)); // wait till end of conversion
	
	digital_value = ADC_Adjust;
	return digital_value;
}