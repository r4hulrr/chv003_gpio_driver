#include <stdio.h>

/*
base address of Flash , SRAM memory and peripherals
*/

#define R_FLASH_BASEADDR              0x00000000U
#define R_SRAM_BASEADDR               0x20000000U
#define R_PERIPH_BASEADDR             0x40000000U

/*
base address of peripherals available
*/

#define R_AFIO_BASEADDR               (R_PERIPH_BASEADDR + 0x00010000)
#define R_EXTI_BASEADDR               (R_PERIPH_BASEADDR + 0x00010400)

#define R_GPIOA_BASEADDR              (R_PERIPH_BASEADDR + 0x00010800)
#define R_GPIOC_BASEADDR              (R_PERIPH_BASEADDR + 0x00011000)
#define R_GPIOD_BASEADDR              (R_PERIPH_BASEADDR + 0x00011400)

#define R_RCC_BASEADDR                (R_PERIPH_BASEADDR + 0x00021000) 

/*
PFIC Register address
*/

#define R_PFIC_IENR1                  ((volatile uint32_t*)0xE000E100)
#define R_PFIC_IENR2                  ((volatile uint32_t*)0xE000E104)

#define R_PFIC_IRER1                  ((volatile uint32_t*)0xE000E180)
#define R_PFIC_IRER2                  ((volatile uint32_t*)0xE000E184)

#define R_PFIC_IPRIOR                 ((volatile uint8_t*)0xE000E400)

/*
peripheral register definition structure for AFIO
*/

typedef struct
{
    uint32_t          RESERVED;     /*                                      address offset: 0x00*/
    volatile uint32_t PCFR1;        /* Remap register 1                     address offset: 0x04*/
    volatile uint32_t EXTICR;       /* External interrupt config register   address offset: 0x08*/
} R_AFIO_RegDef_t;

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
} R_EXTI_RegDef_t;

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
} R_GPIO_RegDef_t;

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
} R_RCC_RegDef_t;

/*
peripheral definitions 
*/

#define R_AFIO                        ((R_AFIO_RegDef_t*)R_AFIO_BASEADDR)
#define R_EXTI                        ((R_EXTI_RegDef_t*)R_EXTI_BASEADDR)
#define R_GPIOA                       ((R_GPIO_RegDef_t*)R_GPIOA_BASEADDR)
#define R_GPIOC                       ((R_GPIO_RegDef_t*)R_GPIOC_BASEADDR)
#define R_GPIOD                       ((R_GPIO_RegDef_t*)R_GPIOD_BASEADDR)
#define R_RCC                         ((R_RCC_RegDef_t*)R_RCC_BASEADDR)

/*
clock enable macros for GPIOx peripherals
*/

#define R_GPIOA_PCLK_EN()             (R_RCC->APB2PCENR |= (1<<2))  
#define R_GPIOC_PCLK_EN()             (R_RCC->APB2PCENR |= (1<<4)) 
#define R_GPIOD_PCLK_EN()             (R_RCC->APB2PCENR |= (1<<5))

/*
clock disable macros for GPIOx peripherals
*/

#define R_GPIOA_PCLK_DI()             (R_RCC->APB2PCENR &= ~(1<<2))  
#define R_GPIOC_PCLK_DI()             (R_RCC->APB2PCENR &= ~(1<<4)) 
#define R_GPIOD_PCLK_DI()             (R_RCC->APB2PCENR &= ~(1<<5))

/*
macros to reset GPIOx peripherals
*/

#define R_GPIOA_RESET()               do {R_RCC->APB2PRSTR |= (1<<2) ; R_RCC->APB2PRSTR &= ~(1<<2);} while (0)
#define R_GPIOC_RESET()               do {R_RCC->APB2PRSTR |= (1<<4) ; R_RCC->APB2PRSTR &= ~(1<<4);} while (0)
#define R_GPIOD_RESET()               do {R_RCC->APB2PRSTR |= (1<<5) ; R_RCC->APB2PRSTR &= ~(1<<5);} while (0)

/*
macro that returns a code for a given gpio base address(x)
*/

#define R_GPIO_BASEADDR_TOCODE(x)  ((x == R_GPIOA) ? 0 : \
                                  (x == R_GPIOC) ? 2 : \
                                  (x == R_GPIOD) ? 3 : -1 )

//generic macros

#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
