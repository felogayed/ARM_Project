/*
 * DAC_interface.h
 *
 *  Created on: Jan 23, 2024
 *      Author: philo
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


void HR2RDAC_vInit(void);
void HR2RDAC_vPlaySongandDisplayName(const u8 *arr,u32 arrsize , u8 * flag , u8 * song_flag);


#endif /* DAC_INTERFACE_H_ */
