/*
 *Memory header for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
 *This file contains memory related macros,structures and 
 *function prototypes.
*/
#include<stdint.h>

#define	CPU_ADDR_SPACE		   0xFFFF+0x1 

#define INTR_SRAM_BASE 		   0x0000
#define INTR_SRAM_RANGE 	   0x0800

#define INTR_SRAM_MIRROR_END   0x1FFF
#define PPU_REG_BASE		   0x2000
#define PPU_REG_END			   0x2007
#define PPU_REG_MIRROR_END 	   0x3FFF	
#define N_PPU_REG			   0x8

typedef struct{
	uint8_t RAM[CPU_ADDR_SPACE];
	uint8_t *vram;
	uint8_t *oam;
	
	uint16_t VRAM_address;
}__memory;

extern __memory memory;
void test_memory();
void init_memory();
uint8_t readRAM(uint16_t address);
uint8_t readVRAM(uint16_t address);

