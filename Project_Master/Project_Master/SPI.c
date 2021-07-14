/*
 * SPI.C
 *  Author: Aya
 */ 
#include "SPI_Interface.h"

void SPI_MasterInit(void){
	//SPI MOSI AS OUTPUT
	DIO_voidSetPinDir(SPI_MOSI_PORT,SPI_MOSI_CHANNEL,OUTPUT);
	//SPI SS AS OUTPUT
	DIO_voidSetPinDir(SPI_SS_PORT,SPI_SS_CHANNEL,OUTPUT);
	//SPI SCK AS OUTPUT
	DIO_voidSetPinDir(SPI_SCK_PORT,SPI_SCK_CHANNEL,OUTPUT);
	//SPI MISO AS IUTPUT
	DIO_voidSetPinDir(SPI_MISO_PORT,SPI_MISO_CHANNEL,INPUT);
	//Initialize SPI SS pin with HIGH (SS in Active Low)
	DIO_voidSetPinValue(SPI_SS_PORT,SPI_SS_CHANNEL,HIGH);
	// Enable SPI Module
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	// Enable Master Mode
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	// Set SCK Freq (1MHz)
	SPI_SPCR_REG |= SPI_SCK_FREQ_FCPU_DIV_16; 	
	
	
}
void SPI_MasterInitTranseve(void){
	
DIO_voidSetPinValue(SPI_SS_PORT,SPI_SS_CHANNEL,LOW);	
	
	
	
}
void SPI_SlaveInit(void){
	
	//SPI MOSI AS IUTPUT
	DIO_voidSetPinDir(SPI_MOSI_PORT,SPI_MOSI_CHANNEL,INPUT);
	//SPI SS AS IUTPUT
	DIO_voidSetPinDir(SPI_SS_PORT,SPI_SS_CHANNEL,INPUT);
	//SPI SCK AS IUTPUT
	DIO_voidSetPinDir(SPI_SCK_PORT,SPI_SCK_CHANNEL,INPUT);
	//SPI MISO AS OUTPUT
	DIO_voidSetPinDir(SPI_MISO_PORT,SPI_MISO_CHANNEL,OUTPUT);
	// Enable SPI Module
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	// Enable Slave Mode
	CLR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	
	
}
void SPI_MasterWrite(uint_8 Data);
uint_8 SPI_MasterRead(void);
uint_8 SPI_SlaveRead(void);
uint_8 SPI_MasterTranseve(uint_8 Data){
	/*load SPI data Reg with a byte to send*/
	SPI_SPDR_REG=Data;
	/*Wait for sending process to finish (Flag)*/
	while((GET_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO))==0);
	/*Flush the reg*/
	return SPI_SPDR_REG;
	
	
	
}