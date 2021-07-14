/*
 * UART.c
 *
 *  Author: Aya
 */ 

#include <xc.h>
#include "UART_Interface.h"
void UART_init(uint_16 BaudRate){
	/* set Rx, Tx Directions */
	DIO_voidSetPinDir(PORTD,PIN0,OUTPUT);
	DIO_voidSetPinDir(PORTD,PIN1,INPUT);
	/*   Set Baud/Bit Rate */
	UART_UBRRH_REG= (uint_8)(BaudRate>>8); //upper reg.
	UART_UBRRL_REG=(uint_8)BaudRate;//lower reg
	/* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);
	/* Enable Transmitter*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);
	/*Frame Format: 8 bits, 1 stop bit, even Parity */
	UART_UCSRC_REG |=(1<<URSEL_BIT_NO)|UART_8BIT_DATA|UART_EVEN_PARITY;
	//UART_UCSRC_REG = 0X86;
	
}
void UART_Tx(uint_8 Data){
	/* wait for empty transmit buffer*/
	while((GET_BIT(UART_UCSRA_REG,UDRE_BIT_NO))==0)
	/* data into buffer for sending */
	UART_UDR_REG=Data;
}
uint_8 UART_Rx(void){
	/* wait for data*/
	while((GET_BIT(UART_UCSRA_REG,RXC_BIT_NO))==0);
	/* return received data from buffer */
	return UART_UDR_REG;
}
