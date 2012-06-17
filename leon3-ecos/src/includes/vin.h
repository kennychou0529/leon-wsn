#ifndef __VIN_H__
#define __VIN_H__

#include "includes.h"

#define VIN_CFG 0x0
#define VIN_DIM 0x4
#define VIN_SAD 0x8
#define VIN_EAD 0xC
#define VIN_STAT 0x10
#define VIN_STAT_FULL	(REG32(VIN_BASE+VIN_STAT) & 0x08)
#define VIN_STAT_EMPTY	(REG32(VIN_BASE+VIN_STAT) & 0x04)
#define VIN_STAT_RXERR	(REG32(VIN_BASE+VIN_STAT) & 0x02)
#define VIN_STAT_RXDONE	(REG32(VIN_BASE+VIN_STAT) & 0x01)
#define VIN_IRQ  0x14
#define VIN_IRQM 0x18
#define VIN_FDI0 0x80
#define VIN_FDI1 0xA0
#define VIN_FDI2 0xC0
#define VIN_FDI3 0xE0

	
void vin_set_sad(unsigned long addr);
void vin_set_ead(unsigned long addr);
void vin_set_window(int16u_t w,int16u_t h);
void vin_en_set();
void vin_init(void);


void show_pix_data();
#endif