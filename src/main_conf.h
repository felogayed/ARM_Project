/*
 * main_conf.h
 *
 *  Created on: Mar 14, 2024
 *      Author: philo
 */

#ifndef MAIN_CONF_H_
#define MAIN_CONF_H_



//**************************************************//
// main section
#define PLAY 1
#define STOP 0

#define CHANNEL_1 1
#define CHANNEL_2 2

#define SONG_1 1
#define SONG_2 2

#define SONG_1_LENGTH 52590
#define SONG_2_LENGTH 47460

#define BUTTON_1 128
#define BUTTON_2 132

//******************************************************//
// IR section

void voidPlay(void);
void voidTakeAction(void);
void voidGetFrame(void);

volatile u8   Local_u8StartFlag       = 0;
volatile u32  Local_u32FrameData[50]  = {0};
volatile u8   Local_u8EdgeCounter     = 0;
volatile u16   Localu8Data            = 0;

//******************************************************//
//flags section
u8 play_flag = 0 ;
u8 song_flag = 0 ;
u8 G_Flag =0;
//********************************************************//

#endif /* MAIN_CONF_H_ */
