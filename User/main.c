#include "stm32f10x.h"
#include "bsp_led.h"
// #include "bsp_key.h"
// #include "bsp_beep.h"
#include "bsp_clkconfig.h"
#include "bsp_mcooutput.h"

void delay(u32 count);

int main(void)
{
    // 使用HSE时，SYSCLK = 8M * RCC_PLLMul_x, x:[2,3,...16],最高是128M
	//HSE_SetSysClock(RCC_PLLMul_9);
	
	// 使用HSI时，SYSCLK = 4M * RCC_PLLMul_x, x:[2,3,...16],最高是64MH
	HSI_SetSysClock(RCC_PLLMul_16);
	
	// MCO 引脚初始化
	MCO_GPIO_Config();
	
	// 设置MCO引脚输出时钟，用示波器即可在PA8测量到输出的时钟信号，
	// 我们可以把PLLCLK/2作为MCO引脚的时钟来检测系统时钟是否配置准确
	// MCO引脚输出可以是HSE,HSI,PLLCLK/2,SYSCLK	
	//RCC_MCOConfig(RCC_MCO_HSE);	             	        
	//RCC_MCOConfig(RCC_MCO_HSI);	                   
	//RCC_MCOConfig(RCC_MCO_PLLCLK_Div2);    	
	//RCC_MCOConfig(RCC_MCO_SYSCLK);		      
	
	// LED 端口初始化
	LED_GPIO_Config();
	while (1)
	{
		LED1_ON	;			  // 亮
		delay(0x0FFFFF);
		LED1_ON	;		  // 灭 
		delay(0x0FFFFF);		
	}
}

void delay(u32 count)
{
    for (;count != 0;count--);
}
