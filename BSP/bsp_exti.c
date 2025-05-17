#include "bsp_exti.h"

/**
 * @brief 配置中断向量嵌套控制器
 */
static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* 配置NVIC为优先级组1 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /* 按键1 */
    NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ; /**< 配置中断源 */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; /**< 配置抢占优先级 */
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; /**< 配置子优先级 */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; /**< 使能中断通道 */

    NVIC_Init(&NVIC_InitStructure);

    /* 按键2 */
    NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ; /**< 配置中断源 */
    NVIC_Init(&NVIC_InitStructure);
}

/**
 * @brief 配置IO为EXIT中断口，并配置中断优先级
 */
void EXTI_Key_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;

    /* 开启GPIO口及AFIO口时钟 */
    RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(KEY2_INT_GPIO_CLK, ENABLE);

    /* 配置NVIC中断 */
    NVIC_Configuration();

    /* KEY1配置 */
  GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN; /**< 选择引脚 */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; /**< 浮空输入 */
  GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);

	
  GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE); /**<  选择EXTI的信号源 */
  EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; /**< 中断模式 */
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; /**< 上升沿触发 */
  EXTI_InitStructure.EXTI_LineCmd = ENABLE; /**< 使能中断 */
  EXTI_Init(&EXTI_InitStructure);
	
  /* KEY2配置 */	
  GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN; /**< 选择引脚 */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; /**< 浮空输入 */
  GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);

	/* 选择EXTI的信号源 */
  GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE); /**<  选择EXTI的信号源 */
  EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; /**< 中断模式 */
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; /**< 下降沿触发 */
  EXTI_InitStructure.EXTI_LineCmd = ENABLE; /**< 使能中断 */
  EXTI_Init(&EXTI_InitStructure);
}

void KEY1_IRQHandler(void)
{
  //确保是否产生了EXTI Line中断
	if(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET) 
	{
		// LED1 取反		
		LED1_TOGGLE;
    //清除中断标志位
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);     
	}  
}

void KEY2_IRQHandler(void)
{
  //确保是否产生了EXTI Line中断
	if(EXTI_GetITStatus(KEY2_INT_EXTI_LINE) != RESET) 
	{
		// LED2 取反		
		LED2_TOGGLE;
    //清除中断标志位
		EXTI_ClearITPendingBit(KEY2_INT_EXTI_LINE);     
	}  
}

