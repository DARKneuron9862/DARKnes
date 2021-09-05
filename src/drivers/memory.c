/*
 *Memory driver for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
*/

#include<stdio.h>
#include"memory.h"
#include"PPU.h"

__memory memory;

void test_memory()
 {
 	printf("greetings from memory\n");

 }
void init_memory(){
    memset(memory.RAM,0,CPU_ADDR_SPACE*sizeof(uint8_t));



}
uint8_t readRAM(uint16_t address){
    /* Internal 2KB SRAM*/
    uint8_t retVal=0;
    if(address>=INTR_SRAM_RANGE && address<=INTR_SRAM_MIRROR_END){
        /*write code*/
    }
    /* PPU registers */
    else if (address>=PPU_REG_BASE+N_PPU_REG && address<=PPU_REG_MIRROR_END){
        /* Write address filtering code*/
        switch(address){
            case PPUSTATUS:
                
                break;
            case OAMDATA:
                
                break;
            case PPUDATA:
                break;
        }
    }

    return retVal;
}

uint8_t readVRAM(uint16_t address){



}

