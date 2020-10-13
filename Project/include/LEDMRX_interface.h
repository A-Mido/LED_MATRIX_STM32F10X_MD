/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 09 October 2020                                                   */
/*********************************************************************************/


#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8	* Copy_u8Data);
void HLEDMRX_voidDisplayMotion(u8* Copy_u8DataLarge , u32 speed);

#endif
