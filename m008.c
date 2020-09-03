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
  char finish[MAX];
  strcpy(finish, s);
  

  int a = strlen(s) - 2;
  while (s[a] != 32)
  {
    i = a - 1;
    a--;
  }
  for(a = i + 1; finish[a + 1] != 0; a++)
  {
    s[b] = finish[a];
    if (s[b]<= 'z' && s[b]>= 'a')
    {
      s[b] = s[b] - 32;
    }
    b++;
  }
  s[b] = ',';
  s[b+1] = ' ';
  for(a = 0; a<=i; a++)
  {
    s[b+2] = finish[a];
    b++;
  }
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
