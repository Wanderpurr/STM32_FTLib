#include "bsp_beep.h"
/**
 * @brief 初始化控制蜂鸣器IO
 * @param 无
 * @return 无
 */
void BEEP_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    /* 开时钟 */
    RCC_APB2PeriphClockCmd(BEEP_GPIO_CLK, ENABLE);
    /* 填充初始化结构体 */
    GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    /* 初始化蜂鸣器 */
    GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);
    /* 关闭蜂鸣器 */
    GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);
}
