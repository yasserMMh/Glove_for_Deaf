/*
 * ADC_D27.c
 *
 * Created: 3/25/2022 11:43:29 AM
 * Author : Ali
 */ 

#define F_CPU 16000000
#include <util/delay.h>

#include "FlexSensor.h"
#include "LCD.h"




int main(void)
{

	uint16 finger1 = 0;
	uint16 finger2 = 0;
	uint16 finger3 = 0;
	uint16 finger4 = 0;
	uint16 finger5 = 0;
	
	uint16 finger1_2 = 0;
	uint16 finger3_4 = 0;
	uint16 finger5_0 = 0;
	
	uint8 delay = 300;

    LCD_Init();
	FlexSensor_Init();

    while (1) 
    {
		/*
		finger1 = FlexSensor_Read(0);
		finger2 = FlexSensor_Read(1);
		finger3 = FlexSensor_Read(2);
		finger4 = FlexSensor_Read(3);
		finger5 = FlexSensor_Read(4);
		*/
		
		//FlexSensor_Set_Word(finger1, finger2, finger3, finger4, finger5);
		
		finger1_2 = FlexSensor_Read(12);
		_delay_ms(10);
		finger3_4 = FlexSensor_Read(34);
		_delay_ms(10);
		finger5_0 = FlexSensor_Read(4);
		
		FlexSensor_Set_Word_diff_mode(finger1_2, finger3_4, finger5_0);
		_delay_ms(delay);
		
		
		
    }
}

