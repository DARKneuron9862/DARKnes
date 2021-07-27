####################################

#Makefile
#Author:Anirban Chowdhury
#Copyright(c),2021,Anirban Chowdhury 

####################################


#Necessary aliases

main=src/main.c
cpu=src/drivers/cpu.c
memory=src/drivers/memory.c
ppu=src/drivers/ppu.c
cpu_h=inc/cpu.h
memory_h=inc/memory.h
ppu_h=inc/ppu.h

CC = gcc
objfiles = main.o memory.o cpu.o ppu.c


all: $(target)

$(target): $(objects)
	$(CC) -wall -o $(target) $(objfiles) 

main.o: main
	gcc -I $(cpu_h) $(memory_h) $(ppu_h) -c main

memory.o: memory
	gcc -I  $(memory_h) -c memory

cpu.o:cpu
	gcc -I $(cpu_h) -c cpu

ppu.o:ppu
	gcc -I $(ppu_h) -c ppu
			
clean:
	#To clean the target and
	#any other obj files created in build process
	rm -f $(objfiles) $(target) *~
