/*
 * FlexSensor.h
 *
 * Created: 6/8/2022 8:14:52 PM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef FLEXSENSOR_H_
#define FLEXSENSOR_H_


#include "ADC.h"
#include "DIO.h"
#include "LCD.h"

void FlexSensor_Init(void);
uint16 FlexSensor_Read(uint8 channel);
void FlexSensor_Set_Word(uint16 finger1, uint16 finger2, uint16 finger3, uint16 finger4, uint16 finger5); // single ended mode
void FlexSensor_Set_Word_diff_mode(uint16 finger1_2, uint16 finger3_4, uint16 finger5_0);  // differential mode



#endif /* FLEXSENSOR_H_ */