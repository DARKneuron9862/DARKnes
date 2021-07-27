####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################

#Add necessary aliases
target=DARKnes
main=src/main.c
drivers:=$(wildcard src/drivers/*.c)
obj=$(drivers:.c=.o) 


all default :$(target)

$(target):$(obj) $(main)
	gcc $^ -Iinc -o $@

$(obj):$(drivers) #put rest of ingredients 1 line and at most 1 alias#no explicit filenames
	gcc $(drivers) -Iinc -c
	mv *.o src/drivers/
	

clean:
	rm -f src/drivers/*o $(target)