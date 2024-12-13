//Stella Herzberg
//CPSC1070:002
//Project 4
//This serves as the driver file for Project 4: PhoneWords. This code, in collaboration with the implementation and header files included, will take in a file of phone numbers, then use a directory to determine whether or not the phone numbers include words from the dictionary.

//Header files
#include "phoneNumSub.h"

//Main allows for command line arguments
int main(int argc, char *argv[]) {
  
  //Open the files with proper modes
  FILE* inFile = fopen(argv[1], "r");
  FILE* outFile = fopen(argv[2], "w");

  //If files not found or opened properly
  if (!inFile) {   //check inFile
    fclose(inFile);
    printf("%s", "Error opening files"); //Prints and returns if error with file opening
    return 1;
  }
  if (!outFile) {    //check outFile
    fclose(outFile);
    printf("%s", "Error opening files");  //Prints and returns if error with file opening
    return 1;
  }

  //Create phoneNum variable and go through file to put the number in
  char phoneNum[13];
  while (fgets(phoneNum, sizeof(phoneNum), inFile)) {  //Take all numbers from input file

    //Fix ending new line char by replacing with null char
    size_t len = strlen(phoneNum);
    if (len > 0 && phoneNum[len - 1] == '\n') {
	phoneNum[len - 1] = '\0';
      }

    //Skips the whitespace or extra lines in input file
    if (len == 0 || phoneNum[0] == '\0') {
      continue;
    }
    

    //Call on the main driver function for the implementation to get all of the word options
    getAllSubs(phoneNum,outFile);
  }
  
  //Close files
  fclose(inFile);
  fclose(outFile);

  return 0;
}
