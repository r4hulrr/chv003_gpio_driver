#include "testing.h"

void R_delay(void){
    for (int i=0;i<500000000;i++);
}

void R_LED_TEST_SETUP(void)
{
    // Initialize GPIO as output
    R_GPIO_Handle_t button;
    button.pGPIOx = R_GPIOC;
    button.GPIO_PinConfig.GPIO_PinMode = R_GPIO_MODE_OUT10MHz;
    button.GPIO_PinConfig.GPIO_PinNumber = 1;
    button.GPIO_PinConfig.GPIO_PinType = R_GPIO_TYPE_OUT_PP;

    R_GPIO_Init(&button);
}

void R_LED_TEST(void)
{
    // GPIO Blink Test
    R_GPIO_ToggleOutputPin(R_GPIOC, 1);
    R_delay();
}

void R_UART_TEST(void)
{
    // Initialize GPIO PC2 as IT_FT
    R_GPIO_Handle_t interrupt;
    interrupt.pGPIOx = R_GPIOC;
    interrupt.GPIO_PinConfig.GPIO_PinMode = R_GPIO_MODE_IT_FT;
    interrupt.GPIO_PinConfig.GPIO_PinNumber = 2;
    interrupt.GPIO_PinConfig.GPIO_PinType = R_GPIO_TYPE_IN_PUPD;
    
    R_GPIO_Init(&interrupt);

    //Initialize GPIO PC3 as the interrupt trigger output
    R_GPIO_Handle_t trigger;
    trigger.pGPIOx = R_GPIOC;
    trigger.GPIO_PinConfig.GPIO_PinMode = R_GPIO_MODE_OUT10MHz;
    trigger.GPIO_PinConfig.GPIO_PinNumber = 3;
    trigger.GPIO_PinConfig.GPIO_PinType = R_GPIO_TYPE_OUT_PP;

    R_GPIO_Init(&trigger);  

    R_GPIO_IRQConfig(20, 6, ENABLE);
    
    R_GPIO_ToggleOutputPin(trigger.pGPIOx,trigger.GPIO_PinConfig.GPIO_PinNumber);

    R_GPIO_IRQHandling(interrupt.GPIO_PinConfig.GPIO_PinNumber);
}
