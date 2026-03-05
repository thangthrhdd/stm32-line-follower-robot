/*
 * gpio.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "gpio.h"
void GPIO_CLK(GPIO_RegDef_t * gpiox,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
   		if(gpiox==GPIOA) GPIOA_PLCK_EN();
		else if(gpiox==GPIOB) GPIOB_PLCK_EN();
 		else if(gpiox==GPIOC) GPIOC_PLCK_EN();
		else if(gpiox==GPIOD) GPIOD_PLCK_EN();
		else if(gpiox==GPIOE) GPIOE_PLCK_EN();
		else if(gpiox==GPIOH) GPIOH_PLCK_EN();
	}
	else
	{
		if(gpiox==GPIOA) GPIOA_PLCK_DI();
		else if(gpiox==GPIOB) GPIOB_PLCK_DI();
		else if(gpiox==GPIOC) GPIOC_PLCK_DI();
		else if(gpiox==GPIOD) GPIOD_PLCK_DI();
		else if(gpiox==GPIOE) GPIOE_PLCK_DI();
		else if(gpiox==GPIOH) GPIOH_PLCK_DI();
	}
}
void GPIO_Init(GPIO_Handle_t * gpio_handle)
{
	GPIO_CLK(gpio_handle->gpiox,ENABLE);
	//pu pd
	gpio_handle->gpiox->PUPDR&=~(0x03<<(gpio_handle->gpioy.gpio_pin*2));
	gpio_handle->gpiox->PUPDR|=(gpio_handle->gpioy.pupd<<(gpio_handle->gpioy.gpio_pin*2));

	if(gpio_handle->gpioy.gpio_pin<8)
	{
	gpio_handle->gpiox->AFRL&=~(0x0F<<(gpio_handle->gpioy.gpio_pin*4));
	gpio_handle->gpiox->AFRL|=(gpio_handle->gpioy.alt_function<<(gpio_handle->gpioy.gpio_pin*4));
	}
	else if(gpio_handle->gpioy.gpio_pin>=8)
	{
		gpio_handle->gpiox->AFRH&=~(0x0F<<((gpio_handle->gpioy.gpio_pin%8)*4));
		gpio_handle->gpiox->AFRH|=(gpio_handle->gpioy.alt_function<<((gpio_handle->gpioy.gpio_pin%8)*4));
	}

	if(gpio_handle->gpioy.mode<=3)
	{
		gpio_handle->gpiox->MODER&=~(0x03<<(gpio_handle->gpioy.gpio_pin*2));
		gpio_handle->gpiox->MODER|=(gpio_handle->gpioy.mode<<(gpio_handle->gpioy.gpio_pin*2));
		//optype
		gpio_handle->gpiox->OTYPER&=~(0x01<<(gpio_handle->gpioy.gpio_pin*2));
		gpio_handle->gpiox->OTYPER|=(gpio_handle->gpioy.optype<<(gpio_handle->gpioy.gpio_pin*2));
		//speed
		gpio_handle->gpiox->OSPEEDR&=~(0x03<<(gpio_handle->gpioy.gpio_pin*2));
		gpio_handle->gpiox->OSPEEDR|=(gpio_handle->gpioy.speed<<(gpio_handle->gpioy.gpio_pin*2));
		//alt function
		//pu pd

	}
	else
	{
		SYSCFG_PCLK_EN();
		uint8_t row=gpio_handle->gpioy.gpio_pin/4;
	    uint8_t col=gpio_handle->gpioy.gpio_pin%4;
	    SYSCFG->EXTICR[row]&=~(0x0f<<col);
	    SYSCFG->EXTICR[row]|=GPIO_To_Code(gpio_handle->gpiox)<<col;
	    if(gpio_handle->gpioy.mode==GPIO_IRQ_RT)
	    {
	    	EXTI->FTSR&=~(1<<gpio_handle->gpioy.gpio_pin);
	    	EXTI->RTSR|=1<<gpio_handle->gpioy.gpio_pin;
	    }
	    else if(gpio_handle->gpioy.mode==GPIO_IRQ_FT)
	    {
	    	EXTI->RTSR&=~(1<<gpio_handle->gpioy.gpio_pin);
	    	EXTI->FTSR|=1<<gpio_handle->gpioy.gpio_pin;
	    }
	    else if(gpio_handle->gpioy.mode==GPIO_IRQ_RTFT)
	    {
	    	EXTI->RTSR|=(1<<gpio_handle->gpioy.gpio_pin);
	    	EXTI->FTSR|=1<<gpio_handle->gpioy.gpio_pin;
	    }
	    EXTI->IMR|=1<<gpio_handle->gpioy.gpio_pin;
	    EXTI->PR|=1<<gpio_handle->gpioy.gpio_pin;
	}
}
void GPIO_WritePin(GPIO_RegDef_t * gpiox,uint8_t pin,uint8_t state)
{
   if(state==SET)
   {
	   gpiox->BSRR|=1<<pin;
   }
   else
   {
	   gpiox->BSRR|=1<<(pin+16);
   }
}
uint8_t GPIO_ReadPin(GPIO_RegDef_t * gpiox,uint8_t pin)
 {
	return (gpiox->IDR>>pin)&1;
}
void GPIO_TogglePin(GPIO_RegDef_t * gpiox,uint8_t pin)
  {
	if(gpiox->ODR<<pin)
	{
		gpiox->BSRR|=1<<(pin+16);
	}
	else
	{
		gpiox->BSRR|=1<<pin;
	}
}

void NVIC_IRQ_ConFig(uint8_t IRQ_number,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(IRQ_number<=31)
		{
			(*NVIC_ISER0_BASE_ADDR)|=(1<<IRQ_number);
		}
		else if(IRQ_number>=32 && IRQ_number<=63)
		{
			*(NVIC_ISER0_BASE_ADDR+1)|=(1<<IRQ_number%32);
		}
		else if(IRQ_number>=64 && IRQ_number<=80)
		{
			*(NVIC_ISER0_BASE_ADDR+2)|=(1<<IRQ_number%64);
		}
	}
	else
	{
		if(IRQ_number<=31)
		{
			(*NVIC_ICER0_BASE_ADDR)|=(1<<IRQ_number);
		}
		else if(IRQ_number>=32 && IRQ_number<=63)
		{
			*(NVIC_ICER0_BASE_ADDR+1)|=(1<<IRQ_number%32);
		}
		else if(IRQ_number>=64 && IRQ_number<=80)
		{
			*(NVIC_ICER0_BASE_ADDR+2)|=(1<<IRQ_number%64);
		}
	}
}
void NVIC_IRQ_PriorityConFig(uint8_t IRQ_number,uint8_t priority)
{
	uint8_t x=IRQ_number/4;
	uint8_t y=IRQ_number%4;
	*(NVIC_IPR0_BASE_ADDR+x)|=(priority<<(y*8+4)); //+4 vì chi lay 4 bit cao ơ moi feild
}
__attribute__((weak))void Application_CallBack(uint8_t pin)
{

}
void GPIO_IRQ_Handling(uint8_t pin)
{
  if(EXTI->PR&(1<<pin))
  {
	  Application_CallBack(pin);
	  EXTI->PR|=(1<<pin);
  }
}
