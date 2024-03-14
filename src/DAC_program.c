/*
 * DAC_program.c
 *
 *  Created on: Jan 23, 2024
 *      Author: philo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "Timer2_interface.h"
#include "STP_interface.h"
#include "DAC_interface.h"



void HR2RDAC_vInit(void)
{
	MGPIO_vSetMode(PORT_B,PIN_7,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_8,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_9,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_10,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_12,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_13,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_14,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_B,PIN_15,MODE_OUTPUT);

	MGPIO_vSetOutputMode(PORT_B,PIN_7,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_8,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_9,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_10,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_12,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_13,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_14,OUTPUT_PUSHPULL,SPEED_MEDUIEM);
	MGPIO_vSetOutputMode(PORT_B,PIN_15,OUTPUT_PUSHPULL,SPEED_MEDUIEM);

}
void HR2RDAC_vPlaySongandDisplayName(const u8 *arr,u32 arrsize, u8 * flag , u8 * song_flag)
{
	u32 L_counter;
	u8 led_counter=0;
	for (L_counter=0;L_counter<arrsize;L_counter++)
	{
		if ((*song_flag) == 1)
		{
			if (L_counter % 180 == 0)
			{
				switch (led_counter)
				{
				case 0:
				case 1:
				case 2:
					S2P_vSendData(0xFE1C);
					S2P_vSendData(0xFD14);
					S2P_vSendData(0xFB1C);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF14);
					S2P_vSendData(0xBF14);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 3:
				case 4:
				case 5:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD1C);
					S2P_vSendData(0xFB14);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF14);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 6:
				case 7:
				case 8:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB1C);
					S2P_vSendData(0xF714);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF1C);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 9:
				case 10:
				case 11:
					S2P_vSendData(0xFE70);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF14);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 12:
				case 13:
				case 14:
					S2P_vSendData(0xFE40);
					S2P_vSendData(0xFD70);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF14);
					S2P_vSendData(0xBF1C);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 15:
				case 16:
				case 17:
					S2P_vSendData(0xFE00);
					S2P_vSendData(0xFD40);
					S2P_vSendData(0xFB70);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF14);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 18:
				case 19:
				case 20:
					S2P_vSendData(0xFEF0);
					S2P_vSendData(0xFD00);
					S2P_vSendData(0xFB40);
					S2P_vSendData(0xF770);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF1C);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 21:
				case 22:
				case 23:
					S2P_vSendData(0xFEB0);
					S2P_vSendData(0xFDF0);
					S2P_vSendData(0xFB00);
					S2P_vSendData(0xF740);
					S2P_vSendData(0xEF70);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 24:
				case 25:
				case 26:
					S2P_vSendData(0xFE00);
					S2P_vSendData(0xFDB0);
					S2P_vSendData(0xFBF0);
					S2P_vSendData(0xF700);
					S2P_vSendData(0xEF40);
					S2P_vSendData(0xDF70);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 27:
				case 28:
				case 29:
					S2P_vSendData(0xFE00);
					S2P_vSendData(0xFD00);
					S2P_vSendData(0xFBB0);
					S2P_vSendData(0xF7F0);
					S2P_vSendData(0xEF00);
					S2P_vSendData(0xDF40);
					S2P_vSendData(0xBF70);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 30:
				case 31:
				case 32:
					S2P_vSendData(0xFE14);
					S2P_vSendData(0xFD00);
					S2P_vSendData(0xFB00);
					S2P_vSendData(0xF7B0);
					S2P_vSendData(0xEFF0);
					S2P_vSendData(0xDF00);
					S2P_vSendData(0xBF40);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 33:
				case 34:
				case 35:
					S2P_vSendData(0xFE1C);
					S2P_vSendData(0xFD14);
					S2P_vSendData(0xFB00);
					S2P_vSendData(0xF700);
					S2P_vSendData(0xEFB0);
					S2P_vSendData(0xDFF0);
					S2P_vSendData(0xBF00);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 36:
				case 37:
				case 38:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD1C);
					S2P_vSendData(0xFB14);
					S2P_vSendData(0xF700);
					S2P_vSendData(0xEF00);
					S2P_vSendData(0xDFB0);
					S2P_vSendData(0xBFF0);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 39:
				case 40:
				case 41:
					S2P_vSendData(0xFE1C);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB1C);
					S2P_vSendData(0xF714);
					S2P_vSendData(0xEF00);
					S2P_vSendData(0xDF00);
					S2P_vSendData(0xBFB0);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 42:
				case 43:
				case 44:
					S2P_vSendData(0xFE14);
					S2P_vSendData(0xFD1C);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF14);
					S2P_vSendData(0xDF00);
					S2P_vSendData(0xBF00);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 45:
				case 46:
				case 47:
					S2P_vSendData(0xFE1C);
					S2P_vSendData(0xFD14);
					S2P_vSendData(0xFB1C);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF14);
					S2P_vSendData(0xBF00);
					S2P_vSendData(0x7F00);
					led_counter = 0;
					break;
				}
			}
		}
		else if ((* song_flag) == 2)
		{
			if (L_counter % 180 == 0)
			{
				switch (led_counter)
				{
				case 0:
				case 1:
				case 2:
					S2P_vSendData(0xFE14);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB18);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF14);
					S2P_vSendData(0xBF1C);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 3:
				case 4:
				case 5:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD14);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF718);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF14);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 6:
				case 7:
				case 8:
					S2P_vSendData(0xFE18);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB14);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF18);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF1C);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 9:
				case 10:
				case 11:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD18);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF714);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF18);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 12:
				case 13:
				case 14:
					S2P_vSendData(0xFE50);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB18);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF14);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF18);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 15:
				case 16:
				case 17:
					S2P_vSendData(0xFE50);
					S2P_vSendData(0xFD50);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF718);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF14);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 18:
				case 19:
				case 20:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD50);
					S2P_vSendData(0xFB50);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF18);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF14);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 21:
				case 22:
				case 23:
					S2P_vSendData(0xFE18);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB50);
					S2P_vSendData(0xF750);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF18);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 24:
				case 25:
				case 26:
					S2P_vSendData(0xFEF0);
					S2P_vSendData(0xFD18);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF750);
					S2P_vSendData(0xEF50);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF18);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 27:
				case 28:
				case 29:
					S2P_vSendData(0xFE80);
					S2P_vSendData(0xFDF0);
					S2P_vSendData(0xFB18);
					S2P_vSendData(0xF710);
					S2P_vSendData(0xEF50);
					S2P_vSendData(0xDF50);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 30:
				case 31:
				case 32:
					S2P_vSendData(0xFE00);
					S2P_vSendData(0xFD80);
					S2P_vSendData(0xFBF0);
					S2P_vSendData(0xF718);
					S2P_vSendData(0xEF10);
					S2P_vSendData(0xDF50);
					S2P_vSendData(0xBF50);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 33:
				case 34:
				case 35:
					S2P_vSendData(0xFE1C);
					S2P_vSendData(0xFD00);
					S2P_vSendData(0xFB80);
					S2P_vSendData(0xF7F0);
					S2P_vSendData(0xEF18);
					S2P_vSendData(0xDF10);
					S2P_vSendData(0xBF50);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 36:
				case 37:
				case 38:
					S2P_vSendData(0xFE14);
					S2P_vSendData(0xFD1C);
					S2P_vSendData(0xFB00);
					S2P_vSendData(0xF780);
					S2P_vSendData(0xEFF0);
					S2P_vSendData(0xDF18);
					S2P_vSendData(0xBF10);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 39:
				case 40:
				case 41:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD1C);
					S2P_vSendData(0xFB14);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF00);
					S2P_vSendData(0xDF80);
					S2P_vSendData(0xBFF0);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 42:
				case 43:
				case 44:
					S2P_vSendData(0xFE18);
					S2P_vSendData(0xFD10);
					S2P_vSendData(0xFB1C);
					S2P_vSendData(0xF714);
					S2P_vSendData(0xEF1C);
					S2P_vSendData(0xDF00);
					S2P_vSendData(0xBF80);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 45:
				case 46:
				case 47:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD18);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF14);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF00);
					S2P_vSendData(0x7F00);
					led_counter++;
					break;
				case 48:
				case 49:
				case 50:
					S2P_vSendData(0xFE10);
					S2P_vSendData(0xFD18);
					S2P_vSendData(0xFB10);
					S2P_vSendData(0xF71C);
					S2P_vSendData(0xEF14);
					S2P_vSendData(0xDF1C);
					S2P_vSendData(0xBF00);
					S2P_vSendData(0x7F00);
					led_counter = 0;
					break;

				}
			}
		}
		if ( (*flag) ==1)
		{
		MGPIO_vWritePin(PORT_B,PIN_7,GET_BIT(arr[L_counter],PIN_7));
		MGPIO_vWritePin(PORT_B,PIN_8,GET_BIT(arr[L_counter],PIN_8));
		MGPIO_vWritePin(PORT_B,PIN_9,GET_BIT(arr[L_counter],PIN_9));
		MGPIO_vWritePin(PORT_B,PIN_10,GET_BIT(arr[L_counter],PIN_10));
		MGPIO_vWritePin(PORT_B,PIN_12,GET_BIT(arr[L_counter],PIN_12));
		MGPIO_vWritePin(PORT_B,PIN_13,GET_BIT(arr[L_counter],PIN_13));
		MGPIO_vWritePin(PORT_B,PIN_14,GET_BIT(arr[L_counter],PIN_14));
		MGPIO_vWritePin(PORT_B,PIN_15,GET_BIT(arr[L_counter],PIN_15));
		TIM2_voidSetBusyWait(200);
		MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
		}
		else
		{
			break;
		}
	}

}


