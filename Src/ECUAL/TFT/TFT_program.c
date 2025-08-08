/*
 ******************************************************************************
 * @file           : TFT_PROGRAM.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : TFT SOURCE FILE
 ******************************************************************************
*/

/************************ INCLUDE PART ****************************/
#include "../Inc/ECUAL/TFT/TFT_interface.h"
#include "../Inc/ECUAL/TFT/TFT_image.h"
/************************ INCLUDE PART ****************************/
static STD_RETURN_TYPES TFT_RESET_FUN(pin_cfg *ptr);
/************************FUNCTION DIFINATION ******************************/

STD_RETURN_TYPES TFT_INI(pin_cfg *CTRL_PIN, pin_cfg *RESET_PIN)
{
	STD_RETURN_TYPES RET = E_OK;

	if((NULL == CTRL_PIN) || (NULL == RESET_PIN))
		{
			RET = E_OK;
		}
		else
		{
			RET = GPIO_PIN_OUTPUT_CFG(CTRL_PIN);
			RET = GPIO_PIN_OUTPUT_CFG(RESET_PIN);
			RET = TFT_RESET_FUN(RESET_PIN);

			/* SLEEP OUT */
			RET = TFT_SEND_COMMAND(CTRL_PIN, SLEEP_OUT_CMD);

			/*SELECT COLOUR MOOD*/
			RET = TFT_SEND_COMMAND(CTRL_PIN, COLOUR_MODE_CMD);

			/* DISPLAY ON*/
			RET = TFT_SEND_COMMAND(CTRL_PIN, DISPLAY_ON_CMD);

		}
	return(RET);
}

STD_RETURN_TYPES TFT_SEND_COMMAND(pin_cfg *CTRL_PIN, uint8 cmd)
{
	STD_RETURN_TYPES RET = E_OK;
    uint16 l_res=0;

	if(NULL == CTRL_PIN)
	{
		RET = E_OK;
	}
	else
	{
		RET = GPIO_PIN_SET_PIN_LOGIC(CTRL_PIN, GPIO_LOW);
		RET = SPI_TRANSCIVE(SPI1_ENABLE,(uint16)cmd, &l_res);
	}

	return(RET);
}

STD_RETURN_TYPES TFT_SEND_Data(pin_cfg *CTRL_PIN, uint8 data)
{
	STD_RETURN_TYPES RET = E_OK;
    uint16 l_res=0;

	if(NULL == CTRL_PIN)
	{
		RET = E_OK;
	}
	else
	{
		RET = GPIO_PIN_SET_PIN_LOGIC(CTRL_PIN, GPIO_HIGH);
		RET = SPI_TRANSCIVE(SPI1_ENABLE,(uint16) data,&l_res);
	}

	return(RET);
}

STD_RETURN_TYPES TFT_IMAGE_DISPLAY(pin_cfg *CTRL_PIN,const uint16 *pos)
{
	STD_RETURN_TYPES RET = E_OK;
    uint8 low_byte = 0;
    uint8 high_byte = 0;

	/*SET X DIRECTION */
	RET = TFT_SEND_COMMAND(CTRL_PIN, X_DIRECTION_CMD);
	RET = TFT_SEND_Data(CTRL_PIN, X_DIR_START_B0);
	RET = TFT_SEND_Data(CTRL_PIN, X_DIR_START_B1);
	RET = TFT_SEND_Data(CTRL_PIN, X_DIR_END_B0);
	RET = TFT_SEND_Data(CTRL_PIN, X_DIR_END_B1);

	/* SET Y DIRECTION */
	RET = TFT_SEND_COMMAND(CTRL_PIN, Y_DIRECTION_CMD);
	RET = TFT_SEND_Data(CTRL_PIN, Y_DIR_START_B0);
	RET = TFT_SEND_Data(CTRL_PIN, Y_DIR_START_B1);
	RET = TFT_SEND_Data(CTRL_PIN, Y_DIR_END_B0);
	RET = TFT_SEND_Data(CTRL_PIN, Y_DIR_END_B1);

	/*write on screen */
	RET = TFT_SEND_COMMAND(CTRL_PIN, SCREEN_WRITE_CMD);

	for(int i=0 ; i<IMAGE_SIZE  ; i++)
	{
		low_byte = (uint8)pos[i];
		high_byte = (uint8)(pos[i] >> 8);

		RET = TFT_SEND_Data(CTRL_PIN, high_byte);
		RET = TFT_SEND_Data(CTRL_PIN, low_byte);
	}

	return(RET);
}

/************************FUNCTION DIFINATION ******************************/
STD_RETURN_TYPES TFT_RESET_FUN(pin_cfg *ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_OK;
	}
	else
	{
		RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
		SYSTICK_SET_WAITING_TIME(200000);

		RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_LOW);
		SYSTICK_SET_WAITING_TIME(2000);

		RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
		SYSTICK_SET_WAITING_TIME(200000);

		RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_LOW);
		SYSTICK_SET_WAITING_TIME(200000);

		RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
		SYSTICK_SET_WAITING_TIME(240000);
	}
	return(RET);
}
