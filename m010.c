/* m010.c - Day of the week.
ok
   This program takes two integers read as command line arguments
   representing, respectively, the day and the month of a date in
   year 2020, and produces as output the corresponding day of the week.
   Output should be: Sunday, Monday, Thursday, Wednesday, Thursday,
   Friday, Saturday.

   E.g.

      command line    : m010 2 6
      expected output : Thursdays

   Directions:

      Please, edit function day_of_week();
      do no not change function main().

 */

#include <stdio.h>
#include <stdlib.h>

#define USAGE "m010 <day> <month>\n"

enum {sun, mon, tue, wed, thu, fri, sat};

/* Return the day of the week in the numeric form:
   Sunday=0, Monday=1... Saturday=6.*/

int day_of_week (int day, int month)
{
  int b;
  int a = 0;
  int i = 0;
  int v[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};
  if(month >= 1 && month <= 12 && day <= v[month])
  {
    for(i = 0; i <= month - 1; i++)
    {
      a = a + v[i];
    }
    b = a + day;
    switch(b % 7)
    {
      case 0:
       return tue;
       break;
      case 1:
       return wed;
       break;
      case 2:
       return thu;
       break;
      case 3:
       return fri;
       break;
      case 4:
       return sat;
       break;
      case 5:
       return sun;
       break;
      case 6:
       return mon;
       break;  
    }
  }
  else 
  return 8;
}

/* Do not edit function main. */

int main (int argc, char **argv)
{
  int day, month, dweek;
  int g;

  if (argc < 3)
    {
      printf (USAGE);
      exit(1);
    }
  
  month = atoi(argv[1]);
  day = atoi(argv[2]);

  dweek = day_of_week (day, month);
  
  switch (dweek)
    {
    case sun:
      printf ("Sunday\n");
      break;
    case mon:
      printf ("Monday\n");
      break;
    case tue:
      printf ("Tuesday\n");
      break;
    case wed:
      printf ("Wednesday\n");
      break;
    case thu:
      printf ("Thursday\n");
      break;
    case fri:
      printf ("Friday\n");
      break;
    case sat:
      printf ("Saturday\n");
      break;
    default:
      printf ("Something wrong\n");
      break;
    }
  
  return 0;
}
