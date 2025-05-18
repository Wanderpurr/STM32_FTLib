#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

#include "stm32f10x.h"

// void SysTick_Init(void);
// void Delay_us(__IO u32 nTime);
// #define Delay_ms(x) Delay_us(100*x)

void SysTick_Delay_Us(__IO u32 us);
void SysTick_Delay_Ms(__IO u32 ms);

#endif /* __BSP_SYSTICK_H__ */
