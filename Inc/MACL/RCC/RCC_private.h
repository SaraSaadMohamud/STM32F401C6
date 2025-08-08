/*
 *******************************************************************************
 * @file           : RCC.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : RCC Private header file
 ******************************************************************************
*/

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

/*************************************      MACRO START      ***********************************************************/

#define  PERIPHERALS_STR_ADD ((volatile uint32*)(0x40000000))
#define  APB1_STR_ADD        ((volatile uint32*)(0x40000000))
#define  APB2_STR_ADD        ((volatile uint32*)(0x40010000))
#define  AHB1_STR_ADD        ((volatile uint32*)(0x40020000))
#define  AHB2_STR_ADD        ((volatile uint32*)(0x50000000))
#define  RCC_STR_ADD         ((volatile uint32*)(0x40023800))
#define  RCC_REG             ((volatile RCC_REG_OFFSET*)(RCC_STR_ADD))

/*************************************      MACRO END       ***********************************************************/

/************************************* USER DATA TYPES START ***********************************************************/

 typedef struct
 {
    volatile uint32 RCC_CR;
    volatile uint32 RCC_PLLCFGR;
    volatile uint32 RCC_CFGR;
    volatile uint32 RCC_CIR;
    volatile uint32 RCC_AHB1RSTR;
    volatile uint32 RCC_AHB2RSTR;
    volatile uint32 Reserved1[2];
    volatile uint32 RCC_APB1RSTR;
    volatile uint32 CC_APB2RSTR;
    volatile uint32 Reserved2[2];
    volatile uint32 RCC_AHB1ENR;
    volatile uint32 RCC_AHB2ENR;
    volatile uint32 Reserved3[2];
    volatile uint32 RCC_APB1ENR;
    volatile uint32 RCC_APB2ENR;
    volatile uint32 Reserved4[2];
    volatile uint32 RCC_AHB1LPEN;
    volatile uint32 RCC_AHB2LPENR;
    volatile uint32 Reserved5[2];
    volatile uint32 RCC_APB1LPENR;
    volatile uint32 RCC_APB2LPENR;
    volatile uint32 Reserved7[2];
    volatile uint32 RCC_BDCR;
    volatile uint32 RCC_CSR;
    volatile uint32 Reserved8[2];
    volatile uint32 RCC_SSCGR;
    volatile uint32 RCC_PLLI2SCFGR;
    volatile uint32 Reserved9;
    volatile uint32 RCC_DCKCFGR;
 }RCC_REG_OFFSET;

 /* ************************************ USER DATA TYPES END   ***********************************************************/


#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
