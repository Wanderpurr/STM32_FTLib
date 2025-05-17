#ifndef __BSP_CLKCONFIG_H__
#define __BSP_CLKCONFIG_H__

#include "stm32f10x.h"

void HSE_SetSysClock(uint32_t pllmul);
void HSI_SetSysClock(uint32_t pllmul);

#endif /* __BSP_CLKCONFIG_H__ */
