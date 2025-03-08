#include "ch32v003.h"

typedef struct
{
    uint8_t GPIO_PinNumber;                 /*  @GPIO_PIN_NUM   */
    uint8_t GPIO_PinMode;                   /*  @GPIO_PIN_MODES */
    uint8_t GPIO_PinType;                   /*  @GPIO_PIN_TYPES */
} R_GPIO_PinConfig_t;

/*
A handle structure for a GPIO pin
*/

typedef struct
{
    R_GPIO_RegDef_t *pGPIOx;                  /* holds base address of GPIO port */
    R_GPIO_PinConfig_t GPIO_PinConfig;        /* holds GPIO pin config settings */
} R_GPIO_Handle_t;

/*
Peripheral clock setup
*/

void R_GPIO_PeriClockControl(R_GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
init and de-init
*/

void R_GPIO_Init(R_GPIO_Handle_t *pGPIOHandle);
void R_GPIO_DeInit(R_GPIO_RegDef_t *pGPIOx);

/*
data read and write
*/

uint8_t R_GPIO_ReadFromInputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);
uint8_t R_GPIO_ReadFromInputPort(R_GPIO_RegDef_t *pGPIOx);
void R_GPIO_WriteToOutputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber, uint8_t value);
void R_GPIO_WriteToOutputPort(R_GPIO_RegDef_t *pGPIOx, uint8_t value);
void R_GPIO_ToggleOutputPin(R_GPIO_RegDef_t *pGPIOx, uint8_t Pinnumber);

/*
IRQ Config and ISR handling
*/

void R_GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
int R_GPIO_IRQHandling(uint8_t Pinnumber);

/*
@GPIO_PIN_NUM
GPIO possible pin numbers
*/

#define R_GPIO_PIN_NO_0           0
#define R_GPIO_PIN_NO_1           1
#define R_GPIO_PIN_NO_2           2
#define R_GPIO_PIN_NO_3           3
#define R_GPIO_PIN_NO_4           4
#define R_GPIO_PIN_NO_5           5
#define R_GPIO_PIN_NO_6           6
#define R_GPIO_PIN_NO_7           7

/*
@GPIO_PIN_MODES
GPIO pin possible modes
*/

#define R_GPIO_MODE_IN            0
#define R_GPIO_MODE_OUT10MHz      1
#define R_GPIO_MODE_OUT2MHz       2
#define R_GPIO_MODE_OUT30MHz      3
#define R_GPIO_MODE_IT_RT         4
#define R_GPIO_MODE_IT_FT         5


/*
@GPIO_PIN_TYPES
GPIO pin possible modes
*/

#define R_GPIO_TYPE_IN_ANALOG     0       // Analog input mode
#define R_GPIO_TYPE_IN_FLOAT      1       // floating input mode
#define R_GPIO_TYPE_IN_PUPD       2       // input with pull-up and pull-down mode

#define R_GPIO_TYPE_OUT_PP        0       // push-pull output
#define R_GPIO_TYPE_OUT_OD        1       // open-drain output
#define R_GPIO_TYPE_AF_PP         2       // alternate function with push-pull output
#define R_GPIO_TYPE_AF_OD         3       // alternate function with open-drain output

