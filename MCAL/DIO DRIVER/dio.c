/*
 * dio.c
 *
 * Created: 7/11/2023 1:30:52 AM
 *  Author: moham
 */ 

#include "dio.h"

/*
	DIO_init ==> accept pin number, port number & direction then return Nothing
		1.check the port
		2.check the direction
		if it is in so make this pin as input
		and if it is out make the pin an output
*/

void DIO_init(uint8_t pinNum, uint8_t portNum, uint8_t direction)
{
	switch(portNum)
	{
		case PORT_B:
			if(direction == IN)
				CLEAR_BIT(DDRB, pinNum);
			else if(direction == OUT)
				SET_BIT(DDRB, pinNum);
			else
				printf("Wrong direction");
		break;
		case PORT_C :
			if(direction == IN)
				CLEAR_BIT(DDRC, pinNum);
			else if(direction == OUT)
				SET_BIT(DDRC, pinNum);
			else
				printf("Wrong direction");
		break;
		case PORT_D:
			if(direction == IN)
				CLEAR_BIT(DDRD, pinNum);
			else if(direction == OUT)
				SET_BIT(DDRD, pinNum);
			else
				printf("Wrong direction");
		break;
		default:
			printf("Unavailable Port !!");
		break;
	}
}

/*
	after the initialization DIO_init and the direction is output we use write function  
	DIO_write ==> accept pin number, port number & value then return Nothing
		1.check the port
		2.check the value
		if it is low so make this pin as output and the value = 0
		and if it is High make the pin an output and the value = 1
*/

//WRITE FUN
void DIO_write(uint8_t pinNum, uint8_t portNum, uint8_t value)
{
	switch(portNum)
	{
		case  PORT_B:
			if(value == LOW)
				CLEAR_BIT(PORTB, pinNum);
			else if(value == HIGH)
				SET_BIT(PORTB, pinNum);
			else
				printf("Wrong Value");
		break;
		case  PORT_C:
			if(value == LOW)
				CLEAR_BIT(PORTC, pinNum);
			else if(value == HIGH)
				SET_BIT(PORTC, pinNum);
			else
				printf("Wrong Value");
		break;
		case  PORT_D:
			if(value == LOW)
				CLEAR_BIT(PORTD, pinNum);
			else if(value == HIGH)
				SET_BIT(PORTD, pinNum);
			else
				printf("Wrong Value");
		break;
		default:
			printf("Unavailable Port !!");
		break;
	}
	
}

/*
	after the initialization DIO_init and the direction is output we use toggle function  
	DIO_toggle ==> accept pin number& port number then return Nothing
		1.check the port
		and toggle the pin inputed
*/

// TOGGLE
void DIO_toggle(uint8_t pinNum, uint8_t portNum)
{
		switch (portNum)
		{
			case PORT_B:
				TOGGLE_BIT(PORTB,pinNum);
			break;
			case PORT_C:
				TOGGLE_BIT(PORTC,pinNum);
			break;
			case PORT_D:
				TOGGLE_BIT(PORTD,pinNum);
			break;
			default:
				printf("Unavailable Port !!");
			break;
		}
	
}

/*
	after the initialization DIO_init and the direction is input we use read function
	DIO_toggle ==> accept pin number, port number, and pointer to value to store the data in it then return Nothing
		1.check the port
		then save the input data
		
*/

//READING
void DIO_read(uint8_t pinNum, uint8_t portNum,uint8_t *value)
{
	switch (portNum)
	{
		case PORT_B:
			*value = READ_BIT(PINB, pinNum);
		break;
		case PORT_C:
			*value = READ_BIT(PINC, pinNum);
		break;
		case PORT_D:
			*value = READ_BIT(PIND, pinNum);
		break;	
		default:
			printf("Unavailable Port !!");
		break;
	}
}