/*
 * UART_Private.h
 *
 * Created: 7/9/2021 7:10:35 PM
 *  Author: Aya
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
#include "STD_TYPES.h"
/*				UART Regiters								*/
#define UART_UBRRH_REG (*((volatile uint_8*)0x40))
#define UART_UBRRL_REG (*((volatile uint_8*)0x29))
#define UART_UCSRA_REG (*((volatile uint_8*)0x2B))
#define UART_UCSRB_REG (*((volatile uint_8*)0x2A))
#define UART_UCSRC_REG (*((volatile uint_8*)0x40))
#define UART_UDR_REG (*((volatile uint_8*)0x2C))
/* Macros for bit numbers (to avoid Magic Numbers)*/
#define RXEN_BIT_NO (4)
#define TXEN_BIT_NO (3)
#define URSEL_BIT_NO (7)
#define USBS_BIT_NO (3)
#define UCSZ0_BIT_NO (1)
#define UPM0_BIT_NO (4)
#define UDRE_BIT_NO (5)
#define RXC_BIT_NO (7)

#define UART_8BIT_DATA (3<<UCSZ0_BIT_NO)
#define UART_1BIT_STOP (1<<USBS_BIT_NO)

#define UART_EVEN_PARITY (2<<UPM0_BIT_NO)
#define UART_ODD_PARITY (3<<UPM0_BIT_NO)

#endif /* UART_PRIVATE_H_ */