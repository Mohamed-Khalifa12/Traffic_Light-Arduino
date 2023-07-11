/*
 * register.h
 *
 * Created: 1/10/2012 11:47:38 PM
 *  Author: mohamed
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#include "typedef.h"
//DIO REGISTERS

//PORTB
#define PORTB (*(volatile uint8_t *)(0x25))
#define DDRB (*(volatile uint8_t *)(0x24))
#define PINB (*(volatile uint8_t *)(0x23))

//PORTC
#define PORTC (*(volatile uint8_t *)(0x28))
#define DDRC (*(volatile uint8_t *)(0x27))
#define PINC (*(volatile uint8_t *)(0x26))

//PORTD
#define PORTD (*(volatile uint8_t *)(0x2B))
#define DDRD (*(volatile uint8_t *)(0x2A))
#define PIND (*(volatile uint8_t *)(0x29))

//TIMER REGISTERS
#define TCCR0A (*(volatile uint8_t *)(0x44)) //CONTROL REG OF TIMER 0
#define TCCR0B (*(volatile uint8_t *)(0x45)) //CONTROL REG OF TIMER 0
#define TCNT0 (*(volatile uint8_t *)(0x46)) //DATA REG OF TIMER 0
#define TIFR0 (*(volatile uint8_t *)(0x35)) //FLAG REG FOR BOTH TIMERS 0
#define TCCR2A (*(volatile uint8_t *)(0xB0)) //CONTROL REG A OF TIMER 2
#define TCCR2B (*(volatile uint8_t *)(0xB1)) //CONTROL REG A OF TIMER 2
#define TCNT2 (*(volatile uint8_t *)(0xB2)) //DATA REG HIGH OF TIMER 2
#define TIFR2 (*(volatile uint8_t *)(0x37)) //FLAG REG FOR BOTH TIMERS 2

//EXTERNAL INTERRUPT REGISTER
#define SREG (*(volatile uint8_t *)(0x5F)) //GLOBAL INTERRUPT *SET I BIT TO ENABLE EXTERNAL INTERRUPT
#define EICRA (*(volatile uint8_t *)(0x69)) //CONTROLLING INT 0 & 1 SENSTIVE (RISING -FALLING - LEVEL)
#define EIMSK (*(volatile uint8_t *)(0x3D)) //ENABING THE EXTERNAL INTERRUPT (0 OR 1 OR 2)


#endif /* REGISTERS_H_ */
