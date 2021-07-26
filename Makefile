####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################

#Add necessary aliases
target=DARKnes
main=src/main.c
drivers=$(wildcard src/drivers/*.c)


all default $(target):$(main) 
		gcc -o $(target) $(main) $(drivers) -I inc

$(main): $(drivers)
	gcc -c $(drivers) -I inc

clean:
	rm -f *.o $(target)