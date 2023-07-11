/*
 * timer.h
 *
 * Created: 1/11/2012 5:24:19 AM
 *  Author: mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../util/register.h"

#define GET_STATE_0 (TIFR0 & 0x01)
#define GET_STATE_2 (TIFR2 & 0x02)

typedef enum prescaller {_0_PRE, _8_PRE, _64_PRE, _256_PRE, _1024_PRE }EN_PRESCALLER;

void TIMER0_delay(uint8_t intialValue, uint8_t loopsNum, EN_PRESCALLER pre);
void TIMER2_delay(uint8_t intialValue, uint8_t loopsNum, EN_PRESCALLER pre);

#endif /* TIMER_H_ */