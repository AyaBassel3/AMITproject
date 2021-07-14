/*
 * UART_Interface.h
 *
 * Created: 7/9/2021 7:10:56 PM
 *  Author: Aya
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "UART_Private.h"
#include "DIO_interface.h"
#define UART_BAUDRATE_9600 (0x67)
void UART_init(uint_16 BaudRate);
void UART_Tx(uint_8 Data);
uint_8 UART_Rx(void);




#endif /* UART_INTERFACE_H_ */