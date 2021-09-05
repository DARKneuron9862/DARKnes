/*
 *PPU header for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
 *This file contains PPU related macros,structures and 
 *function prototypes.
*/

 
#include <stdint.h>

#define PPU_REG_SIZE 0x8U
#define BIT(x)  x
/*Memory-mapped  PPU registers*/
#define PPUCTRL     0x2000
#define PPUMASK     0x2001

#define PPUSTATUS   0x2002
    #define PPUSTATUS_VBLANK      BIT(7)
    #define PPUSTATUS_SPR0_HIT    BIT(6)
    #define PPUSTATUS_SPR_OVRFLW  BIT(5)
    #define PPUSTATUS_LSB4        BIT(4)
    #define PPUSTATUS_LSB3        BIT(3)
    #define PPUSTATUS_LSB2        BIT(2)
    #define PPUSTATUS_LSB1        BIT(1)
    #define PPUSTATUS_LSB0        BIT(0)

#define OAMADDR     0x2003
#define OAMDATA     0x2004
#define PPUSCROLL   0x2005
#define PPUADDR     0x2006
#define PPUDATA     0x2007
#define OAMDMA      0x4014


/* VRAM memory map */
#define NAMETBL_MIRR_START  0x3000
#define NAMETBL_MIRR_END    0x3EFF

#define CLEAR_BIT_PPUREG(PPU_REGISTER,BIT)  memory.RAM[PPU_REGISTER]&=~(1<<BIT)
#define SET_BIT_PPUREG(PPU_REGISTER,BIT)    memory.RAM[PPU_REGISTER]|=(1<<BIT)

typedef struct{
    /* PPU internal registers*/
    uint8_t w;
    uint8_t t;
    uint8_t x;
    uint8_t y;

    uint8_t internal_buffer;

}__PPU_state;
extern __PPU_state PPU_state;
void test_PPU();