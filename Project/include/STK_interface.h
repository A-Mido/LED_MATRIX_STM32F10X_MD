/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 08 October 2020                                                   */
/*********************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/*
	Apply clock choice from config file
	Disable systick interrupts
	Disable systick
*/
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle	 (u32 Copy_u32Ticks, void (*Copy_Ptf)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_Ptf)(void));
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);


#endif