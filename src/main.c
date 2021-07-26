/*
 *main.c for "DARKnes" an NES emulator
 *Author:Anirban Chowdhury
 *Copyright (C),2021, Anirban Chowdhury 
*/


#include"memory.h"
#include"CPU.h"
#include"PPU.h"

void main()
{
	test_CPU();
	test_PPU();
	test_memory();

}
