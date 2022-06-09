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
Uint8 FlexSensor_Read(Uint8 channel);
void FlexSensor_Set_Word(Uint16 finger1, Uint16 finger2, Uint16 finger3, Uint16 finger4, Uint16 finger5);



#endif /* FLEXSENSOR_H_ */