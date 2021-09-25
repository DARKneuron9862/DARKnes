/*
 *main.c for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
*/

#include"memory.h"
#include"CPU.h"
#include"PPU.h"
#include"joystick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

void main(int argc, char **argv)
{
	// check if GAME_ROM missing
	if (argc < 2)
	{
		printf("Error : No input file given.\n");
		exit(EXIT_FAILURE);
	}

	// OPEN ROM FILE
	FILE *fptr;
	fptr = fopen(argv[1],"rb");

	// CHECK IF FILE IS OPENED CORRECTLY
	if (fptr==NULL)
	{
		printf("Error occured while opening the file..\n");
		exit(EXIT_FAILURE);
	}

	fseek(fptr,0,SEEK_END);
	long int length = ftell(fptr);
	fseek(fptr,0,SEEK_SET);

	// FILL THE CATRIDGE BUFFER FROM ROM FILE

	uint8_t *catridge_buffer = (uint8_t *) malloc(length*sizeof(uint8_t));
	if(fread(catridge_buffer,1,length+1,fptr)==length)
	{	
		// CHECK IF THE FILE IS NES FILE OR NOT
		if(catridge_buffer[0]!='N' && catridge_buffer[1]!='E' && catridge_buffer[2]!='S' && catridge_buffer[4]!=0x1A)
		{
			printf("Error : It is not a NES file, load a NES file.\n");
			exit(EXIT_FAILURE);
		}	
	}
	else
	{
		printf("Error : catridge_buffer length is not same as rom buffer length.\n");
		exit(EXIT_FAILURE);
	}

	// CLOSE THE FILE
	fclose(fptr);

	uint8_t n_PRGROM = catridge_buffer[4];
	uint8_t n_CHRROM = catridge_buffer[5];
	uint8_t INFO1 = catridge_buffer[6];
	uint8_t INFO2 = catridge_buffer[7];
	uint8_t n_RAM_BANKS = catridge_buffer[8];

	uint8_t trainer = (INFO1)&1<<2;
	uint8_t mapper = (INFO2>>4)<<4 | INFO1>>4;

	if(trainer)
	{	
		uint8_t rom_banks[length-16];
		for(int i=16;i<length+1;i++)
		{
			rom_banks[i-16] = catridge_buffer[i];
		}
	}
	// CHECK IF MAPPER==0
	if(mapper!=0)
	{
		printf("Error: Mapper value is not 0, load a valid NES file.\n");
		exit(EXIT_FAILURE);
	}
	init_memory();
	uint16_t index;

	// IF TRAINER PRESENT OR NOT
	if(trainer)
	{
		index = 528;
	}	
	else	
	{
		index = 16;
	}
	memcpy(memory.RAM+0x8000,catridge_buffer+index,n_PRGROM*16384);

	// MIRRORING
	if(n_PRGROM==1)
	{
		memcpy(memory.RAM+0xc000,catridge_buffer+index,n_PRGROM*16384);
	}

	// COPY CHRROM to PPUMEM
	memcpy(memory.vram,catridge_buffer+index+n_PRGROM*16384,n_CHRROM*8192);

	// INIT CPU and INIT CONTROLLER
	init_controller();

	// INIT SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	  SDL_Event e;
	  SDL_Surface *screenSurface = NULL;
	  SDL_Window *window=SDL_CreateWindow("TRIAL",
	                    SDL_WINDOWPOS_UNDEFINED,
	                    SDL_WINDOWPOS_UNDEFINED,
	                    640,480,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	  screenSurface = SDL_GetWindowSurface(window);
	  int pause=0;
	  int QUIT = 0;
	  while(!QUIT){
		  	while(SDL_PollEvent(&e))
		  	{

		        if(e.type==SDL_KEYDOWN) 
		        {	
		        	if(e.key.keysym.sym==SDLK_PAUSE)
		        	{
		        		pause ^= 1;
		        	}
		        }
		        else if(e.type == SDL_QUIT)
		        {
		        	QUIT=1;
		        }

		        // HANDLE INPUT FROM API -> args = (controller struct and event)
		        handle_input(&joystick,&e);
		  	}

		  	int frame_complete=0;
		  	if (!pause)
		  	{
		  		// run game and complete frame
		  	}

		  	if(frame_complete)
		  	{
		  		// increment frame count
		  		SDL_UpdateWindowSurface(window);
		  	}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
}	
