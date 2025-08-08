 /*
 *******************************************************************************
 * @file           : BUZZER_PROGRAMM
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BUZZER SOURCE  file
 ******************************************************************************
*/

#include <ECUAL/BUZZER/BUZZER_interface.h>


STD_RETURN_TYPES BUZZER_INTIATIAZE(pin_cfg *ptr)
{
    STD_RETURN_TYPES RET =E_OK;

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
        RET =  GPIO_PIN_SET_OUTPUT_TYPE(ptr);
        RET =  GPIO_PIN_SET_OUTPUT_SPEED(ptr);
        RET =  GPIO_PIN_SET_PULL_TYPE(ptr);
        RET = GPIO_PIN_GET_PIN_LOGIC(ptr, GPIO_LOW);
    }
    return(RET);
}
STD_RETURN_TYPES BUZZER_TURN_ON(pin_cfg *ptr)
{
    STD_RETURN_TYPES RET =E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
    }
    return(RET);
}
STD_RETURN_TYPES BUZZER_TURN_OFF(pin_cfg *ptr)
{
    STD_RETURN_TYPES RET =E_OK;
     if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
         RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_LOW);
    }
    return(RET);
}
STD_RETURN_TYPES BUZZER_TOGGLE(pin_cfg *ptr)
{
    STD_RETURN_TYPES RET =E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
         RET = GPIO_PIN_TOGGLE_LOGIC(ptr);
    }
    return(RET);
}
