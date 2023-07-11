/*
 * led.h
 *
 * Created: 1/11/2012 12:41:36 AM
 *  Author: mohamed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO DRIVER/dio.h"

void LED_init(uint8_t pinNum , uint8_t portNum);
void LED_on(uint8_t pinNum, uint8_t portNum);
void LED_off(uint8_t pinNum , uint8_t portNum);
void LED_toggle(uint8_t pinNum, uint8_t portNum);


#endif /* LED_H_ */