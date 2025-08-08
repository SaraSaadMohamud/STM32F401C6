/*
 ******************************************************************************
 * @file           :CRC_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          :CRC PROGRAM FILE
 ******************************************************************************
*/

#include "../Inc/MACL/CRC/CRC_interface.h"

CRC_statue CRC_INIT()
{
	CRC_statue RET = CRC_VERFACATION_PASS;

	RET = RCC_PERIPHERAL_ENABLE(AHB1, CRC_PERIPHERAL);

	return(RET);
}
CRC_statue CRC_RESET(void)
{
	CRC_statue RET = CRC_VERFACATION_PASS;

	CRC_REG -> CRC_CR |= (1<<RESET_BIT );

	return(RET);
}
CRC_statue CRC_CALCULAT(uint32 *CRC_CAL_VALU , uint32 len , uint32 Buffer_data[])
{
	CRC_statue RET = CRC_VERFACATION_PASS;

	if( (NULL == Buffer_data))
	{
		RET = CRC_VERFACATION_FAILD;
	}
	else
	{
		for(int i=0 ; i<len ; i++)
		{
			CRC_REG ->CRC_DR = Buffer_data[i];
		}

		*CRC_CAL_VALU = CRC_REG ->CRC_DR;
	}
	return(RET);

}
