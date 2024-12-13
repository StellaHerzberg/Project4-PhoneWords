#Stella Herzberg
#CPSC1070
#Project 4: PhoneWords
#This file serves as the makefile for Project 4. This file contains directives to compile, run, and clean the directory files. All files will be compiled with -Wall so that all warnings are included and the output will be sent into an executable called PhoneWord.exe

compile:
	gcc Project4.c -c -Wall
	gcc phoneNumSub.c -c -Wall
	gcc Project4.o phoneNumSub.o -Wall -o Project4.exe

run:
	./Project4.exe input1.txt output1.txt

clean:
	rm*.exe
