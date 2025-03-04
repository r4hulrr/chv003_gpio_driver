#include <stdio.h>

/*
base address of Flash , SRAM memory and peripherals
*/

#define FLASH_BASEADDR              0x00000000U
#define SRAM_BASEADDR               0x20000000U
#define PERIPH_BASEADDR             0x40000000U

/*
base address of peripherals available
*/

#define AFIO_BASEADDR               (PERIPH_BASEADDR + 0x00010000)
#define EXTI_BASEADDR               (PERIPH_BASEADDR + 0x00010400)

#define GPIOA_BASEADDR              (PERIPH_BASEADDR + 0x00010800)
#define GPIOC_BASEADDR              (PERIPH_BASEADDR + 0x00011000)
#define GPIOD_BASEADDR              (PERIPH_BASEADDR + 0x00011400)

#define RCC_BASEADDR                (PERIPH_BASEADDR + 0x00021000) 

/*
peripheral register definition structure for AFIO
*/

typedef struct
{
    uint32_t          RESERVED;     /*                                      address offset: 0x00*/
    volatile uint32_t PCFR1;        /* Remap register 1                     address offset: 0x04*/
    volatile uint32_t EXTICR;       /* External interrupt config register   address offset: 0x08*/
} AFIO_RegDef_t;

/*
peripheral register definition structure for EXTI
*/

typedef struct
{
    volatile uint32_t INTENR;       /* Interrupt enable register                address offset: 0x00*/
    volatile uint32_t EVENR;        /* Event enable register                    address offset: 0x04*/
    volatile uint32_t RTENR;        /* Rising edge trigger enable register      address offset: 0x08*/
    volatile uint32_t FTENR;        /* Falling edge trigger enable register     address offset: 0x0C*/
    volatile uint32_t SWIEVR;       /* Soft interrupt event register            address offset: 0x10*/
    volatile uint32_t INTFR;        /* Interrupt flag register                  address offset: 0x14*/
} EXTI_RegDef_t;

/*
peripheral register definition structure for GPIO
*/

typedef struct
{
    volatile uint32_t CFGLR;         /* Port Config register             address offset: 0x00 */
    uint32_t          RESERVED;      /* RESERVED                         address offset: 0x04 */
    volatile uint32_t INDR;          /* Port input data register         address offset: 0x08 */
    volatile uint32_t OUTDR;         /* Port output data register        address offset: 0x0C */
    volatile uint32_t BSHR;          /* Port set/reset register          address offset: 0x10 */
    volatile uint32_t BCR;           /* Port reset register              address offset: 0x14 */
    volatile uint32_t LCKR;          /* Port config lock register        address offset: 0x18 */
} GPIO_RegDef_t;

/*
peripheral register definition structure for RCC
*/

typedef struct
{
    volatile uint32_t CTLR;         /* Clock control register                address offset: 0x00 */
    volatile uint32_t CFGR0;        /* Clock configuration register 0        address offset: 0x04 */
    volatile uint32_t INTR;         /* Clock interrupt register              address offset: 0x08 */
    volatile uint32_t APB2PRSTR;    /* PB2 peripheral reset register         address offset: 0x0C */
    volatile uint32_t APB1PRSTR;    /* PB1 peripheral reset register         address offset: 0x10 */
    volatile uint32_t AHBPCENR;     /* HB peripheral clock enable register   address offset: 0x14 */
    volatile uint32_t APB2PCENR;    /* PB2 peripheral clock enable register  address offset: 0x18 */
    volatile uint32_t APB1PCENR;    /* PB1 peripheral clock enable register  address offset: 0x1C */
    volatile uint32_t RSTSCKR;      /* Control/status register               address offset: 0x24 */
} RCC_RegDef_t;

/*
peripheral definitions 
*/

#define GPIOA                       ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOC                       ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD                       ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define RCC                         ((RCC_RegDef_t*)RCC_BASEADDR)

/*
clock enable macros for GPIOx peripherals
*/

#define GPIOA_PCLK_EN()             (RCC->APB2PCENR |= (1<<2))  
#define GPIOC_PCLK_EN()             (RCC->APB2PCENR |= (1<<4)) 
#define GPIOD_PCLK_EN()             (RCC->APB2PCENR |= (1<<5))

/*
clock disable macros for GPIOx peripherals
*/

#define GPIOA_PCLK_DI()             (RCC->APB2PCENR &= ~(1<<2))  
#define GPIOC_PCLK_DI()             (RCC->APB2PCENR &= ~(1<<4)) 
#define GPIOD_PCLK_DI()             (RCC->APB2PCENR &= ~(1<<5))

/*
macros to reset GPIOx peripherals
*/

#define GPIOA_RESET()               do {RCC->APB2PRSTR |= (1<<2) ; RCC->APB2PRSTR &= ~(1<<2);} while (0)
#define GPIOC_RESET()               do {RCC->APB2PRSTR |= (1<<4) ; RCC->APB2PRSTR &= ~(1<<4);} while (0)
#define GPIOD_RESET()               do {RCC->APB2PRSTR |= (1<<5) ; RCC->APB2PRSTR &= ~(1<<5);} while (0)

//generic macros

#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
