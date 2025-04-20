#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_beep.h"

void delay(u32 count);

int main(void)
{
    BEEP_GPIO_Config();
    while (1) {
      BEEP( BEEP_ON ); 		   // 响
			delay(0x0FFFFF);	
			BEEP( BEEP_OFF );		  // 不响
			delay(0x0FFFFF);
    }
}

void delay(u32 count)
{
    for (;count != 0;count--);
}
