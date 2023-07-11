/*
 * buuton.c
 *
 * Created: 1/11/2012 1:52:02 AM
 *  Author: mohamed
 */ 

#include "button.h"


//INTIALIZING BUTTON
void BUTTON_init(uint8_t pinNum, uint8_t portNum)
{
	DIO_init(pinNum,portNum, IN);
}

//STARTING BUTTON
void BUTTON_start(uint8_t pinNum, uint8_t portNum, uint8_t *value)
{
	DIO_read(pinNum,portNum, value);
}

//isLongPress

/*
	1. initiate val = 0
	2. make a loop of 10000 iterations and read from the INT0 PIN 
	3. if the state if INT0 = 0 during the iterations
		.call the passed function and finish the function (single short press)
	4. if the state of INT0 stay 1 until the iterations finishes
		. do nothing
*/
void BUTTON_isLongPress(uint8_t pinNum, uint8_t portNum, void (*fn)())
{
	uint8_t *val = 0;
	for (int i = 0; i<= 10000; i++)
	{
		BUTTON_start(pinNum, portNum, val);
		if(*val == 0)
		{
			fn();
			return ;
		}
	}
}
