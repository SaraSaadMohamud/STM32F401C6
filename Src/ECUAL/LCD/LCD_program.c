/*
 ******************************************************************************
 * @file           : LCD_program.C
 * @author         : SARA SAAD MAHMOUD
 * @brief          : LCD program file
 ******************************************************************************
*/

#include "../Inc/ECUAL/LCD/LCD_interface.h"

static STD_RETURN_TYPES LCD_8MODE_SEND_ENABLE(lcd_8mode *PTR);
static STD_RETURN_TYPES LCD_4MODE_SEND_ENABLE(lcd_4mode *PTR);
static STD_RETURN_TYPES LCD_4MODE_SEND_DATA_COMMAND(lcd_4mode *PTR,uint8 data_command);
static STD_RETURN_TYPES LCD_8MODE_SET_CURSOR(lcd_8mode *PTR,uint8 row, uint8 column);
static STD_RETURN_TYPES LCD_4MODE_SET_CURSOR(lcd_4mode *PTR,uint8 row, uint8 column);
STD_RETURN_TYPES LCD_8MODE_INTIALIZED(lcd_8mode *PTR)
{
    STD_RETURN_TYPES RET = E_OK;
    uint8 pins=0;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_MODE(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->Rs_pin));

        RET = GPIO_PIN_SET_MODE(&(PTR->en_pin));
        RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->en_pin));
        RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->en_pin));
        RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->en_pin));

        for(pins=0 ; pins<8 ; pins++)
        {
            RET = GPIO_PIN_SET_MODE(&(PTR->lcd_pins[pins]));
            RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->lcd_pins[pins]));
            RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->lcd_pins[pins]));
            RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->lcd_pins[pins]));
        }
        //__delay_ms(20);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);
        //__delay_ms(5);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);
         // __delay_us(150);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);

        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_CLEAR_DISPLAY);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_CURSOR_RETURN_HOME);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_IECREMENT_ADDRESS_CTR_SHIFT_OFF);
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF );
        RET = LCD_8MODE_SEND_COMMAND(PTR,LCD_8MODE_2LINE_8DOT);
    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_COMMAND(lcd_8mode *PTR,uint8 command)
{
    STD_RETURN_TYPES RET = E_OK;
     uint8 pins=0;

    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->Rs_pin),GPIO_LOW);
        for(pins=0 ; pins<8 ; pins++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[pins]),((command >> pins) & 0x01));
        }
        RET = LCD_8MODE_SEND_ENABLE(PTR);

    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_CHAR_DATA(lcd_8mode *PTR,uint8 data)
{
    STD_RETURN_TYPES RET = E_OK;
    uint8 pins=0;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->Rs_pin),GPIO_HIGH);
        for(pins=0 ; pins<8 ; pins++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[pins]),((data >> pins) & 0x01));
        }
        RET = LCD_8MODE_SEND_ENABLE(PTR);
    }
    return(RET);
}
static STD_RETURN_TYPES LCD_8MODE_SEND_ENABLE(lcd_8mode *PTR)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->en_pin),GPIO_HIGH);
        __delay_us(5);
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->en_pin),GPIO_LOW);
    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_CHAR_DATA_WITH_POS(lcd_8mode *PTR,uint8 data,uint8 row,uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_8MODE_SET_CURSOR(PTR,row,column);
        RET = LCD_8MODE_SEND_CHAR_DATA(PTR,data);
    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_STRING(lcd_8mode *PTR,uint8 *str)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR|| NULL == str)
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; str[i] != '\0' ; i++)
        {
            RET = LCD_8MODE_SEND_CHAR_DATA(PTR,str[i]);
        }
    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_STRING_WITH_POS(lcd_8mode *PTR,uint8 *str,uint8 row, uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR|| NULL == str)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_8MODE_SET_CURSOR(PTR,row,column);
        for(int i=0 ; str[i] != '\0' ; i++)
        {
            RET = LCD_8MODE_SEND_CHAR_DATA(PTR,str[i]);
        }
    }
    return(RET);
}
STD_RETURN_TYPES LCD_8MODE_SEND_CUSTORMER_CHAR(lcd_8mode *PTR,uint8 *data,uint8 mem_pos, uint8 row,uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR|| NULL == data)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_8MODE_SEND_COMMAND(PTR,(LCD_CGRAM_START_ADDRESS+(8*mem_pos)));
        for(int i=0 ; i< 8 ; i++)
        {
            RET =LCD_8MODE_SEND_CHAR_DATA(PTR,data[i]);
        }
        RET = LCD_8MODE_SEND_CHAR_DATA_WITH_POS(PTR,mem_pos,ROW1,column)  ;
    }
    return(RET);
}
static STD_RETURN_TYPES LCD_8MODE_SET_CURSOR(lcd_8mode *PTR,uint8 row, uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        column--;
        switch(row)
        {
            case ROW1:
                RET = LCD_8MODE_SEND_COMMAND(PTR,0X80+column);
                break;
            case ROW2:
                RET = LCD_8MODE_SEND_COMMAND(PTR,0XC0+column);
                break;
            case ROW3:
                RET = LCD_8MODE_SEND_COMMAND(PTR,0X94+column);
                break;
            case ROW4:
                RET = LCD_8MODE_SEND_COMMAND(PTR,0XD4+column);
                break;

        }
    }
    return(RET);
}

STD_RETURN_TYPES LCD_4MODE_INTIALIZED(lcd_4mode *PTR)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_MODE(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->Rs_pin));
        RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->Rs_pin));

        RET = GPIO_PIN_SET_MODE(&(PTR->en_pin));
        RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->en_pin));
        RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->en_pin));
        RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->en_pin));

        for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_MODE(&(PTR->lcd_pins[i]));
            RET = GPIO_PIN_SET_OUTPUT_SPEED(&(PTR->lcd_pins[i]));
            RET = GPIO_PIN_SET_OUTPUT_TYPE(&(PTR->lcd_pins[i]));
            RET = GPIO_PIN_SET_PULL_TYPE(&(PTR->lcd_pins[i]));
        }
        __delay_ms(20);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);
        __delay_ms(5);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);
          __delay_us(150);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_8MODE_1LINE_8DOT);

        __delay_ms(5);


        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_CLEAR_DISPLAY);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_CURSOR_RETURN_HOME);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_IECREMENT_ADDRESS_CTR_SHIFT_OFF);
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF );
        RET = LCD_4MODE_SEND_COMMAND(PTR,LCD_4MODE_2LINE_8DOT);

    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_COMMAND(lcd_4mode *PTR,uint8 command)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->Rs_pin),GPIO_LOW);
        /*
       for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[i]), (command >> (4+i)) & 0x01);
        }
        RET = LCD_4MODE_SEND_ENABLE(PTR);
        for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[i]),( (command)>>i) & 0x01);
        }
        RET = LCD_4MODE_SEND_ENABLE(PTR);*/

        RET = LCD_4MODE_SEND_DATA_COMMAND(PTR,(command>>4));
        RET = LCD_4MODE_SEND_ENABLE(PTR);
        RET = LCD_4MODE_SEND_DATA_COMMAND(PTR,command);
        RET = LCD_4MODE_SEND_ENABLE(PTR);

    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_CHAR_DATA(lcd_4mode *PTR,uint8 data)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->Rs_pin),GPIO_HIGH);
        /*for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[i]),( data >> (4+i)) & 0x01);
        }
        RET = LCD_4MODE_SEND_ENABLE(PTR);
        for(int i=0 ; i<4 ; i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[i]),( (data) >>i) & 0x01);
        }*/
        RET = LCD_4MODE_SEND_DATA_COMMAND(PTR,(data >> 4));
        RET = LCD_4MODE_SEND_ENABLE(PTR);
        RET = LCD_4MODE_SEND_DATA_COMMAND(PTR,data);
        RET = LCD_4MODE_SEND_ENABLE(PTR);
    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_CHAR_DATA_WITH_POS(lcd_4mode *PTR,uint8 data,uint8 row,uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_4MODE_SET_CURSOR(PTR,row,column);
        RET = LCD_4MODE_SEND_CHAR_DATA(PTR,data);
    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_STRING(lcd_4mode *PTR,uint8 *str)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; str[i] != '\0' ; i++)
        {
            RET = LCD_4MODE_SEND_CHAR_DATA(PTR,str[i]);
        }
    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_STRING_WITH_POS(lcd_4mode *PTR,uint8 *str,uint8 row, uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_4MODE_SET_CURSOR(PTR,ROW2,column);
        RET = LCD_4MODE_SEND_STRING(PTR,str);

    }
    return(RET);
}
STD_RETURN_TYPES LCD_4MODE_SEND_CUSTORMER_CHAR(lcd_4mode *PTR,uint8 *data,uint8 mem_pos, uint8 row, uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR|| NULL == data)
    {
        RET = E_NOK;
    }
    else
    {
        RET = LCD_4MODE_SEND_COMMAND(PTR,(LCD_CGRAM_START_ADDRESS+(8*mem_pos)));
        for(int i=0 ; i< 8 ; i++)
        {
            RET =LCD_4MODE_SEND_CHAR_DATA(PTR,data[i]);
        }
        RET = LCD_4MODE_SET_CURSOR(PTR,row,column);
    }
    return(RET);
}
static STD_RETURN_TYPES LCD_4MODE_SEND_ENABLE(lcd_4mode *PTR)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->en_pin),GPIO_HIGH);
        __delay_us(5);
        RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->en_pin),GPIO_LOW);
    }
    return(RET);
}
static STD_RETURN_TYPES LCD_4MODE_SEND_DATA_COMMAND(lcd_4mode *PTR,uint8 data_command)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        for(uint8 i=0 ; i<4 ;i++)
        {
            RET = GPIO_PIN_SET_PIN_LOGIC(&(PTR->lcd_pins[i]),(data_command)>> i &0x01);
        }
    }
    return(RET);
}

static STD_RETURN_TYPES LCD_4MODE_SET_CURSOR(lcd_4mode *PTR,uint8 row, uint8 column)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == PTR)
    {
        RET = E_NOK;
    }
    else
    {
        column--;
        switch(row)
        {
            case ROW1:
                RET =LCD_4MODE_SEND_COMMAND(PTR,0X80+column);
                break;
            case ROW2:
                RET =LCD_4MODE_SEND_COMMAND(PTR,0XC0+column);
                break;
            case ROW3:
                RET =LCD_4MODE_SEND_COMMAND(PTR,0X94+column);
                break;
            case ROW4:
                RET =LCD_4MODE_SEND_COMMAND(PTR,0XD4+column);
                break;
        }
    }
    return(RET);
}
STD_RETURN_TYPES LCD_CONVERT_BYTE(uint8 number, uint8 *str)
{
  STD_RETURN_TYPES RET = E_OK;
    if(NULL == str)
    {
        RET = E_NOK;
    }
    else
    {
        memset(str,'\0',4);
        sprintf(str,"%i",number);
    }
}
STD_RETURN_TYPES LCD_CONVERT_SHORT(uint16 number, uint8 *str)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == str)
    {
        RET = E_NOK;
    }
    else
    {
        memset(str,'\0',6);
        sprintf(str,"%i",number);
    }
}
STD_RETURN_TYPES LCD_CONVERT_INT(uint32 number, uint8 *str)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == str)
    {
        RET = E_NOK;
    }
    else
    {
        memset(str,'\0',11);
        sprintf(str,"%i",number);
    }
}
