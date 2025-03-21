#include "stm32f10x.h"
#include "bsp_led.h"

void delay(u32 count);

int main(void)
{
    LED_GPIO_Config();
    while (1) {
        LED_RED;
        delay(0xfffff);

        LED_GREEN;
        delay(0xfffff);

        LED_BLUE;
        delay(0xfffff);

        LED_YELLOW;
        delay(0xfffff);

        LED_PURPLE;
        delay(0xfffff);

        LED_CYAN;
        delay(0xfffff);

        LED_WHITE;
        delay(0xfffff);

        LED_RGBOFF;
        delay(0xfffff);
    }
}

void delay(u32 count)
{
    for (;count != 0;count--);
}
