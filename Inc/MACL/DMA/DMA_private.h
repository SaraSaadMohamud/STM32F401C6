/*
 ******************************************************************************
 * @file           : DMA_PRIVATE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : DMA HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_DMA_DMA_PRIVATE_H_
#define MACL_DMA_DMA_PRIVATE_H_

/*********************************** INCLUDE PART *******************************/

/******************************** ** INCLUDE PART ******************************/

/************************************* MACROS ***********************************/
#define DMA2_STR_ADD          ((volatile uint32*)0x40026400)
#define DMA1_STR_ADD          ((volatile uint32*)0x40026000)

#define DMA1_REG              ((volatile DMA_REG_CFG*)0x40026000)
#define DMA1_REG              ((volatile DMA_REG_CFG*)0x40026000)
/************************************* MACROS ***********************************/

/******************************* MACROS FUNCTION  *******************************/

/******************************* MACROS FUNCTION ********************************/

/******************************* USER DATE TYPES ********************************/

typedef union
{
	uint32 LISR_REG_SELECT;

	struct
	{
		uint32 FEIF0		:1;
		uint32 RES0			:1;
		uint32 DMEIF0		:1;
		uint32 TEIF0		:1;
		uint32 HTIF0		:1;
		uint32 TCIF0		:1;
		uint32 FEIF1		:1;
		uint32 RES1 		:1;
		uint32 DMEIF1		:1;
		uint32 TEIF1		:1;
		uint32 HTIF1		:1;
		uint32 TCIF1		:1;
		uint32 RES2 		:4;
		uint32 FEIF2		:1;
		uint32 RES3 		:1;
		uint32 DMEIF2		:1;
		uint32 TEIF2		:1;
		uint32 HTIF2		:1;
		uint32 TCIF2		:1;
		uint32 FEIF3		:1;
		uint32 RES4 		:1;
		uint32 DMEIF3		:1;
		uint32 TEIF3		:1;
		uint32 HTIF3		:1;
		uint32 TCIF3		:1;
		uint32 RES4 		:4;
	}LISRbits_t;

}LISR_REG_t;

typedef union
{
	uint32 HISR_REG_SELECT;

	struct
	{
		uint32 FEIF4		:1;
		uint32 RES0			:1;
		uint32 DMEIF4		:1;
		uint32 TEIF4		:1;
		uint32 HTIF4		:1;
		uint32 TCIF4		:1;
		uint32 FEIF5		:1;
		uint32 RES1 		:1;
		uint32 DMEIF5		:1;
		uint32 TEIF5		:1;
		uint32 HTIF5		:1;
		uint32 TCIF5		:1;
		uint32 RES2 		:4;
		uint32 FEIF6		:1;
		uint32 RES3 		:1;
		uint32 DMEIF6		:1;
		uint32 TEIF6		:1;
		uint32 HTIF6		:1;
		uint32 TCIF6		:1;
		uint32 FEIF7		:1;
		uint32 RES4 		:1;
		uint32 DMEIF7		:1;
		uint32 TEIF7		:1;
		uint32 HTIF7		:1;
		uint32 TCIF7		:1;
		uint32 RES4 		:4;
	}HISRbits_t;

}HISR_REG_t;

typedef union
{
	uint32 LIFCR_REG_SELECT;

	struct
	{
		uint32 CFEIF0		:1;
		uint32 RES0			:1;
		uint32 CDMEIF0		:1;
		uint32 CTEIF0 		:1;
		uint32 CHTIF0		:1;
		uint32 CTCIF0		:1;
		uint32 CFEIF1 		:1;
		uint32 RES1 		:1;
		uint32 CDMEIF1		:1;
		uint32 CTEIF1		:1;
		uint32 CHTIF1		:1;
		uint32 CTCIF1		:1;
		uint32 RES2 		:4;
		uint32 CFEIF2		:1;
		uint32 RES3 		:1;
		uint32 CDMEIF2		:1;
		uint32 CTEIF2		:1;
		uint32 CHTIF2		:1;
		uint32 CTCIF2		:1;
		uint32 CFEIF3		:1;
		uint32 RES4 		:1;
		uint32 CDMEIF3		:1;
		uint32 CTEIF3		:1;
		uint32 CHTIF3		:1;
		uint32 CTCIF3		:1;
		uint32 RES4 		:4;
	}LIFCRbits_t;

}LIFCR_REG_t;

typedef union
{
	uint32 HIFCR_REG_SELECT;

	struct
	{
		uint32 CFEIF4		:1;
		uint32 RES0			:1;
		uint32 CDMEIF4		:1;
		uint32 CTEIF4 		:1;
		uint32 CHTIF4		:1;
		uint32 CTCIF4		:1;
		uint32 CFEIF5 		:1;
		uint32 RES1 		:1;
		uint32 CDMEIF5		:1;
		uint32 CTEIF5		:1;
		uint32 CHTIF5		:1;
		uint32 CTCIF5		:1;
		uint32 RES2 		:4;
		uint32 CFEIF6		:1;
		uint32 RES3 		:1;
		uint32 CDMEIF6		:1;
		uint32 CTEIF6		:1;
		uint32 CHTIF6		:1;
		uint32 CTCIF6		:1;
		uint32 CFEIF7		:1;
		uint32 RES4 		:1;
		uint32 CDMEIF7		:1;
		uint32 CTEIF7		:1;
		uint32 CHTIF7		:1;
		uint32 CTCIF7		:1;
		uint32 RES4 		:4;
	}HIFCRbits_t;

}HIFCR_REG_t;

typedef union
{
	uint32 SCR_REF_ALLbits;

	typedef struct
	{
		uint32 EN			:1;
		uint32 DMEIE		:1;
		uint32 TEIE			:1;
		uint32 HTIE 		:1;
		uint32 TCIE			:1;
		uint32 PFCTRL		:1;
		uint32 DIR			:2;
		uint32 CIRC			:1;
		uint32 PINC			:1;
		uint32 MINC			:1;
		uint32 PSIZE		:2;
		uint32 MSIZE		:2;
		uint32 PINCOS		:1;
		uint32 PL			:2;
		uint32 DBM			:1;
		uint32 CT			:1;
		uint32 RES0			:1;
		uint32 PBURST		:2;
		uint32 MBURST 		:2;
		uint32 CHSEL		:2;
		uint32 RES1			:4;
	}SCRbits_t;

}SCR_REG_t;

typedef union
{
	uint32 SFCR_REF_ALLbits;

	typedef struct
	{
		uint32 FTH			:2;
		uint32 DMDIS		:1;
		uint32 FS			:2;
		uint32 RES0			:1;
		uint32 FEIE			:1;
		uint32 RES1         :8;
		uint32 RES2         :16;
	}SFCRbits_t;

}SFCR_REG_t;

typedef struct
{
	SCR_REG_t  DMA_SCR;
	uint32     DMA_SNDTR;
	uint32 	   DMA_SPAR;
	uint32     DMA_SM0AR;
	uint32     DMA_SM1AR;
	SFCR_REG_t DMA_SFCR;

}DMA_stream_t;

typedef struct
{
	LISR_REG_t   DMA_LISR;
	HISR_REG_t   DMA_HISR;
	LIFCR_REG_t  DMA_LIFCR;
	uint32     	 DMA_HIFCR;
	DMA_stream_t SArr[8];

}DMA_REG_CFG;
/******************************* USER DATE TYPES ********************************/

/**************************** FUNCTION DECLERATION ******************************/

/**************************** FUNCTION DECLERATION ******************************/

#endif /* MACL_DMA_DMA_PRIVATE_H_ */
