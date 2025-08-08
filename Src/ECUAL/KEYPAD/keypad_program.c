 /*
 *******************************************************************************
 * @file           : KEYPAD_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : LED SOURCE file
 ******************************************************************************
*/

#include "../Inc/ECUAL/KEYBAD/KEYPAD_interface.h"


uint8 key_value[KEYPAD_ROWS_NUM ][KEYPAD_COLUMN_NUM] = {{'7','8','9','/'},
                                        				{'4','5','6','*'},
														{'1','2','3','-'},
														{'#','0','=','+'}
													   };
STD_RETURN_TYPES KEYPAD_INTIALIZE(keypad_cfg *PTR)
{
    STD_RETURN_TYPES  RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        for(int row_num=0 ; row_num<KEYPAD_ROWS_NUM ; row_num++)
        {
            if((PTR->key_row[row_num].port) == GPIO_PORTH)
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
            }
            else
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1,(PTR->key_row[row_num].port));
            }

            RET =  GPIO_PIN_SET_MODE(&(PTR->key_row[row_num]));
            RET =  GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->key_row[row_num]));
            RET =  GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->key_row[row_num]));
            RET =  GPIO_PIN_SET_PULL_TYPE(&(PTR->key_row[row_num]));
        }
        for(int col_num=0 ;col_num< KEYPAD_COLUMN_NUM ; col_num++)
        {
             if((PTR->key_row[col_num].port) == GPIO_PORTH)
             {
          	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
             }
             else
             {
          	   RET =  RCC_PERIPHERAL_ENABLE(AHB1,(PTR->key_column[col_num].port));
             }

             RET =  GPIO_PIN_SET_MODE(&(PTR->key_column[col_num]));
             RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->key_column[col_num]));
        }
    }
    return(RET);

}
STD_RETURN_TYPES KEYPAD_GET_VALUE(keypad_cfg *PTR,uint8 *value)
{
    STD_RETURN_TYPES  RET = E_OK;
    uint8 col_value = 0;
    uint8 flag=0;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        for(int row_num=0 ; row_num< KEYPAD_ROWS_NUM ; row_num++)
        {
            for(int i=0 ; i< KEYPAD_ROWS_NUM ; i++ )
            {
                RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->key_row[i]),GPIO_LOW);
            }
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->key_row[row_num]),GPIO_HIGH);

            for(int col_num=0 ; col_num <KEYPAD_COLUMN_NUM ; col_num ++)
            {
                RET = GPIO_PIN_GET_PIN_LOGIC(&(PTR->key_column[col_num ]),&col_value); // 1
                if(col_value == GPIO_HIGH)
                {
                    *value = key_value[row_num][col_num];
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                *value  = 'A';
            }
        }
    }
    return(RET);
}
