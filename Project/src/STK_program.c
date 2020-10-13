/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 08 October 2020                                                   */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Make a global pointer to function*/
static void (*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static u32 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if MSTK_CLOCK_SOURCE == MSTK_AHB_DIV_8
		/* Disable systick - Disable interrupts - Make clock AHB/8 */
		MSTK->CTRL = 0;
	#elif MSTK_CLOCK_SOURCE == MSTK_AHB
		/* Disable systick - Disable interrupts - Make clock AHB  */
		MSTK->CTRL = 0x00000004;
	#else
		#error("Wrong choice to the clock")
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*check the value before assigning */
	if (Copy_u32Ticks <= 0x00FFFFFF)
	{
		MSTK->LOAD = Copy_u32Ticks;
	}
	else
	{
		// return error
	}
	
	/*Enable the counter */ 
	SET_BIT(MSTK->CTRL, 0);
	
	/*Wait till the flag is raised */
	while (GET_BIT(MSTK->CTRL, 16) == 0);
	
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
	
}

void MSTK_voidSetIntervalSingle	 (u32 Copy_u32Ticks, void (*Copy_Ptf)(void))
{
	/*check the value before assigning */
	if (Copy_u32Ticks <= 0x00FFFFFF)
	{
		MSTK->LOAD = Copy_u32Ticks;
	}
	else
	{
		// return error
	}
	
	/*enable the counter */ 
	SET_BIT(MSTK->CTRL, 0);
	SET_BIT(MSTK->CTRL, 1);
	
	
	MSTK_u8ModeOfInterval = MSTK -> LOAD;
	MSTK->LOAD = 0;
	
	MSTK_CallBack = Copy_Ptf;
	
	
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_Ptf)(void))
{
	/*check the value before assigning */
	if (Copy_u32Ticks <= 0x00FFFFFF)
	{
		MSTK->LOAD = Copy_u32Ticks;
	}
	else
	{
		// return error
	}
	/*enable the counter */ 
	SET_BIT(MSTK->CTRL, 0);
	SET_BIT(MSTK->CTRL, 1);
	
	MSTK_u8ModeOfInterval = MSTK->LOAD;
	
	MSTK_CallBack = Copy_Ptf;
	
}

void MSTK_voidStopInterval(void)
{
	MSTK -> VAL  = 0;
	MSTK -> LOAD = 0;
	/*Disable STK interrupt */ 
	CLR_BIT(MSTK->CTRL, 0);
	
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 1);
	
}

u32 MSTK_u32GetElapsedTime(void)
{
	return MSTK->LOAD - MSTK->VAL;
}

u32 MSTK_u32GetRemainingTime(void)
{
	return MSTK->VAL;
}

void SysTick_Handler(void)
{
	/*
	u8 Local_u8Temp;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		// Disable STK interrupt 
		CLR_BIT(MSTK->CTRL, 0);
	
		// Stop Timer 
		SET_BIT(MSTK->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	
	(*MSTK_CallBack)();
	
	Local_u8Temp = GET_BIT(MSTK->CTRL, 16)
	*/
}
