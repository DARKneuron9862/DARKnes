####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################


target=DARKnes
main=src/main.c
drivers=$(wildcard src/drivers/*.c)
INCLUDE=inc
INC_FLAG=-I

all default: $(target)

$(target):$(main) $(drivers)
	gcc -o $@ $^ $(INC_FLAG) $(INCLUDE)

$(main): $(drivers)
	gcc -c $^ $(INC_FLAG) $(INCLUDE)

clean:
	rm -f *.o $(target)