/*
 * LED.c
 *
 * Created: 1/11/2012 12:41:10 AM
 *  Author: mohamed
 */ 

#include "led.h"
// initiate the led by passing the pin number & port number
void LED_init(uint8_t pinNum , uint8_t portNum)
{
	DIO_init(pinNum, portNum, OUT);
}

// make the led on by passing the pin number and port number after initializing it
void LED_on(uint8_t pinNum, uint8_t portNum)
{
	DIO_write(pinNum,portNum, HIGH);
}

// make the led off by passing the pin number and port number after initializing it
void LED_off(uint8_t pinNum , uint8_t portNum)
{
	DIO_write(pinNum,portNum, LOW);
}

// make the led toggling by passing the pin number and port number after initializing it
void LED_toggle(uint8_t pinNum, uint8_t portNum)
{
	DIO_toggle(pinNum,portNum);
}
