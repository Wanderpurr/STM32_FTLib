#include "stm32f10x.h"
#include "bsp_systick.h"
#include "bsp_led.h"

int main(void)
{

	LED_GPIO_Config();
	
	while (1)
	{
		LED1_TOGGLE;
		SysTick_Delay_Ms(500);
	}
}
