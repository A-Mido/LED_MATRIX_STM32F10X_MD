/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 09 October 2020                                                   */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


void HLEDMRX_voidInit(void)

{	
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);
		
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidDisplay(u8	* Copy_u8Data)
{
	while(1)
	{
		/*	column	0*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 0	*/
		SetRowValues(Copy_u8Data[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	1*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 1	*/
		SetRowValues(Copy_u8Data[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	2*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 2	*/
		SetRowValues(Copy_u8Data[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	3*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 3	*/
		SetRowValues(Copy_u8Data[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	4*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 4	*/
		SetRowValues(Copy_u8Data[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	5*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 5	*/
		SetRowValues(Copy_u8Data[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	6*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 6	*/
		SetRowValues(Copy_u8Data[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	7*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 7	*/
		SetRowValues(Copy_u8Data[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, 0);
		MSTK_voidSetBusyWait(2500);
	}
}

static void DisableAllCols(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, 1);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, 1);
}

static void SetRowValues(u8 Copy_u8Data)
{
	u8	Local_u8BIT;
	
	Local_u8BIT = GET_BIT(Copy_u8Data,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
}
static void	HLEDMRX_voidDisplayloop(u8* Copy_u8Data, u32 Copy_u32speed)
{
	for (u32 i = 0 ; i < Copy_u32speed; i++)
	{
		/*	column	0*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 0	*/
		SetRowValues(Copy_u8Data[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	1*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 1	*/
		SetRowValues(Copy_u8Data[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, 0);
		MSTK_voidSetBusyWait(2500);

		/*	column	2*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 2	*/
		SetRowValues(Copy_u8Data[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, 0);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	3*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 3	*/
		SetRowValues(Copy_u8Data[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, 0);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	4*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 4	*/
		SetRowValues(Copy_u8Data[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, 0);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	5*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 5	*/
		SetRowValues(Copy_u8Data[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, 0);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	6*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 6	*/
		SetRowValues(Copy_u8Data[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, 0);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	7*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 7	*/
		SetRowValues(Copy_u8Data[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, 0);
		MSTK_voidSetBusyWait(2500);
	}
}

void HLEDMRX_voidDisplayMotion(u8* Copy_u8DataLarge ,u32 speed)
{
	u8 Copy_u8DataSmall[8];
	for(u8 i = 0; i < Array_Len; i++)
	{
		for(u8 j = 0; j < 8; j++)
		{
			Copy_u8DataSmall[j]= Copy_u8DataLarge[i + j];
		}
		HLEDMRX_voidDisplayloop	(Copy_u8DataSmall, speed);
	}
}

