/*
 * Master.c
 *
 *  Author: Aya
 */ 

#include "UART_Interface.h"
#include "SPI_Interface.h" 

int main(void)
{
	uint_8 DummyData, BluetoothData =0;
	/*UART Initialization (Check UART Driver for more comments)*/
	UART_init(UART_BAUDRATE_9600);
	/*SPI Master Initialization (Check SPI Driver for more comments)*/
	SPI_MasterInit();
	/*SPI Master Transeve Initialization (Check SPI Driver for more comments)*/
	SPI_MasterInitTranseve();
	
    while(1)
    {
        /*UART Receiving Data from the Bluetooth module */
		BluetoothData=UART_Rx();
		/*SPI Sending from Master To Slave in a dummy variable (flush register)*/
		DummyData=SPI_MasterTranseve(BluetoothData);
		BluetoothData=0;
    }
}