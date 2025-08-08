/*
 *******************************************************************************
 * @file           : BUTTON_PROGRAM
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BUTTON SOYRCE  file
 ******************************************************************************
*/

#include <ECUAL/BUTTON/BUTTON_interface.h>


STD_RETURN_TYPES BUTTON_INTIALIZE(pin_cfg *ptr)
{
    STD_RETURN_TYPES RET = E_OK;

    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
         if((ptr->port) == GPIO_PORTH)
         {
      	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
         }
         else
         {
      	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, ptr->port);
         }

         RET =  GPIO_PIN_SET_MODE(ptr);
         RET = GPIO_PIN_SET_PULL_TYPE(ptr);
    }
    return(RET);
}
STD_RETURN_TYPES BUTTON_READ_STATE(pin_cfg *ptr,button_state_t*state)
{
    STD_RETURN_TYPES RET = E_OK;
    logic_t btn_log=  GPIO_LOW;
    if(NULL == ptr || NULL == state)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_GET_PIN_LOGIC(ptr,&btn_log);

		#if  BUTTON_CONNECTION  == BUTTON_ACTIVE_HIGH
		if(btn_log == GPIO_LOW)
		{
			*state = BUTTON_RELEASED;
		}
		else
		{
			*state = BUTTON_PREASED;
		}
		#elif  BUTTON_CONNECTION  == BUTTON_ACTIVE_LOW
		if(btn_log == GPIO_LOW)
		{
			*state = BUTTON_PREASED;
		}
		else
		{
			*state = BUTTON_RELEASED;
		}
		#else
				RET = E_NOK;
		#endif

    }
    return(RET);
}
