#include<stm32_spi_driver.h>



void SPI_Clock_Enable(SPI_RegDef_t *pSPIx, uint8_t EnDi)
{

	if(EnDi)
	{
		if (pSPIx == SPI1)
		{
			Enable_CLK_SPI1;
		}
		else if  (pSPIx == SPI2)
		{
			Enable_CLK_SPI2;
		}
		else if  (pSPIx == SPI3)
		{
			Enable_CLK_SPI3;
		}
		else if (pSPIx == SPI4)
		{
			Enable_CLK_SPI4;
		}
	}
	else
	{

	}



}
void SPI_Init(SPI_Handle_t * pSPI_Handle)
{

	SPI_Clock_Enable(pSPI_Handle->SPIx, ENABLE);

	uint16_t temp =0;
	/*SPI Mode*/

	temp = pSPI_Handle->SPIConfig.SPI_Device_Mode<<SPI_CSR_1_MODE_BIT;






}
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}






