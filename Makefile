####################################

#Makefile
#Authors: Anirban Chowdhury,
#	  Sharad Saha
#Copyright(c),2021,Anirban Chowdhury 

####################################

target=DARKnes
main=src/main.c
DRIVERS_DIR=src/drivers
INCLUDE=inc
INC_FLAG=-I
SDL_FLAG=-lSDL2
drivers=$(wildcard src/drivers/*.c)
objfiles=$(drivers:.c=.o) 

all default: $(target) 

$(target):$(objfiles) $(main)
	gcc -o $@ $^ $(INC_FLAG) $(INCLUDE) $(SDL_FLAG)

%.o: %.c
	gcc -c $^ $(INC_FLAG) $(INCLUDE) $(SDL_FLAG) -o $@
	
clean:
	rm -f $(objfiles) $(target)


