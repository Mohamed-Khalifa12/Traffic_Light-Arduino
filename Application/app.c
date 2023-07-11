/*
 * app.c
 *
 * Created: 1/11/2012 12:57:48 AM
 *  Author: mohamed
 */ 

#include "app.h"

uint8_t intial;

typedef enum car_led_state {GREEN,  YELLOW, RED}EN_CARLEDSTATE;
typedef enum INT_Control {RISING, FALLING}EN_INTCONTROL;

EN_INTCONTROL control;
uint8_t isLong;

EN_CARLEDSTATE state;

void APP_init()
{
	init_leds();
}

/*
for a delay 5 seconds after calculations:
we must looping 20 times
with prescaler 1024
and the initial value = 12 => 0x0c
*/


/*
	.start the normal mode 
		1. set state = green & light the green led on
		2. wait 5 seconds
		3. set state = yellow & blink the yellow led 
		4. wait 5 seconds
		5. set state = red & light the red led on
		6. wait 5 seconds
		7. set state = yellow & blink the yellow led
		8. wait for 5 seconds
	this will be done periodically until an interrupt  
*/

void APP_start()
{
	state = GREEN;
	car_GREENLED_ON();
	state = YELLOW;
	carYELLOWLED_BLINKING();
	state = RED;
	car_REDLED_ON();
	state = YELLOW;
	carYELLOWLED_BLINKING();
}

//check the state of the car's traffic light

static void interrupt_fn()
{
	if(state != RED)
	{
		interruptfn1();
	}
	else
	{
		interruptfn2();
	}
}

/*
	if interrupt happens
		1. check if it is single or double or long press
		if it is single so go ahead and get the state of the light
		if it is red 
			1. it gives extra five seconds and light the pedestrians green led on
		if it is yellow or red
			1. the red led of pedestrian's traffic light will turn on
			2. the yellow led will blink for 5 seconds
			3. light the green led of pedestrian's on & light the car's red led off
			4. the yellow led will blink for 5 seconds
		back again to the normal operation
*/

ISR(EXT_INT_0)
{
	if(intial == 1)
	{
		BUTTON_isLongPress(2, PORT_D, interrupt_fn);	
	}
	else
	{
		intial++;
	}
}


