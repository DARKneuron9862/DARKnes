####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################


target=DARKnes
main=src/main.c
DRIVERS_DIR=src/drivers
INCLUDE=inc
INC_FLAG=-I
drivers=$(wildcard src/drivers/*.c)
objfiles=$(drivers:.c=.o) 

all default: $(target) 

$(target):$(objfiles) $(main)
	gcc -o $@ $^ $(INC_FLAG) $(INCLUDE)


$(objfiles): $(drivers)
	gcc -c $^ $(INC_FLAG) $(INCLUDE)
	mv *.o $(DRIVERS_DIR)

clean:
	rm -f $(objfiles) $(target)