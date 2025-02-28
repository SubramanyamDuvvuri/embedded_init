#include "stm32_gpio_driver.h"





void GPIO_Clock_Enable(GPIO_RegDef_t *pGPIOx, uint8_t DiEn)
{
	if(DiEn==ENABLE)
	{

		if  (pGPIOx == GPIOA)
			ENABLE_CLK_GPIOA();


		else if  (pGPIOx ==  GPIOB)
			ENABLE_CLK_GPIOB();

		else if   (pGPIOx ==   GPIOC)
			ENABLE_CLK_GPIOC();

		else if   (pGPIOx ==   GPIOD)
			ENABLE_CLK_GPIOD();

		else if   (pGPIOx ==   GPIOE)
			ENABLE_CLK_GPIOE();

		else if   (pGPIOx ==   GPIOF)
			ENABLE_CLK_GPIOF();

		else if   (pGPIOx ==   GPIOG)
			ENABLE_CLK_GPIOG();

		else if   (pGPIOx ==   GPIOH)
			ENABLE_CLK_GPIOH();


	}
	else
	{

	}
}

void GPIO_Init(GPIO_Handle_t* pGPIO_Handle)
{

	GPIO_Clock_Enable(pGPIO_Handle->pGPIOx, ENABLE);
	uint32_t temp = 0;


	/* Mode of the Register*/
	if(pGPIO_Handle->PinConfig.mode <= ANALOG)
	{
		temp = pGPIO_Handle->PinConfig.mode <<(2*pGPIO_Handle->PinConfig.pin);
		pGPIO_Handle->pGPIOx->MODER &= (~(3<<pGPIO_Handle->PinConfig.pin));
		pGPIO_Handle->pGPIOx->MODER |=temp;
	}
	if(pGPIO_Handle->PinConfig.mode ==ALT_FUN)
	{
		uint8_t temp1 , temp2;

		temp1 = pGPIO_Handle->PinConfig.pin/8;
		temp2 = pGPIO_Handle->PinConfig.pin%8;
		pGPIO_Handle->pGPIOx->AFR[temp1]	 &= (~(0xff <<pGPIO_Handle->PinConfig.pinAltFunMod));
		pGPIO_Handle->pGPIOx->AFR[temp1]		|= pGPIO_Handle->PinConfig.pinAltFunMod << (4*temp2);

	}
	else //Interrupt Mode
	{


		/* COnfig Rising and falling trigger*/
		if (pGPIO_Handle->PinConfig.mode == RE_INT)
		{

			temp |= (1<<pGPIO_Handle->PinConfig.pin);
			EXTI->EXTI_RTSR |= temp;
			EXTI->EXTI_FTSR |= (0<<pGPIO_Handle->PinConfig.pin);
			temp = 0;
		}
		else if (pGPIO_Handle->PinConfig.mode == FE_INT)
		{
			temp |= (1<<pGPIO_Handle->PinConfig.pin);
			EXTI->EXTI_FTSR |= temp;
			EXTI->EXTI_RTSR |= (0<<pGPIO_Handle->PinConfig.pin);
			temp = 0;

		}
		else if (pGPIO_Handle->PinConfig.mode == RFE_INT)
		{
			temp |= (1<<pGPIO_Handle->PinConfig.pin);
			EXTI->EXTI_FTSR |= temp;
			EXTI->EXTI_RTSR |=temp;
		}


		/* Enable interrupt mask register*/
		temp |= (1<<pGPIO_Handle->PinConfig.pin);
		EXTI->EXTI_IMR|=temp;
		/* Configure SYSCONFIG*/
		ENABLE_CLK_SYSCONFIG();
		/*Configure EXTI LINE in SYSCONFIG*/
		uint8_t temp1 = (pGPIO_Handle->PinConfig.pin/4);
		uint8_t temp2 = pGPIO_Handle->PinConfig.pin%4;
		uint8_t     sysconfig_reg_port_config = SysConfig_Get_Port(pGPIO_Handle->pGPIOx);

		SYSCONFIG->SYSCFG_EXTICR[temp1] = sysconfig_reg_port_config<<(4*temp2);
	}


	temp = 0;
	/*Speed of the register*/
	temp = pGPIO_Handle->PinConfig.speed <<(2*pGPIO_Handle->PinConfig.pin);
	pGPIO_Handle->pGPIOx->OSPEEDR &= (~(3<<pGPIO_Handle->PinConfig.pin));
	pGPIO_Handle->pGPIOx->OSPEEDR |=temp;
	temp = 0;

	/*Config Pullup Pull Down*/
	temp = pGPIO_Handle->PinConfig.pupdControl <<(2*pGPIO_Handle->PinConfig.pin);
	pGPIO_Handle->pGPIOx->PUPDR &= (~(3<<pGPIO_Handle->PinConfig.pin));

	pGPIO_Handle->pGPIOx->PUPDR|=temp;


	/*Output Type*/
	temp = pGPIO_Handle->PinConfig.PinopType <<(pGPIO_Handle->PinConfig.pin);
	pGPIO_Handle->pGPIOx->PUPDR &= (~(1<<pGPIO_Handle->PinConfig.pin));

	pGPIO_Handle->pGPIOx->PUPDR|=temp;

	temp = 0;
}

uint8_t SysConfig_Get_Port(GPIO_RegDef_t *pGPIOx)
{
	uint8_t port = 0;


	if (pGPIOx == GPIOA) {
		port = 0;

	} else if (pGPIOx == GPIOB) {
		port = 1;
	} else if (pGPIOx == GPIOC) {
		port = 2;
	} else if (pGPIOx == GPIOD) {
		port = 3;
	} else if (pGPIOx == GPIOE) {
		port = 4;
	} else if (pGPIOx == GPIOF) {
		port = 5;
	} else if (pGPIOx == GPIOG) {
		port = 6;
	} else if (pGPIOx == GPIOH) {
		port = 7;
	} else {
		port = 0;
	}


	return port;
}



void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}
uint8_t GPIO_Read_From_Pin(GPIO_RegDef_t *pGPIOx, int PinNumber)
{
	uint8_t temp = 0;

	temp =(uint8_t)(( pGPIOx->IDR>>PinNumber) & 0x0000001);
	return temp;
}
uint16_t GPIO_Read_From_Port(GPIO_RegDef_t *pGPIOx)
{
	uint16_t temp;
	temp = pGPIOx->IDR;

	return temp;
}
void GPIO_Write_to_Pin(GPIO_RegDef_t *pGPIOx, int PinNumber, uint8_t value)
{
	if(value ==SET)
		pGPIOx->ODR |= (1<<PinNumber);
	else
		pGPIOx->ODR &= (~(1<<PinNumber));

}
void GPIO_Write_to_Port(GPIO_RegDef_t *pGPIOx, int PinNumber, uint16_t value)
{
	pGPIOx->ODR = value;
}
void GPIO_Toggle(GPIO_RegDef_t *pGPIOx, int PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);

}

void GPIO_IRQConfig(uint8_t IRQnumber, uint8_t IRQPriority, uint8_t EnDI)
{
	//uint8_t temp1 = IRQnumber/32;
	//uint8_t temp2 =IRQnumber%32;
	if(EnDI)
	{

	}
}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}
