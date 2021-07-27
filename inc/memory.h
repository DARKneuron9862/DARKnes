/*
 *Memory header for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
 *This file contains memory related macros,structures and 
 *function prototypes.
*/
#include<stdint.h>

typedef struct{
	uint8_t *ram;
	uint8_t *vram;
	uint8_t *oam;
	
	uint16_t vram_address;


}__memory;

extern __memory memory;


void test_memory();
