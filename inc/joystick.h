#include <SDL2/SDL.h>

typedef struct 
{
	uint8_t buttons[8];
} __joystick;

extern __joystick joystick;

void init_controller();
void handle_input(__joystick *joystick,SDL_Event *e);
