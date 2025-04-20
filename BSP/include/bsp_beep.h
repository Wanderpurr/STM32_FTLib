#ifndef __BSP_BEEP_H__
#define __BSP_BEEP_H__

#include "stm32f10x.h"

#define BEEP_GPIO_PORT GPIOA
#define BEEP_GPIO_PIN  GPIO_Pin_8
#define BEEP_GPIO_CLK  RCC_APB2Periph_GPIOA

/* 高电平是蜂鸣器响 */
#define BEEP_ON  1
#define BEEP_OFF 0

#define BEEP(state) \
            if(state) \
                GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN); \
            else \
                GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Config(void);

#endif /* __BSP_BEEP_H__ */
