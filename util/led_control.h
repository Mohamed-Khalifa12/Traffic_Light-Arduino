/*
 * led_control.h
 *
 * Created: 1/18/2023 12:49:54 AM
 *  Author: moham
 */ 


#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#include "../MCAL/TIMER DRIVER/timer.h"
#include "../ECUAL/LED DRIVER/led.h"
#include "../MCAL/INTERRUPT DRIVER/interrupt.h"

void init_leds();
void carREDLED_ON();
void pedREDLED_ON();
void carGREENLED_ON();
void pedGREENLED_ON();
void carYELLOWLED_BLINKING();
void pedLEDS_OFF();
void pedcarYELLOWLED_BLINKING();
void car_GREENLED_ON();
void car_REDLED_ON();
void interruptfn1();
void interruptfn2();


#endif /* LED_CONTROL_H_ */