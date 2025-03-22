#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

void delay(u32 count);
void led_change(int8_t led_state);
int main(void)
{
    int8_t led_state = 0;
    LED_GPIO_Config();
    KEY_GPIO_Config();
    while (1) {
        if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON) {
            led_state++;
            if (led_state == 8)
                led_state = 0;
            led_change(led_state);
        }

        if (Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON) {
            led_state--;
            if (led_state == -1)
                led_state = 7;
            led_change(led_state);
        }
    }
}

void delay(u32 count)
{
    for (;count != 0;count--);
}

void led_change(int8_t led_state)
{
    switch (led_state) {
    default:
    case 0:/* 关闭所有灯 */
        LED_RGBOFF;
        break;
    case 1:/* 红 */
        LED_RED;
        break;
    case 2:/* 绿 */
        LED_GREEN;
        break;
    case 3:/* 蓝 */
        LED_BLUE;
        break;
    case 4:/* 黄 */
        LED_YELLOW;
        break;
    case 5:/* 紫 */
        LED_PURPLE;
        break;
    case 6:/* 青 */
        LED_CYAN;
        break;
    case 7:/* 白 */
        LED_WHITE;
        break;
    }
}
