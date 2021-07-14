/*
 * SPI_Interface.h
 *
 * Created: 7/11/2021 1:27:46 AM
 *  Author: Aya
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_Private.h"

#define SPI_SCK_FREQ_FCPU_DIV_16 (1<<0)
 
void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterWrite(uint_8 Data);
uint_8 SPI_MasterRead(void);
uint_8 SPI_SlaveRead(void);
uint_8 SPI_MasterTranseve(uint_8 Data);
void SPI_MasterInitTranseve(void);



#endif /* SPI_INTERFACE_H_ */