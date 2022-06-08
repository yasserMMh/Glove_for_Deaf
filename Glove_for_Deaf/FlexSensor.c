/*
 * FlexSensor.c
 *
 * Created: 6/8/2022 8:15:08 PM
 *  Author: yasser & Mahmoud
 */ 

#include "FlexSensor.h"

void FlexSensor_Init(void)
{
	ADC_Init();
}

Uint8 FlexSensor_Read(Uint8 channel)
{
	ADC_Select_Channel(channel);
	
	Uint8 V_Input = 0;
	Uint8 result = 0;
	
	V_Input = ADC_ReadAnalogValue();
	
	result = V_Input * 5;
	
	return result;
}

void FlexSensor_Set_Word(Uint16 finger1, Uint16 finger2, Uint16 finger3, Uint16 finger4, Uint16 finger5)
{
	LCD_Clear();
	
	if(finger1 > 2.5 && finger2 > 2.5 && finger3 > 2.5 && finger4 > 2.5 && finger5 > 2.5)
	{
		Uint8* word1 = "stop";
		LCD_WriteString(word1);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word2 = "one";
		LCD_WriteString(word2);
	}
	else if(finger1 > 2.5 && finger2 > 2.5 && finger3 < 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word3 = "two";
		LCD_WriteString(word3);
	}
	else if(finger1 > 2.5 && finger2 > 2.5 && finger3 > 2.5 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word4 = "three";
		LCD_WriteString(word4);
	}
	else if(finger1 > 2.5 && finger2 > 2.5 && finger3 > 2.5 && finger4 > 2.5 && finger5 < 0.1)
	{
		Uint8* word5 = "four";
		LCD_WriteString(word5);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 < 0.1 && finger5 > 2.5)
	{
		Uint8* word6 = "love";
		LCD_WriteString(word6);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 > 2.5 && finger5 < 0.1)
	{
		Uint8* word7 = "ok";
		LCD_WriteString(word7);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 > 2.5 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word8 = "where";
		LCD_WriteString(word8);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word9 = "move";
		LCD_WriteString(word9);
	}
	else if(finger1 < 0.1 && finger2 < 2 && finger3 < 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word10 = "well";
		LCD_WriteString(word10);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 > 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word11 = "you";
		LCD_WriteString(word11);
	}
	else if(finger1 > 0.3 && finger2 > 2.5 && finger3 < 0.1 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word12 = "me";
		LCD_WriteString(word12);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 > 1.2 && finger4 < 0.1 && finger5 < 0.1)
	{
		Uint8* word13 = "what";
		LCD_WriteString(word13);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 > 2 && finger5 < 0.1)
	{
		Uint8* word14 = "when";
		LCD_WriteString(word14);
	}
	else if(finger1 < 0.1 && finger2 > 2.5 && finger3 < 0.1 && finger4 > 0.3 && finger5 < 0.1)
	{
		Uint8* word15 = "how";
		LCD_WriteString(word15);
	}
}