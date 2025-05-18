#include "stm32f10x.h"
#include "bsp_systick.h"
#include "bsp_led.h"

int main(void)
{

	LED_GPIO_Config();
	SysTick_Init();

	while (1)
	{
		Delay_ms(500);
		LED2_TOGGLE;
	}
}
