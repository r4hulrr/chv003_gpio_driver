#include "ch32v003.h"

typedef struct
{
    uint8_t GPIO_PinNumber;                 /*  @GPIO_PIN_NUM   */
    uint8_t GPIO_PinMode;                   /*  @GPIO_PIN_MODES */
    uint8_t GPIO_PinType;                   /*  @GPIO_PIN_TYPES */
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

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
init and de-init
*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
data read and write
*/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);
uint8_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);

/*
IRQ Config and ISR handling
*/

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t Pinnumber);

/*
@GPIO_PIN_NUM
GPIO possible pin numbers
*/

#define GPIO_PIN_NO_0           0
#define GPIO_PIN_NO_1           1
#define GPIO_PIN_NO_2           2
#define GPIO_PIN_NO_3           3
#define GPIO_PIN_NO_4           4
#define GPIO_PIN_NO_5           5
#define GPIO_PIN_NO_6           6
#define GPIO_PIN_NO_7           7

/*
@GPIO_PIN_MODES
GPIO pin possible modes
*/

#define GPIO_MODE_IN            0
#define GPIO_MODE_OUT10MHz      1
#define GPIO_MODE_OUT2MHz       2
#define GPIO_MODE_OUT30MHz      3
#define GPIO_MODE_IT_RT         4
#define GPIO_MODE_IT_FT         5


/*
@GPIO_PIN_TYPES
GPIO pin possible modes
*/

#define GPIO_TYPE_IN_ANALOG     0       // Analog input mode
#define GPIO_TYPE_IN_FLOAT      1       // floating input mode
#define GPIO_TYPE_IN_PUPD       2       // input with pull-up and pull-down mode

#define GPIO_TYPE_OUT_PP        0       // push-pull output
#define GPIO_TYPE_OUT_OD        1       // open-drain output
#define GPIO_TYPE_AF_PP         2       // alternate function with push-pull output
#define GPIO_TYPE_AF_OD         3       // alternate function with open-drain output

