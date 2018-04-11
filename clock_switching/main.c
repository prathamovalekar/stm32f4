#include "stm32f407xx.h"                  // Device header
#include <stdint.h>

int main(){
	
	RCC_TypeDef *pRCC;
	pRCC = RCC;
	//RCC clock control register (RCC_CR)
	//HSE ON=> it is on 16th bit
	pRCC->CR |=(1U << 16);
	
	//wait till HSE(high speed external =crystal oscillator) becomes stable
	//wait untill ready flag ie 17th bit of RCC->CR to set
	while ( ! ( pRCC->CR & (1<<17)));

	//Select HSE as the main(system) clock
	// RCC clock configuration register (RCC_CFGR) Bit1 Bit0
	//																						 	0		0: HSI oscillator selected as system clock
  //																							0		1: HSE oscillator selected as system clock
	//																							1		0: PLL selected as system clock
	//																							1		1: not applicable	
	pRCC->CFGR &= ~	(0x3<<0);			// Clear the bits1&0
	pRCC->CFGR |=		(0x1<<0);			//HSE select
	
	
}

