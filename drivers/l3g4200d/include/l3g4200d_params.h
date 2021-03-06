/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_l3g4200d
 *
 * @{
 * @file
 * @brief       Default configuration for L3G4200D devices
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef L3G4200D_PARAMS_H
#define L3G4200D_PARAMS_H

#include "board.h"
#include "l3g4200d.h"
#include "saul_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Set default configuration parameters
 * @{
 */
#ifndef L3G4200D_PARAM_I2C
#define L3G4200D_PARAM_I2C          I2C_DEV(0)
#endif
#ifndef L3G4200D_PARAM_ADDR
#define L3G4200D_PARAM_ADDR         (0x68)
#endif
#ifndef L3G4200D_PARAM_INT1
#define L3G4200D_PARAM_INT1         (GPIO_PIN(0, 0))
#endif
#ifndef L3G4200D_PARAM_INT2
#define L3G4200D_PARAM_INT2         (GPIO_PIN(0, 1))
#endif
#ifndef L3G4200D_PARAM_MODE
#define L3G4200D_PARAM_MODE         (L3G4200D_MODE_200_25)
#endif
#ifndef L3G4200D_PARAM_SCALE
#define L3G4200D_PARAM_SCALE        (L3G4200D_SCALE_500DPS)
#endif

#define L3G4200D_PARAMS_DEFAULT     { .i2c      = L3G4200D_PARAM_I2C, \
                                      .addr     = L3G4200D_PARAM_ADDR, \
                                      .int1_pin = L3G4200D_PARAM_INT1, \
                                      .int2_pin = L3G4200D_PARAM_INT2, \
                                      .mode     = L3G4200D_PARAM_MODE, \
                                      .scale    = L3G4200D_PARAM_SCALE }
/**@}*/

/**
 * @brief   Allocate some memory to store the actual configuration
 */
static const l3g4200d_params_t l3g4200d_params[] =
{
#ifdef L3G4200D_PARAMS_CUSTOM
    L3G4200D_PARAMS_CUSTOM,
#else
    L3G4200D_PARAMS_DEFAULT,
#endif
};

/**
 * @brief   Additional meta information to keep in the SAUL registry
 */
static const saul_reg_info_t l3g4200d_saul_info[] =
{
    { .name = "l3g4200d" }
};

#ifdef __cplusplus
}
#endif

#endif /* L3G4200D_PARAMS_H */
/** @} */
