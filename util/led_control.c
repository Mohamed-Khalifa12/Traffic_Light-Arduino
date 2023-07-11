/*
 * led_control.c
 *
 * Created: 1/18/2023 12:40:04 AM
 *  Author: mohamed
 */ 

#include "led_control.h"

/*
	1. initiate pins 0 1 & 2 in port A as an output
	2. initiate pins 0 1 & 2 in port B as an output
	3. initiate the button in pin 2 port D as an input
	4. initiate the interrupts
*/

void init_leds()
{
	LED_init(0, PORT_C);
	LED_init(1, PORT_C);
	LED_init(2, PORT_C);

	LED_init(0, PORT_B);
	LED_init(1, PORT_B);
	LED_init(2, PORT_B);
	
	BUTTON_init(2, PORT_D);
	
	INT0_init();
}

//==============FOR RED LEDS=============//

//MAKE THE RED LED OF THE CAR ON
// write to pin 0 port A => 1 & pin 1 , 2 in port A => 0

void carREDLED_ON()
{
	LED_on(0, PORT_C);
	LED_off(1,PORT_C);
	LED_off(2,PORT_C);
}

//MAKE THE RED LED OF THE PED ON
// write to pin 0 port B => 1 & pin 1 , 2 in port B => 0
void pedREDLED_ON()
{
	LED_on(0, PORT_B);
	LED_off(1,PORT_B);
	LED_off(2,PORT_B);
}


//==============FOR GREEN LEDS=============//

//MAKE THE GREEN LED OF THE CAR ON
// write to pin 2 port A => 1 & pin 0 , 1 in port A => 0
void carGREENLED_ON()
{
	LED_off(0, PORT_C);
	LED_off(1,PORT_C);
	LED_on(2,PORT_C);
}

//MAKE THE GREEN LED OF THE PED ON
// write to pin 2 port B => 1 & pin 0 , 1 in port B => 0
void pedGREENLED_ON()
{
	LED_off(0, PORT_B);
	LED_off(1,PORT_B);
	LED_on(2,PORT_B);
}

//==============FOR YELLOW LEDS=============//

// toggle the yellow led in car's traffic light
static void car_toggleYELLOWLED()
{
	LED_toggle(1, PORT_C);
}

// toggle the yellow led in pedestrian's traffic light
static void ped_toggleYELLOWLED()
{
	LED_toggle(1, PORT_B);
}

/*
for a delay 1 sec after calculations:
we must looping 4 times
with prescaler 1024
and the initial value = 12 => 0x0c
*/

// MAKE THE YELLOW LED OF CARS BLINKING
void carYELLOWLED_BLINKING()
{
	for (int i = 0; i < 5; i++)
	{
		car_toggleYELLOWLED();
		TIMER0_delay(0x0c, 4, _1024_PRE);
	}
}

//MAKE THE YELLOW LED OF PED BLINKING
void pedcarYELLOWLED_BLINKING()
{
	for (int i = 0; i < 5; i++)
	{
		ped_toggleYELLOWLED();
		car_toggleYELLOWLED();
		TIMER2_delay(0x0c, 4, _1024_PRE);
	}
}

//CLOSE ALL LEDS OF PED
/*
	write to pins 0 1 & 2 in port B => 0
*/
void pedLEDS_OFF()
{
	LED_off(0, PORT_B);
	LED_off(1,PORT_B);
	LED_off(2,PORT_B);
}

////////////////////////////////////////////////////////////////

/* 
	1. light the green led on 
	2. wait for 5 seconds
*/
void car_GREENLED_ON()
{
	carGREENLED_ON();
	TIMER0_delay(0x0c, 20, _1024_PRE);
}

/* 
	1. light the red led on 
	2. wait for 5 seconds
*/
void car_REDLED_ON()
{
	carREDLED_ON();
	TIMER0_delay(0x0c, 20, _1024_PRE);
}

/* 
	function (interruptfn1) for interrupt if the state is yellow or green
		1. the red led of pedestrian's traffic light will turn on
		2. the yellow led will blink for 5 seconds
		3. light the green led of pedestrian's on & light the car's red led off
		4. the yellow led will blink for 5 seconds
		5. light off all ped's leds
*/

void interruptfn1()
{
	pedREDLED_ON();
	pedcarYELLOWLED_BLINKING();
	pedGREENLED_ON();
	carREDLED_ON();
	TIMER2_delay(0x0c, 20, _1024_PRE);
	pedcarYELLOWLED_BLINKING();
	pedREDLED_ON();
	carGREENLED_ON();
	pedLEDS_OFF();
}

/*
	function (interruptfn2) for interrupt if the state is red
		1. light the green light of ped's on
		2. light the red light of car's on
		3. wait for 5 seconds
		4 light all leds off of ped's  
*/

void interruptfn2()
{
	pedGREENLED_ON();
	carREDLED_ON();
	TIMER2_delay(0x0c, 20, _1024_PRE);
	pedLEDS_OFF();
}

