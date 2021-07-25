/*
@author: Anirban Chowdhury


*/
#include<stdint.h>

typedef struct{
	uint8_t *ram;
	uint8_t *vram;
	uint8_t *oam;
	
	uint16_t vram_address;


}__memory;

extern __memory memory;
