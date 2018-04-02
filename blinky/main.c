#include "stm32f4xx.h"                  // Device header
#include "io.h"
#include "delay.h"

int main()
	
{
	LED_init();
	while(1){
		GPIOD->ODR &=(0x00<<12);
		ms_delay(250);
			
		GPIOD->ODR |=(BLUE|RED|ORANGE|GREEN);
		ms_delay(500);
		
		GPIOD->ODR &=(0x00<<12);
		ms_delay(250);
		GPIOD->ODR |=(BLUE);
		ms_delay(500);
		GPIOD->ODR |=(RED);
		ms_delay(500);	
		GPIOD->ODR |=(ORANGE);
		ms_delay(500);	
		GPIOD->ODR |=(GREEN);
		ms_delay(500);			
	}
}


