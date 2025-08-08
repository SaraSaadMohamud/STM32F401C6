 /*
 *******************************************************************************
 * @file           : common.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : common usage  file
 ******************************************************************************
*/

#ifndef MCAL_MATH_H_
#define MCAL_MATH_H_

#define CLEAR_BIT(REG,BIT)  ((REG) &= ~(1 << BIT)) 			/* MACRO FUNCTION TO CLEAR BIT*/
#define SET_BIT(REG,BIT)    ((REG) |=  (1 << BIT)) 			/* MACRO FUNCTION TO SET BIT*/
#define TOGGLE_BIT(REG,BIT) ((REG) ^=  (1 << BIT)) 			/* MACRO FUNCTION TO TOGGLE BIT*/
#define READ_BIT(REG,BIT)   ((REG)  =  (REG >> BIT) & 1)    /* MACRO FUNCTION TO READ BIT*/

#define  E_OK        1  /* RETURN OF FUNCTION IF ALL THING IS OK*/
#define  E_NOK       0  /* RETURN OF FUNCTION IF THERE IS AN ERROR*/

#define  NULL        (void*)(0)

#endif /* MCAL_MATH_H_ */
