#include "ch32v003_gpio_driver.h"

/*
Peripheral clock setup

description         - enables or disables peripheral clock for the given GPIO port

input param1        - GPIO port base address
input param2        - enable or disable macros

return              - none

note                - none
*/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA){
            GPIOA_PCLK_EN();
        }
        if(pGPIOx == GPIOC){
            GPIOC_PCLK_EN();
        }
        if(pGPIOx == GPIOD){
            GPIOD_PCLK_EN();
        }
    }else if (EnorDi == DISABLE)
    {
        if(pGPIOx == GPIOA){
            GPIOA_PCLK_DI();
        }
        if(pGPIOx == GPIOC){
            GPIOC_PCLK_DI();
        }
        if(pGPIOx == GPIOD){
            GPIOD_PCLK_DI();
        }
    }
}

/*
GPIO init


description         - initializes the GPIO Pin with the handle provide

input param1        - GPIO handle structure

return              - none

note                - none
*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
    uint32_t temp = 0; 

    // clears the CNF and MODE bits for the specific GPIO Pin in the CFGLR register         
    pGPIOHandle->pGPIOx->CFGLR &= ~( 0xF << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    // configures mode bits
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    // configures type bits
    temp |= pGPIOHandle->GPIO_PinConfig.GPIO_PinType << (2+(4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    // modifies the CFGLR register with the given mode and type for the specific pin
    pGPIOHandle->pGPIOx->CFGLR |= temp;

}

/*
GPIO deinit


description         - resets given GPIO port

input param1        - GPIO port base address

return              - none

note                - none
*/

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if(pGPIOx == GPIOA)
    {
        GPIOA_RESET();
    }else if(pGPIOx == GPIOC)
    {
        GPIOC_RESET();
    }else if(pGPIOx == GPIOD)
    {
        GPIOD_RESET();
    }
}

/*
data read and write
*/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);

/*
IRQ Config and ISR handling
*/

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t Pinnumber);