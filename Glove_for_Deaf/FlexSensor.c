/*
 * FlexSensor.c
 *
 * Created: 6/8/2022 8:15:08 PM
 *  Author: Yasser & Mahmoud
 */ 

#include "FlexSensor.h"

void FlexSensor_Init(void)
{
	ADC_Init();
}

uint16 FlexSensor_Read(uint8 channel)
{
	ADC_Select_Channel(channel);
	
	uint16 V_Input = 0;
	uint16 res = 0;
	
	V_Input = ADC_ReadAnalogValue();
	
	res = V_Input / 1;
	
	if(channel == 0 || channel == 1 || channel == 2 || channel == 3 || channel == 4) res /= 10;
	
	return res;
}

void FlexSensor_Set_Word(uint16 finger1, uint16 finger2, uint16 finger3, uint16 finger4, uint16 finger5)
{
	LCD_Clear();
	
	if(finger1 > 3 )
	{
		uint8* word1 = "stop";
		LCD_WriteString(word1);
	}
	else if(finger2 > 3)
	{
		uint8* word2 = "hi";
		LCD_WriteString(word2);
	}
	else if(finger3 > 3)
	{
		uint8* word3 = "welcome";
		LCD_WriteString(word3);
	}
	else if(finger4 > 3)
	{
		uint8* word4 = "go";
		LCD_WriteString(word4);
	}
	else if(finger5 > 3)
	{
		uint8* word5 = "return";
		LCD_WriteString(word5);
	}
	else if(finger1 > 2)
	{
		uint8* word6 = "love";
		LCD_WriteString(word6);
	}
	else if(finger2 > 2)
	{
		uint8* word7 = "ok";
		LCD_WriteString(word7);
	}
	else if(finger3 > 2)
	{
		uint8* word8 = "where";
		LCD_WriteString(word8);
	}
	else if(finger4 > 2)
	{
		uint8* word9 = "move";
		LCD_WriteString(word9);
	}
	else if(finger5 > 2)
	{
		uint8* word10 = "well";
		LCD_WriteString(word10);
	}
	else if(finger1 > 1)
	{
		uint8* word11 = "you";
		LCD_WriteString(word11);
	}
	else if(finger2 > 1)
	{
		uint8* word12 = "me";
		LCD_WriteString(word12);
	}
	else if(finger3 > 1)
	{
		uint8* word13 = "what";
		LCD_WriteString(word13);
	}
	else if(finger4 > 1)
	{
		uint8* word14 = "when";
		LCD_WriteString(word14);
	}
	else if(finger5 > 1)
	{
		uint8* word15 = "how";
		LCD_WriteString(word15);
	}
}

void FlexSensor_Set_Word_diff_mode(uint16 finger1_2, uint16 finger3_4, uint16 finger5_0)
{
	LCD_Clear();
	
	if(finger1_2 > 45 )
	{
		uint8* word1 = "stop";
		LCD_WriteString(word1);
	}
	else if(finger1_2 > 40)
	{
		uint8* word3 = "welcome";
		LCD_WriteString(word3);
	}
	else if(finger1_2 > 35)
	{
		uint8* word4 = "go";
		LCD_WriteString(word4);
	}
	else if(finger1_2 > 30)
	{
		uint8* word5 = "return";
		LCD_WriteString(word5);
	}
	else if(finger1_2 > 25)
	{
		uint8* word6 = "love";
		LCD_WriteString(word6);
	}
	else if(finger1_2 > 20)
	{
		uint8* word7 = "ok";
		LCD_WriteString(word7);
	}
	else if(finger1_2 > 15)
	{
		uint8* word8 = "where";
		LCD_WriteString(word8);
	}
	else if(finger1_2 > 10)
	{
		uint8* word9 = "move";
		LCD_WriteString(word9);
	}
	else if(finger3_4 > 40)
	{
		uint8* word10 = "well";
		LCD_WriteString(word10);
	}
	else if(finger3_4 > 35)
	{
		uint8* word11 = "you";
		LCD_WriteString(word11);
	}
	else if(finger3_4 > 30)
	{
		uint8* word12 = "me";
		LCD_WriteString(word12);
	}
	else if(finger3_4 > 25)
	{
		uint8* word13 = "what";
		LCD_WriteString(word13);
	}
	else if(finger3_4 > 15)
	{
		uint8* word14 = "when";
		LCD_WriteString(word14);
	}
	else if(finger5_0 > 3)
	{
		uint8* word15 = "how";
		LCD_WriteString(word15);
	}
	else if(finger5_0 > 2)
	{
		uint8* word2 = "hi";
		LCD_WriteString(word2);
	}
}
