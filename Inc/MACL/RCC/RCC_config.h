 /*
 *******************************************************************************
 * @file           : RCC.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : RCC Config header file
 ******************************************************************************
*/


#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

#define RCC_CLK_SRC HSI_CLK_SRC

/* HSE OPTIONS*/
#if RCC-CLK_SRC== HSE_CLK_SRC
#define HSE_SOURCE CRYSTAL_HSE_CLK_SRC
#endif

/*PLL OPTIONS*/
#if RCC_CLK_SRC == PLL_CLK_SRC
#define PLL_SRC  PLL_HSI_CLK_SRC
#endif

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
