/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 08 October 2020                                                   */
/*********************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#define MSTK_AHB_DIV_8	0
#define MSTK_AHB		1

#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIOD_INTERVAL    1

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	
}MSTK_Type; 

#define MSTK ((MSTK_Type*) 0xE000E010)


#endif
