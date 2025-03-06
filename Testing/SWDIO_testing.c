#include "ch32v003_gpio_driver.h"

void delay(void){
    for (int i=0;i<5000;i++);
}

int main(void)
{
    GPIO_Handle_t button;
    button.pGPIOx = GPIOD;
    button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT30MHz;
    button.GPIO_PinConfig.GPIO_PinNumber = 0;
    button.GPIO_PinConfig.GPIO_PinType = GPIO_TYPE_OUT_PP;

    GPIO_Init(&button);

    while(1)
    {
        GPIO_ToggleOutputPin(GPIOD,0);
        delay();
    }
}