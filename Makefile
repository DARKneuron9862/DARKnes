####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################

#Add necessary aliases
target=DARKnes
main=src/main.c

all default $(target):$(main) #put rest of ingredients 1 line and at most 1 alias#no explicit filenames
	gcc -Iinc/ src/drivers/*.c $(main) -o $(target)
clean:
	rm $(target)