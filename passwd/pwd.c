// pwd2.c

// By Jeremy Villegas
// By Tony Stanton
// Programming Asssignment
// April 9, 2008

/******************************************************************************** 
* Legal Passwords (Example from Elaine Rich in "Automata, Compatibility and 
* Complexity", p.) Consider the problem of determining whether a string is a legal 
* password. Suppose that we require that all passwords meet the following requirements: 
*
* A password must begin with a letter.
* A password may contain only letters, numbers, and the underscore character.
* A password must contain at least four characters and no more than eight characters.
* The following regular expression describes the language of legal passwords.
*
* ((a-z) + (A-Z))
* ((a-z) + (A-Z) + (0-9) + _)
* ((a-z) + (A-Z) + (0-9) + _)
* ((a-z) + (A-Z) + (0-9) + _)
* ((a-z) + (A-Z) + (0-9) + _ + e)
* ((a-z) + (A-Z) + (0-9) + _ + e)
* ((a-z) + (A-Z) + (0-9) + _ + e)
* ((a-z) + (A-Z) + (0-9) + _ + e)
*
* ASCII: lowercase letters ( a-z ) is 97 to 122
* ASCII: uppercase letters ( A-Z ) is 65 to 90
* ASCII: underscore character ( _ ) is 95
* ASCII: numbers ( 0-9 ) is 48 to 57
* ASCII: null (  ) is 0
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define MIN_STR_SIZE 4
#define MAX_STR_SIZE 8

static void pwd_error(char*);

int main()
{
  char ch, passwd[MAX_STR_SIZE+1];
  int x = 0;
  printf("Enter password: ");
  while((ch = (char)getchar()) != '\n'){
    // Perform all checks here
    switch(x){
      case 0: // Is the first character a letter?
        if(((int)ch >= 65 && (int)ch <= 90) ||
             ((int)ch >= 97 && (int)ch <= 122))          
          passwd[x++] = ch;
        else pwd_error("First character must begin with a letter.");
        break;
      case MAX_STR_SIZE+1: // does it exceed the length?
        pwd_error("Password exceeds allowable length");
        break;
      default:
        // Is it a number, letter, or underscore?
        if(((int)ch >= 65 && (int)ch <= 90) || 
             ((int)ch >= 97 && (int)ch <= 122) || 
             ((int)ch >= 48 && (int)ch <= 57) || 
             ((int)ch == 95))
          passwd[x++] = ch;
        else pwd_error("Password contains an invalid character.");
    }
  }
  passwd[x] = '\0';
  printf("Legal password!\n");
  return 0;

} // end of int main()

void pwd_error(char* s){
  printf("ERROR: %s\n",s);
  exit(EXIT_FAILURE);
}
 
