/*
 * interrupt.h
 *
 * Created: 1/12/2012 8:37:53 AM
 *  Author: mohamed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../util/register.h"

#define EXT_INT_0 __vector_1

//INTERRUPT FUNCTION
#define  ISR(INT_VEC) void INT_VEC(void) __attribute__((signal, used));\
void INT_VEC(void)

//prototypes
void INT0_init();


#endif /* INTERRUPT_H_ */