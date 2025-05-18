#include "bsp_systick.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
//	if (SysTick_Config(SystemFrequency / 100000))	// ST3.0.0库版本
	if (SysTick_Config(SystemCoreClock / 100000))	// ST3.5.0库版本
	{ 
		/* Capture error */ 
		while (1);
	}
}

void Delay_us(__IO u32 nTime)
{
	TimingDelay = nTime;	

	// 使能滴答定时器  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimingDelay != 0);
}


/**
  * @brief  获取节拍程序
  * @attention  在 SysTick 中断函数 SysTick_Handler()调用
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
    }
}



/**
 * @brief 延时us微秒时间
 * @param us 延时的微秒数
 */
void SysTick_Delay_Us(__IO u32 us)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000000);

    /* 每us后CTRL的BIT(16)会置一 */
    for (i = 0;i < us;i++) {
        while (!((SysTick->CTRL) & (1 << 16)));
    }

    /* 关闭SysTick定时器 */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

}

/**
 * @brief 延时ms微秒时间
 * @param ms 延时的微秒数
 */
void SysTick_Delay_Ms(__IO u32 ms)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000);

    /* 每ms后CTRL的BIT(16)会置一 */
    for (i = 0;i < ms;i++) {
        while (!((SysTick->CTRL) & (1 << 16)));
    }

    /* 关闭SysTick定时器 */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

}
