#include "joystick.h"
#include <stdio.h>

__joystick joystick;

void init_controller()
{
	memset(joystick.buttons,0,8*sizeof(uint8_t));	
}

void handle_input(__joystick *joystick,SDL_Event *e)
{
	switch(e->key.keysym.sym)
	{
		case SDLK_a:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[6] = 1;
			else
				joystick->buttons[6] = 0;
			printf("left\n");
			break;
		
		case SDLK_w:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[4] = 1;
			else
				joystick->buttons[4] = 0;
			printf("up\n");		
			break;

		case SDLK_d:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[7] = 1;
			else
				joystick->buttons[7] = 0;
			printf("right\n");
			break;

		case SDLK_s:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[5] = 1;
			else
				joystick->buttons[5] = 0;
			printf("Down\n");
			break;
		case SDLK_0:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[0] = 1;
			else
				joystick->buttons[0] = 0;
			printf("A\n");
			break;
		case SDLK_1:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[1] = 1;
			else
				joystick->buttons[1] = 0;
			printf("B\n");
			break;
		case SDLK_2:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[2] = 1;
			else
				joystick->buttons[2] = 0;
			printf("Select\n");
			break;
		case SDLK_3:
			if(e->type==SDL_KEYDOWN)
				joystick->buttons[3] = 1;
			else
				joystick->buttons[3] = 0;
			printf("Start\n");
			break;								
	}
}
