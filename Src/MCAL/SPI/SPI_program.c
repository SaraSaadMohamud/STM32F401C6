/*
 ******************************************************************************
 * @file           : SPI_PROGRAM.C
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SPI SOURCE FILE
 ******************************************************************************
*/
/********************** INCLUDE PART ******************************/
#include "../Inc/MACL/SPI/SPI_interface.h"
/********************** INCLUDE PART ******************************/

/***************** STATIC FUNCTION DECLERATION ********************/

static SPI_REG_CFG* GET_HANDLER(SPI_INDEX index);
static STD_RETURN_TYPES SPI_CLOCK_ENABLE(SPI_INDEX index);
static STD_RETURN_TYPES SPI_DATA_TRNSIEVE_SIZE(SPI_INDEX index);
static STD_RETURN_TYPES SPI_CLOCK_CONFIGURATION(SPI_INDEX index);
static STD_RETURN_TYPES SPI_DATA_TRANSCIVE_DIRECTION(SPI_INDEX index);
static STD_RETURN_TYPES SPI_MASTER_CONTROL(SPI_INDEX index);
static STD_RETURN_TYPES SPI_FRAME_FORMATE(SPI_INDEX index);

/***************** STATIC FUNCTION DECLERATION ********************/

/****************** MAIN FUNCTION DEFINITION *********************/
STD_RETURN_TYPES  SPI_MASTER_INT(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	if(SPI_REG_SEL == NULL)
	{
		RET= E_NOK;
	}
	else
	{
		/* ENABLE SPI CLOCK SOURCE*/
		RET = SPI_CLOCK_ENABLE(index);
		RET = SPI_CLOCK_CONFIGURATION(index);

		/* SELECT DATA FORMATE*/
		RET = SPI_DATA_TRNSIEVE_SIZE(index);

		/*MASTER CONTROL SLAVE*/
		RET = SPI_MASTER_CONTROL(index);

		/* ENABLE MASTER CONFIGURATION*/
		SPI_REG_SEL->SPI_CR1.MSTR_bit = BIT_SET;

		/* SELECT THE FIRST BIT TRANSCIVE */
		RET = SPI_DATA_TRANSCIVE_DIRECTION(index);

		/* SELECT SPI FRAME FORMATE*/
		 RET = SPI_FRAME_FORMATE(index);

		/* ENABLE SPI PERIPHERAL*/
		SPI_REG_SEL->SPI_CR1.SPE_bit = BIT_SET;
	}

	return(RET);
}
STD_RETURN_TYPES  SPI_SLAVE_INT(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	if(SPI_REG_SEL == NULL)
	{
		RET= E_NOK;
	}
	else
	{
		/* ENABLE SPI CLOCK SOURCE*/
		RET = SPI_CLOCK_ENABLE(index);
		RET = SPI_CLOCK_CONFIGURATION(index);

		/* ENABLE SLAVE CONFIGURATION*/
		SPI_REG_SEL->SPI_CR1.MSTR_bit = BIT_CLEAR;

		/* SELECT DATA FORMATE*/
		RET = SPI_DATA_TRNSIEVE_SIZE(index);

		/* SELECT SPI FRAME FORMATE*/
		 RET = SPI_FRAME_FORMATE(index);

		/* SELECT THE FIRST BIT TRANSCIVE */
		RET = SPI_DATA_TRANSCIVE_DIRECTION(index);

		/* ENABLE SPI PERIPHERAL*/
		SPI_REG_SEL->SPI_CR1.SPE_bit = BIT_SET;
	}

	return(RET);
}
STD_RETURN_TYPES  SPI_TRANSCIVE(SPI_INDEX index,uint16 data_t , uint16 *data_r )
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

		SPI_REG_SEL = GET_HANDLER(index);

		if(SPI_REG_SEL == NULL)
		{
			RET= E_NOK;
		}
		else
		{
			/* Transmite Data*/
			while(!(SPI_REG_SEL->SPI_SR.TXE_bit));
			#if   DATA_TRANSIEVE_SIZE == FORMATE_8BIT_DATA
				SPI_REG_SEL->SPI_DR = (uint8)(data_t);
			#elif DATA_TRANSIEVE_SIZE == FORMATE_16BIT_DATA
				SPI_REG_SEL->SPI_DR = (uint16)(data_t);
			#endif
			/* Rescive Data*/
				if(NULL == data_r)
				{
					RET = E_NOK;
				}
				else
				{
					while(!(SPI_REG_SEL->SPI_SR.RXNE_bit));
					#if   DATA_TRANSIEVE_SIZE == FORMATE_8BIT_DATA
						*data_r = (uint8)SPI_REG_SEL->SPI_DR;
					#elif DATA_TRANSIEVE_SIZE == FORMATE_16BIT_DATA
						*data_r = (uint16)SPI_REG_SEL->SPI_DR;
					#endif
				}
		}

	return(RET);
}
/***************** MAIN FUNCTION DEFINITION ********************/

/***************** STATIC FUNCTION DEFINITION ********************/

static SPI_REG_CFG* GET_HANDLER(SPI_INDEX index)
{
	SPI_REG_CFG *VALID_SPI =  SPI1_REG ;
	switch(index)
	{
	case SPI1_ENABLE:
		VALID_SPI =  SPI1_REG ;
		break;

	case SPI2_ENABLE:
		VALID_SPI =  SPI2_REG ;
		break;

	case SPI3_ENABLE:
		VALID_SPI =  SPI3_REG ;
		break;

	case SPI4_ENABLE:
		VALID_SPI =  SPI4_REG ;
		break;

	default:
		VALID_SPI = NULL;
	}
	return(VALID_SPI);
}

static STD_RETURN_TYPES  SPI_CLOCK_ENABLE(SPI_INDEX index)
{
	 STD_RETURN_TYPES RET = E_OK;

	 switch(index)
	 {
		case SPI1_ENABLE:
			RET= RCC_PERIPHERAL_ENABLE(APB2, SPI1_PERIPHERAL);
			break;

		case SPI4_ENABLE:
			RET= RCC_PERIPHERAL_ENABLE(APB2, SPI4_PERIPHERAL);
			break;

		case SPI2_ENABLE:
			RET= RCC_PERIPHERAL_ENABLE(APB1, SPI2_PERIPHERAL);
			break;

		case SPI3_ENABLE:
			RET= RCC_PERIPHERAL_ENABLE(APB1, SPI3_PERIPHERAL);
			break;

		default:
			RET = E_NOK;
			break;
	 }
}

static STD_RETURN_TYPES  SPI_DATA_TRNSIEVE_SIZE(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	#if    DATA_TRANSIEVE_SIZE == FORMATE_8BIT_DATA
		SPI_REG_SEL->SPI_CR1.DFF_bit  = FORMATE_8BIT_DATA;
	#elif  DATA_TRANSIEVE_SIZE == FORMATE_16BIT_DATA
		SPI_REG_SEL->SPI_CR1.DFF_bit  = FORMATE_16BIT_DATA;
	#else
		RET = E_NOK;
	#endif

	return(RET);
}

static STD_RETURN_TYPES SPI_CLOCK_CONFIGURATION(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	#if   DATA_IDEL_CLOCK_  == CPOL_IDEAL_CLK_HIGH
		SPI_REG_SEL->SPI_CR1.CPOL_bit  = CPOL_IDEAL_CLK_HIGH ;
	#elif DATA_IDEL_CLOCK_  == CPOL_IDEAL_CLK_LOW
		SPI_REG_SEL->SPI_CR1.CPOL_bit  = CPOL_IDEAL_CLK_LOW;
	#else
		RET = E_NOK;
	#endif

	#if   DATA_CLOCK_PHASE == FIRST_CLK_PHASE
		SPI_REG_SEL->SPI_CR1.CPHA_bit  = FIRST_CLK_PHASE ;
	#elif DATA_CLOCK_PHASE == SECOND_CLK_PHASE
		SPI_REG_SEL->SPI_CR1.CPHA_bit  = SECOND_CLK_PHASE;
	#else
		RET = E_NOK;
	#endif
	return(RET);
}

static STD_RETURN_TYPES SPI_DATA_TRANSCIVE_DIRECTION(SPI_INDEX index)
{
	 STD_RETURN_TYPES RET = E_OK;
	 SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	 SPI_REG_SEL = GET_HANDLER(index);

	#if    DATA_TRANSIVE_DIR == LSB_transmitted_first
		SPI_REG_SEL->SPI_CR1.LSBFIRST_bit  = LSB_transmitted_first ;
	#elif DATA_TRANSIVE_DIR == MSB_transmitted_first
		SPI_REG_SEL->SPI_CR1.LSBFIRST_bit  = MSB_transmitted_first;
	#else
		RET = E_NOK;
	#endif

	 return(RET);
}

static STD_RETURN_TYPES SPI_MASTER_CONTROL(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	#if   MASTER_CONTROL_SLAVE_ ==  NSS_HW_MANAGE
		SPI_REG_SEL->SPI_CR1.SSM_bit = NSS_HW_MANAGE ;
		SPI_REG_SEL->SPI_CR1.SSI_bit = BIT_SET;
	#elif MASTER_CONTROL_SLAVE_ ==  NSS_SW_MANAGE
		SPI_REG_SEL->SPI_CR1.SSM_bit = NSS_SW_MANAGE;
	#else
		RET = E_NOK;
	#endif

	 return(RET);
}

static STD_RETURN_TYPES SPI_FRAME_FORMATE(SPI_INDEX index)
{
	STD_RETURN_TYPES RET = E_OK;
	SPI_REG_CFG *SPI_REG_SEL =  SPI1_REG ;

	SPI_REG_SEL = GET_HANDLER(index);

	#if   FRAME_FORMATE ==TI_FORMATE_FRAME
		SPI_REG_SEL->SPI_CR2.FRF_bit = TI_FORMATE_FRAME ;
	#elif FRAME_FORMATE == MOTROLA_FORMATE_FRAME
		SPI_REG_SEL->SPI_CR2.FRF_bit = MOTROLA_FORMATE_FRAME ;
	#else
		RET = E_NOK;
	#endif

	 return(RET);
}

/***************** STATIC FUNCTION DEFINITION ********************/
