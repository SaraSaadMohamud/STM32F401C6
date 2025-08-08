/*
 ******************************************************************************
 * @file           : FLASH_PRIVATE.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : FLASH HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_FLASH_FLASH_PRIVATE_H_
#define MACL_FLASH_FLASH_PRIVATE_H_

/************************ INCLUDE PART ***************************/

/************************ INCLUDE PART ***************************/

/**************************** MACROS *****************************/

#define FLASH_STR_ADD    ((volatile uint32*)0x40023C00)
#define FLASH_REG		 ((volatile FLASH_REG_CFG*)0x40023C00)

/**************************** MACROS *****************************/

/************************ MACROS FUNCTION ************************/

/************************ MACROS FUNCTION ************************/

/************************* USER DATA TYPES *************************/
typedef struct
{
	uint32 LATENCY       :4;
	uint32 RESERVE0      :4;
	uint32 PRFTEN        :1;
	uint32 ICEN          :1;
	uint32 DCEN          :1;
	uint32 ICRST         :1;
	uint32 DCRST         :1;
	uint32 RESERVE1      :1;
	uint32 RESERVE2      :16;
}FLASH_ACR_bits;

typedef union
{
    struct
	{
		uint32 EOP           :1;
		uint32 OPERR         :1;
		uint32 RES0          :1;
		uint32 WRPERR        :1;
		uint32 PGAERR        :1;
		uint32 PGPERR        :1;
		uint32 PGSERR        :1;
		uint32 RDERR         :1;
		uint32 RES1          :7;
		uint32 BSY           :1;
		uint32 RES2          :15;
	}FLASH_STRUCT;

	uint32 FLASH_SR_REG ;

}FLASH_SR_bits;

typedef struct
{
	uint32 PG		   	 :1;
	uint32 SER		   	 :1;
	uint32 MER		   	 :1;
	uint32 SNB		   	 :4;
	uint32 RES0		   	 :1;
	uint32 PSIZE		 :2;
	uint32 RES1		   	 :6;
	uint32 STRT		   	 :1;
	uint32 RES2		   	 :7;
	uint32 EOPIE		 :1;
	uint32 ERRIE		 :1;
	uint32 RES3		   	 :5;
	uint32 LOCK		   	 :1;
}FLASH_CR_bits;

typedef struct
{
	uint32  OPTLOCK		 :1;
	uint32  OPTSTRT		 :1;
	uint32  BOR_LEV		 :1;
	uint32  RESERVE0	 :1;
	uint32  WDG_SW		 :1;
	uint32  nRST_STOP	 :1;
	uint32  nRST_STDBY	 :1;
	uint32  RDP		     :8;
	uint32  nWRP1		 :1;
	uint32  nWRP2		 :1;
	uint32  nWRP3		 :1;
	uint32  nWRP4		 :1;
	uint32  nWRP5		 :1;
	uint32  nWRP6		 :1;
	uint32  nWRP7		 :1;
	uint32  nWRP8		 :1;
	uint32  RESERVE1	 :7;
	uint32  SPRMOD		 :1;

}FLASH_OPTCR_bits;

typedef struct
{
	FLASH_ACR_bits 	 FLASH_ACR;
	uint32 			 FLASH_KEYR;
	uint32 			 FLASH_OPTKEYR;
	FLASH_SR_bits 	 FLASH_SR;
	FLASH_CR_bits 	 FLASH_CR;
	FLASH_OPTCR_bits FLASH_OPTCR;

}FLASH_REG_CFG;
/************************* USER DATA TYPES *************************/

/*********************** FUNCTION DECLERATION ************************/

/*********************** FUNCTION DECLERATION ************************/

#endif /* MACL_FLASH_FLASH_PRIVATE_H_ */
