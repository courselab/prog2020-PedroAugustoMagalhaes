/* m008.c - Lastname-Names.
ok
   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  int b = 0;
  int i;
  char ultimo[MAX];
  char resto[MAX];
  char finish[MAX];

  int a = strlen(s) - 2;
  while (s[a] != 32)
  {
    i = a - 1;
    a--;
  }
  for(a = i + 1; s[a + 1] != 0; a++)
  {
    ultimo[b] = s[a];
    if (ultimo[b]<= 'z' && ultimo[b]>= 'a')
    {
      ultimo[b] = ultimo[b] - 32;
    }
    b++;
  }
  for(a = 0; a<i; a++)
  {
    resto[a] = s[a];
  }
  strcat(finish, ultimo);
  strcat(finish, ", ");
  strcat(finish, resto);

  strcpy(s, finish);
}

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
