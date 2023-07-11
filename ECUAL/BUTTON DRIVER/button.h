/*
 * button.h
 *
 * Created: 1/11/2012 1:52:22 AM
 *  Author: mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO DRIVER/dio.h"

//INTIALIZING BUTTON
void BUTTON_init(uint8_t pinNum, uint8_t portNum);

//STARTING BUTTON
void BUTTON_start(uint8_t pinNum, uint8_t portNum, uint8_t *value);

//CHECKING IF LONG PRESS OR NOT
void BUTTON_isLongPress(uint8_t pinNum, uint8_t portNum, void (*fn)());

#endif /* BUTTON_H_ */