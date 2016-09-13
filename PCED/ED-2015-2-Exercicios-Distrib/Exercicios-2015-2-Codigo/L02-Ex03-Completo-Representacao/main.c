#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  union {
    char      c [8];  // 1 byte  por char
    short int si[4];  // 2 bytes por short int
    int       i [2];  // 4 bytes por int
    double    d;      // 8 bytes por double
  }
    u;
    
  int k;

  u.c[0] = 'A';
  u.c[1] = 'B';
  u.c[2] = 'C';
  u.c[3] = 'D';
  u.c[4] = '1';
  u.c[5] = '2';
  u.c[6] = '3';
  u.c[7] = 'A';

/*
Como char:  A B C D 1 2 3 A
Como short int:  16961 17475 12849 16691
Como int:  1145258561 1093874225
Como double:  1258033.266651
*/

  printf ("Como char: ");
  for (k=0; k<8; k++)
    printf ("%c ", u.c[k]);
  printf ("\n");
  
  printf ("Como short int: ");
  for (k=0; k<4; k++)
    printf ("%d ", u.si[k]);
  printf ("\n");

  printf ("Como int: ");
  for (k=0; k<2; k++)
    printf ("%d ", u.i[k]);
  printf ("\n");

  printf ("Como double: ");
  printf ("%f", u.d);
  printf ("\n");

  system("PAUSE");
  return 0;
}
