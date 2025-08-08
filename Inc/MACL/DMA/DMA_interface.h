/*
 ******************************************************************************
 * @file           : DMA_INTERFACE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : DMA HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_DMA_DMA_INTERFACE_H_
#define MACL_DMA_DMA_INTERFACE_H_

/*********************************** INCLUDE PART *******************************/

/******************************** ** INCLUDE PART ******************************/

/************************************* MACROS ***********************************/

/************************************* MACROS ***********************************/

/******************************* MACROS FUNCTION  *******************************/

/******************************* MACROS FUNCTION ********************************/

/******************************* USER DATE TYPES ********************************/

typedef enum
{
	BYTE = 0,
	HALF_WORD,
	WORD,
}size_t;

typedef enum
{
	FIFO_1_4 = 0,
	FIFO_1_2,
	FIFO_3_4,
	FIFO_FULL,
}Threshold_t;

typedef struct
{
	uint8 StreamId;
	uint32 *Source_Address;
	uint32 *Destination_Address;
	size_t size;
	Threshold_t thershold;
	uint16 BlockSize;
}STREAM_CFG;

/******************************* USER DATE TYPES ********************************/

/**************************** FUNCTION DECLERATION ******************************/
STD_RETURN_TYPES DMA_INIT();
STD_RETURN_TYPES DMA_SET_STREAM_CFG(STREAM_CFG *ptr);
STD_RETURN_TYPES DMA_ENABLE_STREM(uint8 stream_id);
STD_RETURN_TYPES DMA_CALL_BACK(STREAM_CFG *PTR);
/**************************** FUNCTION DECLERATION ******************************/

#endif /* MACL_DMA_DMA_INTERFACE_H_ */
