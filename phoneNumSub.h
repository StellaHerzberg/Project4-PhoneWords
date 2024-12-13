//Stella Herzberg
//CPSC1070:002
//Project 4
//This file serves as the header file for the PhoneWords portion of Project 4. It includes the prototypes for the functions implemented in PhoneWords.c

//Header guards
#ifndef PHONENUMSUB_H
#define PHONENUMSUB_H

//Header files
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Main driver of implementation file
void getAllSubs(char* inPhoneNum, FILE*);

//Gets the numbers for each dictionary word
char getNums(char c);

//Removes the dashes from the inputted word
void removeDashes(char *inPhoneNum);

//Makes sure word contains no non-alphabet characters
bool isValid(char *line);

//Ending header guard
#endif
