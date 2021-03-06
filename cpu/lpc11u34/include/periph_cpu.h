/*
 * Copyright (C) 2015-2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_lpc11u34
 * @{
 *
 * @file
 * @brief           CPU specific definitions for internal peripheral handling
 *
 * @author          Paul RATHGEB <paul.rathgeb@skynet.be>
 * @author          Hauke Petersen<hauke.petersen@fu-berlin.de>
 */

#ifndef PERIPH_CPU_H
#define PERIPH_CPU_H

#include <stdint.h>
#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief declare needed generic SPI functions
 * @{
 */
#define PERIPH_SPI_NEEDS_INIT_CS
#define PERIPH_SPI_NEEDS_TRANSFER_BYTE
#define PERIPH_SPI_NEEDS_TRANSFER_REG
#define PERIPH_SPI_NEEDS_TRANSFER_REGS
/** @} */

/**
 * @brief   Length of the CPU_ID in octets
 */
#define CPUID_LEN           (16U)

/**
 * @brief   Define number of available ADC lines
 */
#define ADC_NUMOF           (8U)

/**
 * @brief   Override the default GPIO type
 * @{
 */
#define HAVE_GPIO_T
typedef uint16_t gpio_t;
/** @} */

/**
 * @brief   Define a custom GPIO_PIN macro for the lpc11u34
 */
#define GPIO_PIN(port, pin)     (gpio_t)((port << 8) | pin)

/**
 * @brief   Number of PWM channels per PWM peripheral
 */
#define PWM_CHAN_NUMOF      (3U)

/**
 * @brief   Generate GPIO mode bitfields
 *
 * We use the following bits to encode the pin mode:
 * - bit  0: 0 for input or 1 for output
 * - bit  3: Pull-down resistor enable
 * - bit  4: Pull-up resistor enable
 * - bit 10: Open drain enable
 */
#define GPIO_MODE_BITS(pu, pd, od, out)   ((pu << 4) | (pd << 3) | (od << 10) | out)

#ifndef DOXYGEN
/**
 * @brief   Override GPIO modes
 * @{
 */
#define HAVE_GPIO_MODE_T
typedef enum {
    GPIO_IN    = GPIO_MODE_BITS(0, 0, 0, 0),  /**< in without pull resistor */
    GPIO_IN_PD = GPIO_MODE_BITS(0, 1, 0, 0),  /**< in with pull-down */
    GPIO_IN_PU = GPIO_MODE_BITS(1, 0, 0, 0),  /**< in with pull-up */
    GPIO_OUT   = GPIO_MODE_BITS(0, 0, 0, 1),  /**< push-pull output */
    GPIO_OD    = GPIO_MODE_BITS(0, 0, 1, 1),  /**< open-drain output */
    GPIO_OD_PU = GPIO_MODE_BITS(1, 0, 1, 1),  /**< open-drain output with pull-up */
} gpio_mode_t;
/** @} */

/**
 * @brief   Override the ADC resolution settings
 * @{
 */
#define HAVE_ADC_RES_T
typedef enum {
    ADC_RES_6BIT  = (0x4 << 17),    /**< ADC resolution: 6 bit */
    ADC_RES_8BIT  = (0x2 << 17),    /**< ADC resolution: 8 bit */
    ADC_RES_10BIT = (0x0 << 17),    /**< ADC resolution: 10 bit */
    ADC_RES_12BIT = 1,              /**< ADC resolution: 12 bit, no supported */
    ADC_RES_14BIT = 2,              /**< ADC resolution: 14 bit, no supported */
    ADC_RES_16BIT = 3,              /**< ADC resolution: 16 bit, no supported */
} adc_res_t;
/** @} */
#endif /* ndef DOXYGEN */

/**
 * @brief   PWM configuration
 */
typedef struct {
    LPC_CTxxBx_Type *dev;                   /**< PWM device */
    __IO uint32_t *pins[PWM_CHAN_NUMOF];    /**< set to NULL if channel is not used */
    uint16_t clk_bit;                       /**< clock enable bit */
    uint8_t af;                             /**< alternate pin function */
} pwm_conf_t;

/**
 * @brief   Override SPI clock speed values
 *
 * @note    The values expect the CPU to run at 12MHz
 * @todo    Generalize the SPI driver
 *
 * @{
 */
#define HAVE_SPI_CLK_T
typedef enum {
    SPI_CLK_100KHZ = 119,       /**< drive the SPI bus with 100KHz */
    SPI_CLK_400KHZ =  29,       /**< drive the SPI bus with 400KHz */
    SPI_CLK_1MHZ   =  11,       /**< drive the SPI bus with 1MHz */
    SPI_CLK_5MHZ   =   2,       /**< drive the SPI bus with 5MHz */
    SPI_CLK_10MHZ  =   0        /**< actual: 12 MHz */
} spi_clk_t;
/** @} */

/**
 * @brief   SPI configuration data
 */
typedef struct {
    LPC_SSPx_Type *dev;     /**< SPI device to configure */
    uint32_t preset_bit;    /**< mask of the corresponding preset bit */
    uint32_t ahb_bit;       /**< mask of the corresponding AHB bit */
} spi_conf_t;

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CPU_H */
/** @} */
