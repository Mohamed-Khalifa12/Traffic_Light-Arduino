/*
 * dio.h
 *
 * Created: 7/11/2023 1:30:41 AM
 *  Author: mohamed
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../util/register.h"

//PORTS
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//DIRECTION
#define IN 0
#define OUT 1

//VALUES
#define LOW 0
#define HIGH 1

//CLEAR , SET AND READ BITS
#define  CLEAR_BIT(X,Y) (X &= ~(1<<Y))
#define SET_BIT(X,Y) (X |= (1<<Y))
#define  READ_BIT(X,Y) ((X & (1<<Y))>>Y)
#define TOGGLE_BIT(X,Y) (X ^= (1<< Y))

//FUNCTIONS PROTOTYPES
void DIO_init(uint8_t pinNum, uint8_t portNum, uint8_t direction);
void DIO_write(uint8_t pinNum, uint8_t portNum, uint8_t value);
void DIO_toggle(uint8_t pinNum, uint8_t portNum);
void DIO_read(uint8_t pinNum, uint8_t portNum,uint8_t *value);


#endif /* DIO_H_ */
