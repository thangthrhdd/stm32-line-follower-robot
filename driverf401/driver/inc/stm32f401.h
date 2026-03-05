/*
 * stm32f401.h
 *
 *  Created on: Sep 11, 2025
 *      Author: ADMIN
 */

#ifndef INC_STM32F401_H_
#define INC_STM32F401_H_
#include<stdint.h>
#include "stdlib.h"
#define __vo volatile

#define NVIC_ISER0_BASE_ADDR ((__vo uint32_t*) 0xE000E100)
#define NVIC_ICER0_BASE_ADDR ((__vo uint32_t*) 0xE000E180)
#define NVIC_IPR0_BASE_ADDR  ((__vo uint32_t*) 0xE000E400)

#define ROM_ADDR 0x1FFF0000U
#define RAM_ADDR 0x20000000U
#define FLASH_ADDR 0x08000000U

#define AHB2_BASEADDR 0x50000000U
#define AHB1_BASEADDR 0x40020000U
#define APB2_BASEADDR 0x40010000U
#define APB1_BASEADDR 0x40000000U

#define RCC_BASEADDR (AHB1_BASEADDR+0x3800)
#define GPIOA_BASEADDR (AHB1_BASEADDR)
#define GPIOB_BASEADDR (AHB1_BASEADDR+0x0400)
#define GPIOC_BASEADDR (AHB1_BASEADDR+0x0800)
#define GPIOD_BASEADDR (AHB1_BASEADDR+0x0C00)
#define GPIOE_BASEADDR (AHB1_BASEADDR+0x1000)
#define GPIOH_BASEADDR (AHB1_BASEADDR+0x1C00)
#define SYSCFG_BASEADDR (APB2_BASEADDR+0x3800)
#define OTG_FS_BASEADDR 0x50000000U
#define EXTI_BASEADDR (APB2_BASEADDR+0x3C00)

#define TIM1_BASEADDR (APB2_BASEADDR)
#define TIM2_BASEADDR (APB1_BASEADDR)
#define TIM8_BASEADDR (APB2_BASEADDR+0x400)
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t reserved[2];

	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t reserved1[2];

	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t reserved2[2];

	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t reserved3[2];

	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t reserved4[2];

	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t reserved5[2];

	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t reserved6[2];

	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t reserved7;

	__vo uint32_t DCKCFGR;

}RCC_RegDef_t;
#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
#define GPIOA_PLCK_EN() (RCC->AHB1ENR|=1)
#define GPIOB_PLCK_EN() (RCC->AHB1ENR|=1<<1)
#define GPIOC_PLCK_EN() (RCC->AHB1ENR|=1<<2)
#define GPIOD_PLCK_EN() (RCC->AHB1ENR|=1<<3)
#define GPIOE_PLCK_EN() (RCC->AHB1ENR|=1<<4)
#define GPIOH_PLCK_EN() (RCC->AHB1ENR|=1<<7)
#define SYSCFG_PCLK_EN() (RCC->APB2ENR|=1<<14)
#define OTG_PCLK_EN() (RCC->AHB2ENR|=1<<7)

#define TIM1_PCLK_EN() (RCC->APB2ENR|=1<<0)
#define TIM2_PCLK_EN() (RCC->APB1ENR|=(1<<0))
#define TIM8_PCLK_EN() (RCC->APB2ENR|=1<<1)

#define GPIOA_PLCK_DI() (RCC->AHB1ENR&=~1)
#define GPIOB_PLCK_DI() (RCC->AHB1ENR&=~(1<<1))
#define GPIOC_PLCK_DI() (RCC->AHB1ENR&=~(1<<2))
#define GPIOD_PLCK_DI() (RCC->AHB1ENR&=~(1<<3))
#define GPIOE_PLCK_DI() (RCC->AHB1ENR&=~(1<<4))
#define GPIOH_PLCK_DI() (RCC->AHB1ENR&=~(1<<7))
#define SYSCFG_PCLK_DI() (RCC->APB2ENR&=~(1<<14))
#define OTG_PCLK_DI() (RCC->AHB2ENR&=~(1<<7))

#define TIM1_PCLK_DI() (RCC->APB2ENR&=~(1<<0))
#define TIM2_PCLK_DI() (RCC->APB1ENR&=~(1<<0))
#define TIM8_PCLK_DI() (RCC->APB2ENR&=~(1<<1))

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;

}GPIO_RegDef_t;
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPCR;
}SYSCFG_RegDef_t;
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)
typedef struct
{
	__vo uint32_t GOTGCTL;//0x00
	__vo uint32_t GOTGINT;//0x04
	__vo uint32_t GAHBCFG;//0x08
	__vo uint32_t GUSBCFG;//0x0c
	__vo uint32_t GRSTCTL;//0x10
	__vo uint32_t GINTSTS;//0x14
	__vo uint32_t GINTMSK;//0x18
	__vo uint32_t GRXSTSP;//0x1c
	__vo uint32_t GRXSTSPR;//0x20
	__vo uint32_t GRXFSIZ;//0x24
	__vo uint32_t DIEPTXF0;//0x28
	__vo uint32_t HNPTXSTS;//0x2c
	__vo uint32_t Reversed1[2];
	__vo uint32_t GCCFG;//0x38
	__vo uint32_t CID;//0x3c
	__vo uint32_t Reversed2[48];
	__vo uint32_t HPTXFSIZ;//0x100
	__vo uint32_t DIEPTXF[3];
}OTG_FS_GLOBAL;
#define OTG_GLOBAL ((OTG_FS_GLOBAL*)OTG_FS_BASEADDR)
typedef struct
{
	__vo uint32_t HCCHAR;//0x500
	__vo uint32_t Reversed0;//0x504
	__vo uint32_t HCINT;//0x508
	__vo uint32_t HCINTMSK;//0x50c
	__vo uint32_t HCTSIZ;//0x510
	__vo uint32_t Reversed1[7];
}REG_HOST;
typedef struct
{
//	__vo uint32_t Reversed0[255];
	__vo uint32_t HCFG;//0x400
	__vo uint32_t HFIR;//0x404
	__vo uint32_t HFNUM;//0x408
	__vo uint32_t HPTXSTS;//0x410
	__vo uint32_t HAINT;//0x414
	__vo uint32_t HAINTMSK;//0x418
	__vo uint32_t Reversed1[9];
	__vo uint32_t HPRT;//0x440
	__vo uint32_t Reversed2[47];
	REG_HOST Host[8];
}OTG_FS_HOST;
#define OTG_HOST ((OTG_FS_HOST*)(OTG_FS_BASEADDR+0x400U))

typedef struct
{
	__vo uint32_t DIEPCTL;//0x900+0x20*x
	__vo uint32_t Reversed0;
	__vo uint32_t DIEPINT;//0x908+0x20*x
	__vo uint32_t Reversed5;
	__vo uint32_t DIEPTSIZ;//0x910+0x20*x
	__vo uint32_t Reversed1;
	__vo uint32_t DTXFSTS;//0x918+0x20*x
	__vo uint32_t Reversed2[1];
}REG_DIEP;

typedef struct
{
	__vo uint32_t DOEPCTL;//0xB00+0x20*x
	__vo uint32_t Reversed0;
	__vo uint32_t DOEPINT;//0xB08+0x20*x
	__vo uint32_t Reversed1;
	__vo uint32_t DOEPTSIZ;//0xB10+0x20*x
	__vo uint32_t Reversed2[3];
}REG_DOEP;
typedef struct
{
//	__vo uint32_t Reversed0[511];
	__vo uint32_t DCFG;//0x800
	__vo uint32_t DCTL;//0x804
	__vo uint32_t DSTS;//0x808
	__vo uint32_t Reversed1;//0x80c
	__vo uint32_t DIEPMSK;//0x810
	__vo uint32_t DOEPMSK;//0x814
	__vo uint32_t DAINT;//0x818
	__vo uint32_t DAINTMSK;//0x81c
	__vo uint32_t Reversed2[2];
	__vo uint32_t DVBUSDIS;//0x828
	__vo uint32_t DVBUSPULSE;//0x82c
	__vo uint32_t Reversed3;
	__vo uint32_t DIEPEMPMSK;//0x834

	__vo uint32_t Reversed4[50];//0x8fc
	REG_DIEP DIEP[4];//0x9CC
	__vo uint32_t Reversed6[96];
	REG_DOEP DOEP[4];//0xb00
}OTG_FS_DEVICE;
#define OTG_DEVICE ((OTG_FS_DEVICE*)(OTG_FS_BASEADDR+0x800U))
typedef struct
{
	__vo uint32_t PCGCCTL;
}OTG_FS_Power;
#define OTG_POWER ((OTG_FS_Power*)(OTG_FS_BASEADDR+0xE00U))


typedef struct
{
	__vo uint32_t CR1;//0x00
	__vo uint32_t CR2;//0x04
	__vo uint32_t SMCR;//0x08
	__vo uint32_t DIER;//0x0c
	__vo uint32_t SR;//0x10
	__vo uint32_t EGR;//0x14
	__vo uint32_t CCMR[2];//0x18
	__vo uint32_t CCER;//0x20
	__vo uint32_t CNT;//0x24
	__vo uint32_t PSC;//0x28
	__vo uint32_t ARR;//0x2c
	__vo uint32_t RCR;//0x30
	__vo uint32_t CCR[4];//0x34
	__vo uint32_t BDTR;//0x44
	__vo uint32_t DCR;//0x48
	__vo uint32_t DMAR;//0x4c
	__vo uint32_t OR;//0x50

}TIM_RegDef_t;
#define TIM1 ((TIM_RegDef_t*)TIM1_BASEADDR)
#define TIM2 ((TIM_RegDef_t*)TIM2_BASEADDR)
#define TIM8 ((TIM_RegDef_t*)TIM8_BASEADDR)


#define SET 1
#define RESET 0
#define FLAG_SET 1
#define FLAG_RESET 0
#define ENABLE 1
#define DISABLE 0
#endif /* INC_STM32F401_H_ */
