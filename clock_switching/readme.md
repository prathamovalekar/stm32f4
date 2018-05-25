
# STM32F407VG Discovery Board CLOCK SOURCES:
1) Crystal Oscillator(external MCU)(HSE High speed external)

2) RC oscillator (Internal MCU)(HSIHigh speed internal) 16 Mghz

3) PLL Phase Locked Loop(Internal)


# On RESET RC oscillator is selected.
# STEPS To switch the clock to Crystal Oscillator:
	1) RCC clock control register (RCC_CR)
	   HSE ON=> it is on 16th bit
	2) Wait till HSE(high speed external =crystal oscillator) becomes stable
	   wait untill ready flag ie 17th bit of RCC clock control register (RCC_CR) is set
	3) Select HSE as the main(system) clock
	   	 RCC clock configuration register (RCC_CFGR) Bit1	Bit0
							 	0	0: HSI oscillator selected as system clock
 								0	1: HSE oscillator selected as system clock
								1	0: PLL selected as system clock
								1	1: not applicable	
