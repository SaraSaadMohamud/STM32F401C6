 /*
 *******************************************************************************
 * @file           : MOTOR_PROGRAM.C
 * @author         : SARA SAAD MAHMOUD
 * @brief          : MOTOR SOURCE file
 ******************************************************************************
*/

#include <ECUAL/SEGEMENT/SEGMENT_interface.h>
STD_RETURN_TYPES SEGEMENT_INTIALIZE(segment_cfg_t *ptr)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; i<4 ; i++)
        {
            if((ptr->segment_pins[i].port) == GPIO_PORTH)
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
            }
            else
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1,(ptr->segment_pins[i].port));
            }

            RET =  GPIO_PIN_SET_MODE(&(ptr->segment_pins[i]));
            RET =  GPIO_PIN_SET_OUTPUT_TYPE(&(ptr->segment_pins[i]));
            RET =  GPIO_PIN_SET_OUTPUT_SPEED(&(ptr->segment_pins[i]));
            RET =  GPIO_PIN_SET_PULL_TYPE(&(ptr->segment_pins[i]));
        }


    }
    return(RET);
}
STD_RETURN_TYPES SEGEMENT_WRITE_NUMBER(segment_cfg_t *ptr,uint8 number)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr || number > 10 || number < 0) //5 // 0101 BITWISE
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(ptr->segment_pins[i]),((number >> i)&0x01));
        }
    }
    return(RET);
}
