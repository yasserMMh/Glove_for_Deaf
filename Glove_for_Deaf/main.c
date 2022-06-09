/*
 * Glove_for_Deaf.c
 *
 * Created: 6/8/2022 8:07:04 PM
 * Author : Yasser & Mahmoud
 */ 

//#include <avr/io.h>

#include "ADC.h"
#include "LCD.h"

int main(void)
{
	Uint32 finger1, finger2, finger3, finger4, finger5;
	
	LCD_Init();
	ADC_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		finger1 = FlexSensor_Read(0);
		finger2 = FlexSensor_Read(1);
		finger3 = FlexSensor_Read(2);
		finger4 = FlexSensor_Read(3);
		finger5 = FlexSensor_Read(4);
		
		FlexSensor_Set_Word(finger1, finger2, finger3, finger4, finger5);
    }
}

