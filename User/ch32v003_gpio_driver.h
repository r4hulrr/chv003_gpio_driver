#include "ch32v003.h"

typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
A handle structure for a GPIO pin
*/

typedef struct
{
    GPIO_RegDef_t *pGPIOx;                  /* holds base address of GPIO port */
    GPIO_PinConfig_t GPIO_PinConfig;        /* holds GPIO pin config settings */
}GPIO_Handle_t;

/*
Peripheral clock setup
*/

void GPIO_PeriClockControl(void);

/*
init and de-init
*/

void GPIO_Init(void);
void GPIO_DeInit(void);

/*
data read and write
*/

void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);

/*
IRQ Config and ISR handling
*/

void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);