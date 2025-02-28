

#ifndef	STM32_GPIO_DRIVER
#define STM32_GPIO_DRIVER

#include"stm32f446.h"


typedef struct
{
	uint8_t pin;
	uint8_t mode;
	uint8_t speed;
	uint8_t pupdControl;
	uint8_t	PinopType;
	uint8_t pinAltFunMod;

}GPIO_PinConfig_t;

typedef struct{

	GPIO_RegDef_t* pGPIOx;				//Base address of the port
	GPIO_PinConfig_t PinConfig;
}GPIO_Handle_t;




  void GPIO_Clock_Enable(GPIO_RegDef_t *pGPIOx, uint8_t DiEn);

  void GPIO_Init(GPIO_Handle_t* pGPIO_Handle);
  void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
  uint8_t GPIO_Read_From_Pin(GPIO_RegDef_t *pGPIOx, int PinNumber);
  uint16_t GPIO_Read_From_Port(GPIO_RegDef_t *pGPIOx);
  void GPIO_Write_to_Pin(GPIO_RegDef_t *pGPIOx, int PinNumber, uint8_t value);
  void GPIO_Write_to_Port(GPIO_RegDef_t *pGPIOx, int PinNumber, uint16_t value);
  void GPIO_Toggle(GPIO_RegDef_t *pGPIOx, int PinNumber);


  void GPIO_IRQConfig(uint8_t IRQnumber, uint8_t IRQPriority, uint8_t EnDI);
  void GPIO_IRQHandling(uint8_t PinNumber);

  uint8_t SysConfig_Get_Port(GPIO_RegDef_t *X);



#define ENABLE_CLK_GPIOA()				(RCC->RCC_AHB1ENR|=(1<<0))
#define ENABLE_CLK_GPIOB()			(RCC->RCC_AHB1ENR|=(1<<1))
#define ENABLE_CLK_GPIOC()			(RCC->RCC_AHB1ENR|=(1<<2))
#define ENABLE_CLK_GPIOD()			(RCC->RCC_AHB1ENR|=(1<<3))
#define ENABLE_CLK_GPIOE()				(RCC->RCC_AHB1ENR|=(1<<4))
#define ENABLE_CLK_GPIOF()				(RCC->RCC_AHB1ENR|=(1<<5))
#define ENABLE_CLK_GPIOG()			(RCC->RCC_AHB1ENR|=(1<<6))
#define ENABLE_CLK_GPIOH()			(RCC->RCC_AHB1ENR|=(1<<7))



#define  INPUT				0
#define  OUTPUT			1
#define 	ALT_FUN			2
#define ANALOG			3
#define RE_INT				4
#define FE_INT				5
#define	RFE_INT					6


#define PUSH_PULL				0
#define	OPEN_DRAIN			1

#define 	LOW_SPEED			0
#define	MEDIUM_SPEED	1
#define	FAST_SPEED			2
#define	HIGH_SPEED			3


#define 	NO_PULL_UP_PULL_DOWN			0
#define	PULL_UP	1
#define	PULL_DOWN			2


#define GPIO_PIN_0 			0
#define GPIO_PIN_1 			1
#define GPIO_PIN_2 			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4 			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6 			6
#define GPIO_PIN_7 			7
#define GPIO_PIN_8 			8
#define GPIO_PIN_9 			9
#define GPIO_PIN_10 		10
#define GPIO_PIN_11	 	11
#define GPIO_PIN_12 		12
#define GPIO_PIN_13		13
#define GPIO_PIN_14 		14
#define GPIO_PIN_15 		15




#endif
