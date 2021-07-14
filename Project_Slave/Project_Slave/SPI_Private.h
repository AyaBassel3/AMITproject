/*
 * SPI_Private.h
 *
 * Created: 7/11/2021 1:27:26 AM
 *  Author: Aya
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
#include "STD_TYPES.h"
/* Macros definition for SPI driver Regs and bits */
#define SPI_SPCR_REG (*(volatile uint_8*)0x2D)
#define SPI_SPSR_REG (*(volatile uint_8*)0x2E)
#define SPI_SPDR_REG (*(volatile uint_8*)0x2F)

#define SPI_SPE_BIT_NO (6)
#define SPI_MSTR_BIT_NO (4)
#define SPI_SPIF_BIT_NO (7)

/* Config reg*/

#define SPI_SS_PORT (PORTB)
#define SPI_SS_CHANNEL (PIN4)

#define SPI_MOSI_PORT (PORTB)
#define SPI_MOSI_CHANNEL (PIN5)

#define SPI_MISO_PORT (PORTB)
#define SPI_MISO_CHANNEL (PIN6)

#define SPI_SCK_PORT (PORTB)
#define SPI_SCK_CHANNEL (PIN7)










#endif /* SPI_PRIVATE_H_ */