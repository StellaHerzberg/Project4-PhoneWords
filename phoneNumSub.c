//Stella Herzberg
//CPSC1070:002
//Project 4: PhoneWords
//This file serves as the implementation file for the PhoneWords header file. It includes all of the code to take in the phone number, then find words inside the number.

#include "phoneNumSub.h"


//Function which takes in a char pointer to the array that containes the phone number. No return type because the function alters the variable itself. Will iterate through and return the number without dashes, whitespace
void removeDashes(char *inPhoneNum) {
  int j = 0;   //keep track of index   

  //Loop to run through the phone number       
  for (int i = 0; inPhoneNum[i] != '\0'; i++) {
    if (isdigit(inPhoneNum[i])) {     //Alter if char is a number     
      inPhoneNum[j++] = inPhoneNum[i];
    }
  }
  inPhoneNum[j] = '\0';  //Add ending null char    
}


//Function to get all of the word substitutions for the phone number
//Will take in the phone number and output file and print output onto output fine
void getAllSubs(char *inPhoneNum, FILE* output) {

  removeDashes(inPhoneNum);  //Call on function to get stripped number
  fprintf(output,"%s\n", inPhoneNum);  //Print to file

  //Open dictionary and create variables for dictionary words and our final converted dictionary word
  FILE* dictionary = fopen("/usr/share/dict/words","r");
  char line[256];
  char convertedDict[15];

  //Loop through words in dictionary
  while (fgets(line, sizeof(line), dictionary)) {

    //Replace ending newline character with a null character
    size_t len = strlen(line);
    if (len > 0 && line[len-1] == '\n') {
      line[len - 1] = '\0';
    }

    //Keep track of how many elements are in the dictionary word
    size_t dictIndex = 0;
    for (size_t i = 0; i < strlen(line); i++) {    //Iterate through the word found in dictionary line

      char t9_number = getNums(line[i]);  //Get the corresponding number for letters

      //Will add all of the alphabet chars to the convertedDict, ignoring non-alphabetical chars
      if (t9_number != 'x'){
      convertedDict[i] = t9_number;
      dictIndex++; //Increment index variable
      }
    }
    convertedDict[dictIndex] = '\0';  //Adds ending new variable to convertedDict

    //If the convertedDict is a substring of the original input & longer than 2 elements & no non-alphabetic chars
    if (strstr(inPhoneNum,convertedDict)!= NULL && strlen(line) > 2 && isValid(line) == true) {

      //Convert all original words to lowercase by going through each char in dictionary line
      for (int i = 0; line[i] != '\0'; i++) {  
	line[i] = tolower((unsigned char)line[i]); 
      }
      fprintf(output,"%s\n", line);  //Print the final lowercase line
    }
  }
  fclose(dictionary);  //Close dictionary file
}


//Function to convert the alphabet chars to numbers
//Takes in the letter as a char and returns the number has a char
char getNums(char c) {

  //If the char is not a letter, just return an x as a placeholder
  if (!isalpha(c)) {
    return 'x';
  }
  
  c = tolower(c);   //Convert char to lowercase

  //If statements to convert the alphabet to a number
  if (c >= 'a' && c <= 'c') {  //a-c is 2
    return '2';
  } else if (c >= 'd' && c <= 'f') {  //d-f is 3
    return '3';
  } else if (c >= 'g' && c <= 'i') {  //g-i is 4
    return '4';
  } else if (c >= 'j' && c <= 'l') {  //j-l is 5
    return '5';
  } else if (c >= 'm' && c <= 'o') {   //m-o is 6
    return '6';
  } else if (c >= 'p' && c <= 's') {   //p-s is 7
    return '7';
  } else if (c >= 't' && c <= 'v') {   //t-v is 8
    return '8';
  } else if (c >= 'w' && c <= 'z') {  //w-z is 9
    return '9';
  } else {   //If none of those, just return 0
    return '0';
  }
}


//Boolean to decide if the line has any non-alphabetical elements
bool isValid(char *line) {

  //Loops through entire line from dictionary
  for (int i = 0; line[i] != '\0'; i++) {
    if (!isalpha(line[i])) {   //Decides if the char is in the alphabet, returns false if not
      return false;
    }
  }
  //If all elements are in alphabet, returns true
  return true;
}
