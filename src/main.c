#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "Timer2_interface.h"
#include "Timer3_interface.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "STP_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "DAC_interface.h"
#include "main_conf.h"

#include "img.h"
#include "img2.h"
#include "lalaly.h"
#include "nour.h"



int main (void)
{
	//****************************// ----> Enable RCC
	MRCC_vInt();
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);
	MRCC_vEnable(RCC_APB2,APB2_SYSCFG);
	MRCC_vEnable(RCC_APB1,APB1_TIM2);
	MRCC_vEnable(RCC_APB1,APB1_TIM3);
	MRCC_vEnable(RCC_APB2,APB2_SPI1);
	//********************// --------------> Configure TFT pins
	MGPIO_vSetMode(PORT_A,PIN_0,MODE_OUTPUT);
	MGPIO_vSetMode(PORT_A,PIN_1,MODE_OUTPUT);
	MGPIO_vSetOutputMode(PORT_A,PIN_0,OUTPUT_PUSHPULL,SPEED_LOW);
	MGPIO_vSetOutputMode(PORT_A,PIN_1,OUTPUT_PUSHPULL,SPEED_LOW);
	//**************************//-----------> Configure IR Pin
	MGPIO_vSetMode(PORT_B, PIN_0, MODE_INPUT);
	MGPIO_vSetInputMode(PORT_B, PIN_0, INPUT_PULLUP);
	//*********************************//----------------> Configure SPI Pins
	MGPIO_vSetMode(PORT_A,PIN_4,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_5,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_6,MODE_ALTERNATIVE);
	MGPIO_vSetMode(PORT_A,PIN_7,MODE_ALTERNATIVE);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_4,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_5,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_6,ALTR_SPI);
	MGPIO_vSetAlternativeMode(PORT_A,PIN_7,ALTR_SPI);
	//*******************************************//
	S2P_vInit();
	//****************************************//
	HR2RDAC_vInit();
	//*************************************//
	TIM2_voidInit();
	//************************************//
	SPI1_voidInit();
	//********************************//
	MSYSYTICK_voidInit();
	TFT_voidvInit();
	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
	//***************************//
	MEXTI_voidInerruptSetPort(EXTI_LineZero,PORT_B);
	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero,EXTI_Enable);
	MEXTI0_voidCallBack(voidGetFrame);
	//**********************//
	NVIC_VoidSetInterruptGroupMode(Group16Sub0);
	NVIC_VoidSetInterruptPriority(EXTI_1,GROUP_1,SUB_GROUP_0);
	NVIC_vEnable(EXTI_1);
	//****************************//

	while (1)
	{
		switch (G_Flag) {
		case CHANNEL_1:
			play_flag = PLAY;
			TFT_voidDisplay(img);
			HR2RDAC_vPlaySongandDisplayName(__01_Nour_El_Ain_raw,SONG_1_LENGTH,&play_flag , &song_flag);
			break;
		case CHANNEL_2:
			play_flag = PLAY;
			TFT_voidDisplay(img2);
			HR2RDAC_vPlaySongandDisplayName(__10_Ya_Lalaly_raw,SONG_2_LENGTH,&play_flag , &song_flag);
			break;
		default:
			asm("NOP");
			break;
		}

	}

}





//-----------------------------------------------> IR Code (Must Be Kept In Main)
//********************************************//
void voidPlay(void)
{
	switch (Localu8Data)
	{
	case BUTTON_1:
		play_flag = STOP ;
		song_flag = SONG_1 ;
		G_Flag = CHANNEL_1;
		break;
	case BUTTON_2:
		play_flag = STOP ;
		song_flag = SONG_2 ;
		G_Flag = CHANNEL_2;
		break ;
	}
}

void voidTakeAction(void)
{
	u8 i;
	Localu8Data = 0;

	if ( (Local_u32FrameData[0] >= 10000) && (Local_u32FrameData[0] <= 15000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (Local_u32FrameData[17+i] >= 1000) && (Local_u32FrameData[17+i] <=2000) )
			{
				CLR_BIT(Localu8Data,i);
			}

			else
			{
				SET_BIT(Localu8Data,i);
			}
		}

		voidPlay();
	}

	else
	{
		/*	 Invalid Frame */
	}

	Local_u8StartFlag     = 0;
	Local_u32FrameData[0] = 0;
	Local_u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if (Local_u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetInterval_single(100000,voidTakeAction);
		Local_u8StartFlag = 1;
	}

	else
	{
		Local_u32FrameData[Local_u8EdgeCounter] = ( MSTK_u32GetElapsedTime() / 2 );
		MSTK_voidSetInterval_single(100000,voidTakeAction);
		Local_u8EdgeCounter++;
	}
	if(Local_u8EdgeCounter == 50)
	{
		asm("NOP");
	}

}
//*******************************************************************************************//
