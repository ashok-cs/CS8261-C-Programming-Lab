/*
Ex 11. From a given paragraph perform the following using built-in functions:
a.  Find the total number of words.
b.  Capitalize the first word of each sentence. 
c.   Replace a given word with another word.
*/

#include "stdio.h"
#include "string.h"
#include "ctype.h"
void replace (char *, char *, char *); 

int main(void) {
  char paragraph[200] = "The quick brown fox\n jumps over\n the lazy dog.";
  char old[10] = "Fox", S[10] = "Lion";
  char word[30], c;
  
  int i = 0, j =0, count = 0;
  printf("***** Given paragraph  *****\n");
  printf("%s \n", paragraph);
  printf("****************************\n");
  while (paragraph[i] != '\0')
  {
    word[j++] = paragraph[i++];
    if (paragraph[i] == ' ' || paragraph[i] == '\n')
    {
      j = 0;
      count++;
      paragraph[i+1] = toupper(paragraph[i+1]);
    };       
  } // end-while
  
  printf("No of words: %d \n", count);
  printf("****************************\n");
  printf("Capitalize each word\n");
  printf("****************************\n");
  printf("%s\n", paragraph);
  printf("****************************\n");
  printf("Replace %s with %s \n\n", old, S);
  printf("****************************\n");
  replace(paragraph, old, S);
  printf("%s\n", paragraph);

  return 0;
}


void replace(char * str, char * s_string, char * r_string) 
{
  //a buffer variable to do all replace things 
  char buffer[200];
  //to store the pointer returned from strstr 
  char * ch;
  
  //first exit condition
  if(!(ch = strstr(str, s_string))) return;
  
  //copy all the content to buffer before the first occurrence of the search string 
  strncpy(buffer, str, ch-str);
  
  //prepare the buffer for appending by adding a null to the end of it
   
  buffer[ch-str] = 0;
  
  //append using sprintf function
  sprintf(buffer+(ch -str), "%s%s", r_string, ch + strlen(s_string));
  
  //empty str for copying 
  str[0] = 0;
  strcpy(str, buffer);
  //pass recursively to replace other occurrences 
  return replace(str, s_string, r_string);
}
