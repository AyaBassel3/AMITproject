#ifndef			DIO_INTERFACE_H
#define			DIO_INTERFACE_H
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"DIO_private.h"
void	DIO_voidSetPinDir(uint_8 PortID , uint_8 PinID ,uint_8 Direction);

void	DIO_voidSetPinValue(uint_8 PortID , uint_8 PinID ,uint_8 Value);

uint_8	DIO_uint_8GetPinValue(uint_8 PortID , uint_8 PinID);


void	DIO_voidSetPortDireation(uint_8 PortID , uint_8 Direction);

void	DIO_voidSetPortValue(uint_8 PortID , uint_8 Value);


#define			PORTA			0
#define			PORTB			1
#define			PORTC			2
#define			PORTD			3

#define			PIN0			0
#define			PIN1			1
#define			PIN2			2
#define			PIN3			3
#define			PIN4			4
#define			PIN5			5
#define			PIN6			6
#define			PIN7			7

#define			INPUT			0
#define			OUTPUT			1

#define			HIGH			1
#define			LOW				0


#endif