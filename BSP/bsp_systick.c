#include "bsp_systick.h"

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
