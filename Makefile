####################################

#Makefile
#Authors: Anirban Chowdhury,
#	  Sharad Saha
#Copyright(c),2021,Anirban Chowdhury 

####################################

target=DARKnes
main=src/main.c
<<<<<<< HEAD
driver=src/*/*.c
all default $(target):$(main) #put rest of ingredients 1 line and at most 1 alias#no explicit filenames
		#write the receipe 1 line

$(main): driver.o
	gcc -o $(target) *.o

driver.o: $(driver)
	gcc -c -Iinc $(driver) $(main)

clean:
	#write the receipe to clean the target and
	#any other obj files created in build process
	rm -f $(target) *.o
=======
DRIVERS_DIR=src/drivers
INCLUDE=inc
INC_FLAG=-I
drivers=$(wildcard src/drivers/*.c)
objfiles=$(drivers:.c=.o) 

all default: $(target) 

$(target):$(objfiles) $(main)
	gcc -o $@ $^ $(INC_FLAG) $(INCLUDE)

%.o: %.c
	gcc -c $^ $(INC_FLAG) $(INCLUDE) -o $@
	
clean:
	rm -f $(objfiles) $(target)
>>>>>>> experimental
