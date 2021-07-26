####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################

#Add necessary aliases
target=DARKnes
main=src/main.c
driver=src/drivers/cpu.c src/drivers/memory.c src/drivers/ppu.c
all default $(target):$(main) #put rest of ingredients 1 line and at most 1 alias#no explicit filenames
		#write the receipe 1 line
		gcc -Iinc $(driver) -Iinc $(main) -o $(target)
clean:
	#write the receipe to clean the target and
	#any other obj files created in build process
	rm *$(target)