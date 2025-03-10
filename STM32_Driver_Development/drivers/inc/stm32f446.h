

#ifndef STM32F446_H
#define STM32F446_H

#include <stdint.h>


#define ENABLE 	1
#define DISABLE 0
#define SET		ENABLE
#define RESET	DISABLE

/*NVIC  Registers*/
#define INTERRUPT_SET_ENABLE_REG					0xE000E100u
#define INTERRUPT_CLEAR_ENABLE_REG			0XE000E180u
#define	INTERRUPT_PRIORITY_REGISTER				0xE000E400u


/*EXT IRQ*/


#define EXTI_IRQ_0				6
#define EXTI_IRQ_1				7
#define EXTI_IRQ_2				8
#define EXTI_IRQ_3				9
#define EXTI_IRQ_4				10
#define EXTTI_IRQ_9_5		23
#define EXTI_IRQ_10_15		40

/*Memory Base Addresses*/
#define FLASH_BASEADDR 			0x08000000u
#define SRAM_16KB_BASEADDR  	0x2001C000u
#define	SRAM_112KB_BASEADDR		0x20000000u
#define ROM_BASEADDR			0x1FFF0000u			//System Memory


/* Bus base addresses*/

#define APB1_BASEADDR 			0x40000000u
#define APB2_BASEADDR			0x40010000u
#define AHB1_BASEADDR			0x40020000u
#define AHB2_BASEADDR			0x50050000u




/*Peripherals on AHB1 Bus */

#define GPIOA_BASEADDR			(AHB1_BASEADDR+0)
#define GPIOB_BASEADDR			(AHB1_BASEADDR+0x0400)
#define GPIOC_BASEADDR			(AHB1_BASEADDR+0x0800)
#define GPIOD_BASEADDR			(AHB1_BASEADDR+0x0c00)
#define GPIOE_BASEADDR			(AHB1_BASEADDR+0x1000)
#define GPIOF_BASEADDR			(AHB1_BASEADDR+0x1400)
#define GPIOG_BASEADDR			(AHB1_BASEADDR+0x1800)
#define GPIOH_BASEADDR			(AHB1_BASEADDR+0x1c00)

#define DMA1_BASEADDR			(AHB1_BASEADDR+0x6000)
#define	DMA2_BASEADDR 			(AHB1_BASEADDR+0x6400)
#define RCC_BASEADDR			(AHB1_BASEADDR+0x3800)





/*Peripherals on APB1 Bus */

#define I2C1_BASEADDR 			(APB1_BASEADDR+0x5400)
#define I2C2_BASEADDR			(APB1_BASEADDR+0x5800)
#define I2C3_BASEADDR			(APB1_BASEADDR+0x5c00)
#define UART2_BASEADDR			(APB1_BASEADDR+0x4400)
#define UART3_BASEADDR			(APB1_BASEADDR+0x4800)
#define UART4_BASEADDR			(APB1_BASEADDR+0x4c00)
#define UART5_BASEADDR			(APB1_BASEADDR+0x5000)
#define CAN1_BASEADDR			(APB1_BASEADDR+0x6400)
#define CAN2_BASEADDR			(APB1_BASEADDR+0x6800)
#define SPI2_BASEADDR			(APB1_BASEADDR+0x3800)
#define SPI3_BASEADDR			(APB1_BASEADDR+0x3c00)

/*Peripherals on APB2 Bus */
#define EXTI_BASEADDR				(APB2_BASEADDR+0x3C00)
#define UART1_BASEADDR			(APB2_BASEADDR+0x1000)
#define UART6_BASEADDR			(APB2_BASEADDR+0x1400)
#define SPI1_BASEADDR				(APB2_BASEADDR+0x3000)
#define SPI4_BASEADDR					(APB2_BASEADDR+0x3400)
#define SYSCONFIG_BASEADDR      (APB2_BASEADDR+0x3800)





typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRRL;
	volatile uint32_t BSSRH;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];

} GPIO_RegDef_t;



typedef struct
{
	volatile uint32_t		RCC_CR;
	volatile uint32_t		RCC_CLL_CFGR;
	volatile uint32_t		RCC_CFGR;
	volatile uint32_t		RCC_CIR;
	volatile uint32_t		RCC_AHB1_RSTR;
	volatile uint32_t		RCC_AHB2_RSTR;
	volatile uint32_t		RCC_AHB3_RSTR;
	volatile uint32_t		RCC_reserved;
	volatile uint32_t		RCC_APB1_RSTR;
	volatile uint32_t		RCC_APB2_RSTR;
	volatile uint32_t		RCC_reserved1;
	volatile uint32_t		RCC_reserved2;
	volatile uint32_t		RCC_AHB1ENR;
	volatile uint32_t		RCC_AHB2ENR;
	volatile uint32_t		RCC_AHB3ENR;
	volatile uint32_t		RCC_reserved3;
	volatile uint32_t		RCC_APB1ENR;
	volatile uint32_t		RCC_APB2ENR;
	volatile uint32_t		RCC_reserved4;
	volatile uint32_t		RCC_reserved5;
	volatile uint32_t		RCC_AHB1LPENR;
	volatile uint32_t		RCC_AHB2LPENR;
	volatile uint32_t		RCC_AHB3LPENR;
	volatile uint32_t		RCC_reserved6;
	volatile uint32_t		RCC_APB1LPENR;
	volatile uint32_t		RCC_APB2LPENR;
	volatile uint32_t		RCC_reserved7;
	volatile uint32_t		RCC_reserved8;
	volatile uint32_t		RCC_BDCSR;
	volatile uint32_t		RCC_CSR;
	volatile uint32_t		RCC_reserved9;
	volatile uint32_t		RCC_reserved10;
	volatile uint32_t		RCC_SS_CGR;
	volatile uint32_t		RCC_PLLI2CGFR;
	volatile uint32_t		RCC_PLLSAICGFR;
	volatile uint32_t		RCC_DCKCGFR;
	volatile uint32_t		RCC_CKGATENR;
	volatile uint32_t		RCC_DCKCGFR2;

}RCC_RegDef_t;

typedef struct
{
	volatile uint32_t	 SYSCFG_MEMRMP;
	volatile uint32_t	  SYSCFG_PMC;
	volatile uint32_t	 SYSCFG_EXTICR[4];
	volatile uint32_t	  SYSCFG_CMPCR;
	volatile uint32_t	SYSCFG_CFGR;

}SYSCONFIG_RegDef_t;

typedef struct
{
	volatile uint32_t	  	EXTI_IMR;							// Interrupt Mask Register
	volatile uint32_t    	EXTI_EMT;						//Event Mask Register
	volatile	uint32_t	  	EXTI_RTSR;						//Rising trigger selection Register
	volatile	uint32_t	 	EXTI_FTSR;						//Falling trigger selection Register
	volatile	uint32_t		EXTI_SWIER;					//Sw Interrupt event register
	volatile  uint32_t		EXTI_PR;							//Pending Register
}EXTI_RegDef_t;


typedef	struct
{
	volatile uint32_t	SPI_CSR1;						//Control Register
	volatile uint32_t	SPI_CSR2;						//control Reg
	volatile uint32_t	SPI_SR;								//Status Reg
	volatile uint32_t	SPI_DR;								//Data Reg
	volatile uint32_t	SPI_CRCPR;						//CRC Polynomial Reg
	volatile uint32_t	SPI_RXCRCR;					//RXCRC
	volatile uint32_t	SPI_TXCRCR;					//TXCRC
	volatile uint32_t	SPI_I2SCFGR;					/*I2C Config Reg*/
	volatile uint32_t	SPI_I2SSPR;						/*Prescalar Reg*/


}SPI_RegDef_t;







#define GPIOA					 	((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 				((GPIO_RegDef_t*)GPIOH_BASEADDR)


#define RCC   							((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCONFIG				((SYSCONFIG_RegDef_t*)SYSCONFIG_BASEADDR)
#define	EXTI 							((EXTI_RegDef_t*) EXTI_BASEADDR)

#define	SPI1						((SPI_RegDef_t*)SPI1_BASEADDR)
#define	SPI2						((SPI_RegDef_t*)SPI2_BASEADDR)
#define	SPI3						((SPI_RegDef_t*)SPI3_BASEADDR)
#define	SPI4						((SPI_RegDef_t*)SPI4_BASEADDR)

/*
 * CLOCK ENABLE
 */


#define	ENABLE_CLK_SYSCONFIG()				(RCC->RCC_APB2ENR |=(1<<14))						//SYSCONFIG CLOCK Enable




#endif


