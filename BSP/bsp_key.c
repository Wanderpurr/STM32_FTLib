#include "bsp_key.h"

/**
 * @brief  初始化2个按键
 * @param  无
 * @return 无
 */
void KEY_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 开启按键相关GPIO时钟 */
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK, ENABLE);

    /* 初始化key1*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; /**< 浮空输入 */
    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);

    /* 初始化key2 */
    GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;
    GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
}
/**
 * @brief 按键扫描,判断是否被按下
 * @param GPIOx: x可以是A,B,C,D,E
 * @param GPIO_Pin: 待读取的端口为
 * @return KEY_OFF: 按键未被按下
 *         KEY_ON:  按键被按下
 */
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    /* 检测按键引脚电平,判断是否被按下 */
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
        /* 按键按下,等待抬起 */
        while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
        return KEY_ON;
    } else {
        /* 按键没有被按下 */
        return KEY_OFF;
    }
}
