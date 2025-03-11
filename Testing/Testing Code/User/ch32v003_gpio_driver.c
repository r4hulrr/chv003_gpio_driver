#include "ch32v003_gpio_driver.h"
/*
Peripheral clock setup

description         - enables or disables peripheral clock for the given GPIO port

input param1        - GPIO port base address
input param2        - enable or disable macros

return              - none

note                - none
*/

void R_GPIO_PeriClockControl(R_GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == R_GPIOA){
            R_GPIOA_PCLK_EN();
        }
        if(pGPIOx == R_GPIOC){
            R_GPIOC_PCLK_EN();
        }
        if(pGPIOx == R_GPIOD){
            R_GPIOD_PCLK_EN();
        }
    }else if (EnorDi == DISABLE)
    {
        if(pGPIOx == R_GPIOA){
            R_GPIOA_PCLK_DI();
        }
        if(pGPIOx == R_GPIOC){
            R_GPIOC_PCLK_DI();
        }
        if(pGPIOx == R_GPIOD){
            R_GPIOD_PCLK_DI();
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

void R_GPIO_Init(R_GPIO_Handle_t *pGPIOHandle){
    uint32_t temp = 0; 

    R_GPIO_PeriClockControl(pGPIOHandle->pGPIOx,ENABLE);

    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= R_GPIO_MODE_OUT30MHz)
    {
        // clears the CNF and MODE bits for the specific GPIO Pin in the CFGLR register         
        pGPIOHandle->pGPIOx->CFGLR &= ~( 0xF << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // configures mode bits
        temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        // configures type bits
        temp |= pGPIOHandle->GPIO_PinConfig.GPIO_PinType << (2 + (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // modifies the CFGLR register with the given mode and type for the specific pin
        pGPIOHandle->pGPIOx->CFGLR |= temp;
    }else
    {   
        // enables the exti line based on the given GPIO Pin number and port
        uint8_t portcode = R_GPIO_BASEADDR_TOCODE(pGPIOHandle->pGPIOx);
        R_AFIO->EXTICR |= (portcode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        R_EXTI->INTENR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        // configures for falling edge and rising edge trigger
        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == R_GPIO_MODE_IT_FT)
        {
            // enables falling edge trigger on selected EXTI line
            R_EXTI->FTENR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            // clears corresponding rising edge trigger
            R_EXTI->RTENR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == R_GPIO_MODE_IT_RT)
        {
            // enables rising edge trigger on selected EXTI line
            R_EXTI->RTENR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            // clears corresponding falling edge trigger
            R_EXTI->FTENR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
    }

}

/*
GPIO deinit


description         - resets given GPIO port

input param1        - GPIO port base address

return              - none

note                - none
*/

void R_GPIO_DeInit(R_GPIO_RegDef_t *pGPIOx)
{
    if(pGPIOx == R_GPIOA)
    {
        R_GPIOA_RESET();
    }else if(pGPIOx == R_GPIOC)
    {
        R_GPIOC_RESET();
    }else if(pGPIOx == R_GPIOD)
    {
        R_GPIOD_RESET();
    }
}

/*
GPIO read from input pin


description         - returns value stored in given GPIO pin 

input param1        - GPIO port base address 
input param2        - GPIO pin number 

return              - value stored in the given GPIO pin

note                - none
*/

uint8_t R_GPIO_ReadFromInputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber)
{
    uint8_t value;
    value = (uint8_t)((pGPIOx->INDR >> Pinnumber) & 0x00000001);
    return value;
}

/*
GPIO read from input port


description         - returns value stored in given GPIO port 

input param1        - GPIO port base address 

return              - value stored in the given GPIO port

note                - none
*/

uint8_t R_GPIO_ReadFromInputPort(R_GPIO_RegDef_t *pGPIOx)
{
    uint8_t value;
    value = (uint8_t)pGPIOx->INDR;
    return value;
}

/*
GPIO write to output pin


description         - writes given value to stated GPIO pin 

input param1        - GPIO port base address 
input param2        - GPIO pin number 
input param3        - value to be written

return              - none

note                - none
*/

void R_GPIO_WriteToOutputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber, uint8_t value)
{
    if(value == SET)
    {
        pGPIOx->OUTDR |= ((1 << Pinnumber));
    }else if (value == RESET)
    {
        pGPIOx->OUTDR &= (~(1 << Pinnumber));
    }
}

/*
GPIO write to output port


description         - writes given value to stated GPIO port 

input param1        - GPIO port base address 
input param2        - value to be written

return              - none

note                - none
*/

void R_GPIO_WriteToOutputPort(R_GPIO_RegDef_t *pGPIOx, uint8_t value)
{
    pGPIOx->OUTDR = value;
}

/*
GPIO toggle output pin


description         - toggles value in stated GPIO pin 

input param1        - GPIO port base address
input param2        - GPIO pin number 

return              - none

note                - none
*/

void R_GPIO_ToggleOutputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber)
{
    pGPIOx->OUTDR ^= (1 << Pinnumber);
}

/*
IRQ Config and ISR handling


description         - enables or disables a specific interrupt along with its priority 

input param1        - Interrupt no.
input param2        - Interrupt priority
input param3        - Enable or disable macro

return              - none

note                - can be used with the GPIO init to enable the EXTI interrupt in the CPU's PFIC
*/
void R_GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(IRQNumber <= 31)
        {
            // configure PFIC IENR1 register
            *R_PFIC_IENR1 |= ( 1 << IRQNumber);
        }else if (IRQNumber > 31 && IRQNumber <= 38)
        {
            // configure PFIC IENR2 register
            *R_PFIC_IENR2 |= (1 << (IRQNumber - 32));
        }
        R_PFIC_IPRIOR[IRQNumber] = IRQPriority;
    }else 
    {
        if(IRQNumber <= 31)
        {
            // configure PFIC IRER1 register
            *R_PFIC_IRER1 |= ( 1 << IRQNumber);
        }else if (IRQNumber > 31 && IRQNumber <= 38)
        {
            // configure PFIC IRER2 register
            *R_PFIC_IRER2 |= (1 << (IRQNumber - 32));
        }
    }
}

/*
IRQ handling


description         - can be used to check if the EXTI interrupt configured is triggered

input param1        - GPIO Pin number

return              - none

note                - none
*/

int R_GPIO_IRQHandling(uint8_t Pinnumber)
{
    if(R_EXTI->INTFR == (1 << Pinnumber))
    {
        R_EXTI->INTFR |= ( 1 << Pinnumber);
        return 1;
    }else {
        return 0;
    }
}