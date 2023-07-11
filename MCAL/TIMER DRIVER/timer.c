/*
 * timer.c
 *
 * Created: 1/11/2012 5:24:34 AM
 *  Author: mohamed
 */ 

#include "timer.h"

/*
	For timer 0
	TIMER0_start takes the prescaler as an input to start the timer and specify the prescaler
	check the value of prescaler and activate the required register
*/

//STARTING TIMER 0
static void TIMER0_start(EN_PRESCALLER pre)
{
	switch(pre)
	{
		case _0_PRE:
			TCCR0B = 0x01;
		break;
		case _8_PRE:
			TCCR0B = 0x02;
		break;
		case _64_PRE:
			TCCR0B = 0x03;
		break;
		case _256_PRE:
			TCCR0B = 0x04;
		break;
		case _1024_PRE:
			TCCR0B = 0x05;
		break;
		default:
			printf("Unavailable prescalaer !!");
		break;
	}
}

/*
	For timer 1
	TIMER1_start takes the prescaler as an input to start the timer and specify the prescaler
	check the value of prescaler and activate the required register
*/


//STARTING TIMER 2
static void TIMER2_start(EN_PRESCALLER pre)
{
	switch(pre)
	{
		case _0_PRE:
			TCCR2B = 0x01;
		break;
		case _8_PRE:
			TCCR2B = 0x02;
		break;
		case _64_PRE:
			TCCR2B = 0x04;
		break;
		case _256_PRE:
			TCCR2B = 0x06;
		break;
		case _1024_PRE:
			TCCR2B = 0x07;
		break;
		default:
			printf("Unavailable prescalaer !!");
		break;
	}
}

/*
	For timer 0
	TIMER0_delay => intial value, loopsNum and the prescaler
	1. initiate the data reg with the value of intial value
	2. start the timer (previous functions)
	3. looping to the number of calculated loops needed
	4. check the flag which check if the reg is full or not (TIFR)
	5. when it is full make the data reg = 0 by putting 1 on that flag (TIFG)
	6. finish the timer
*/

//implement the delay function with (initial value, prescalar and the number of looping) as inputs
//and it will impelement the required delay
 
void TIMER0_delay(uint8_t intialValue, uint8_t loopsNum, EN_PRESCALLER pre)
{
	TCNT0 = intialValue;
	TIMER0_start(pre);
	if(loopsNum == 0)
	{
		while(GET_STATE_0 == 0);
		TIFR0 = 0x01;
	}
	else
	{
		for (int i = 0; i < loopsNum; i++)
		{
			while(GET_STATE_0 == 0);
			TIFR0 = 0x01;
		}
	}
	TCCR0A = 0x00;
}

/*
	For timer 2
	TIMER1_delay => intial value, loopsNum and the prescaler
	1. initiate the data reg with the value of intial value
	2. start the timer (previous functions)
	3. looping to the number of calculated loops needed
	4. check the flag which check if the reg is full or not (TIFR)
	5. when it is full make the data reg = 0 by putting 1 on that flag (TIFG)
	6. finish the timer
*/

//delay with timer 1 
void TIMER2_delay(uint8_t intialValue, uint8_t loopsNum, EN_PRESCALLER pre)
{
	TCNT2 = intialValue;
	TIMER2_start(pre);
	if(loopsNum == 0)
	{
		while(GET_STATE_2 == 0);
		TIFR2 = 0x01;
	}
	else
	{
		for (int i = 0; i < loopsNum; i++)
		{
			while(GET_STATE_2 == 0);
			TIFR2 = 0x02;
		}
	}
	TCCR2A = 0x00;
}