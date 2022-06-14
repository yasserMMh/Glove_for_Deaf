/*
 * ADC.c
 *
 * Created: 3/25/2022 11:44:51 AM
 *  Author: Ali
 */ 

#include  "ADC.h"



void ADC_Init(void)
{
	#if ADC_VOLTAGE_REFRENCE == ADC_VREF_VCC
        SET_BIT(ADMUX , 6);
        CLR_BIT(ADMUX , 7);
		
    #endif
	
   #if ADC_CHANNEL == ADC_CHANNEL_1
	 SET_BIT(ADMUX , 0);
	
   #endif
	
   #if ADC_CONVERSION_TRIGGER ==  ADC_CONVERSION_AUTO_TRIGGER
     SET_BIT(ADCSRA , 5);
   #endif
   
   #if ADC_PRESCALER      ==     ADC_PRESCALER_128
SET_BIT(ADCSRA , 0);
SET_BIT(ADCSRA , 1);
SET_BIT(ADCSRA , 2);
  #endif
  
  #if ADC_INTERRUPT_STATUS  ==  ADC_INTERRUPT_DISABLED
     CLR_BIT(ADCSRA , 3);
    
  #endif
	 
  #if ADC_ADJUST        ==      ADC_RIGHT_ADJUCT
	   CLR_BIT(ADMUX , 5);
  #endif
	
	SET_BIT(ADCSRA , 7); //Enable ADC
}

void ADC_Select_Channel(uint8 channel)
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
		
		case 12:
		CLR_BIT(ADMUX, 0);
		CLR_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		CLR_BIT(ADMUX, 3);
		SET_BIT(ADMUX, 4);
		break;
		
		case 34:
		SET_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		CLR_BIT(ADMUX, 2);
		SET_BIT(ADMUX, 3);
		SET_BIT(ADMUX, 4);
		break;
		
		default:
		break;
	}
}

uint16  ADC_ReadAnalogValue(void)
{
	uint16  Digital_Value = 0;
	uint16  V_Input = 0;
	
	SET_BIT(ADCSRA , 6);   // Start Conversion
	
	while(! (GET_BIT(ADCSRA , 4))); //wait till end of conversion
	
	Digital_Value = ADC_Adjust;
	
	V_Input = (Digital_Value * 50) / 1024 ;
	
	return V_Input;
	
}