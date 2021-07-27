####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################


target=DARKnes
main=src/main.c
drivers=$(wildcard src/drivers/*.c)

all default: $(target)

$(target):$(main) $(drivers)
	gcc -o $@ $^ -I inc

$(main): $(drivers)
	gcc -c $^ -I inc

clean:
	rm -f *.o $(target)