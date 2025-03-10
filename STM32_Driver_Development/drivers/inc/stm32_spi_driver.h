
#ifndef	STM32_SPI_H
#define	STM32_SPI_H

#include"stm32f446.h"


#define SPI_MASTER_MODE					1
#define SPI_SLAVE_MODE						0






#define SPI_CSR_1_MODE_BIT			2

typedef struct
{
	volatile uint32_t SPI_Device_Mode;
	volatile uint32_t SPI_Bus_Config;
	volatile uint32_t SPI_DFF;
	volatile uint32_t SPI_CPHA;
	volatile uint32_t SPI_CPOL;
	volatile uint32_t SPI_SSM;
	volatile uint32_t SPI_Speed;
} SPI_Config_t;


typedef struct
{
	SPI_RegDef_t *SPIx;
	SPI_Config_t	SPIConfig;

} SPI_Handle_t;


void SPI_Clock_Enable(SPI_RegDef_t *pSPIx, uint8_t EnDi);
void SPI_Init(SPI_Handle_t * pGPIO_Handle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);







#define Enable_CLK_SPI1					((RCC->RCC_APB2ENR|=1<<12))
#define Enable_CLK_SPI2					((RCC->RCC_APB1ENR|=1<<14))
#define Enable_CLK_SPI3					((RCC->RCC_APB1ENR|=1<<15))
#define Enable_CLK_SPI4					((RCC->RCC_APB2ENR|=1<<13))


#endif
