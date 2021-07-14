/*
 * Slave
 *
 *  Author: Aya
 */ 

#include "SPI_Interface.h"




int main(void)
{
	/**/
	uint_8 Data, DummyData =0;
	/*Set Actuators Outputs Direction*/
	DIO_voidSetPinDir(PORTD,PIN3,OUTPUT);
	DIO_voidSetPinDir(PORTC,PIN2,OUTPUT);
	/*SPI Slave Initialization (Check SPI Driver for more comments)*/
	SPI_SlaveInit();
	
	
    while(1)
    {
        Data=SPI_MasterTranseve(DummyData);
		/*Actuators is set to high if the number is odd and low if the number is even */
		if ((Data & HIGH)==HIGH)
		{
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			/*Clearing data for the next iteration*/
			Data=0;
		}else if ((Data & HIGH)==LOW)
		{
			DIO_voidSetPinValue(PORTD,PIN3,LOW);
			DIO_voidSetPinValue(PORTC,PIN2,LOW);
			/*Clearing data for the next iteration*/
			Data=0;
		}
    }
}