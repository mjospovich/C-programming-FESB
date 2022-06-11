#include<stdio.h>
#include<stdlib.h>

int main()
{
  int test, brint;
  double broj;
  unsigned long int maska = 1, i;
  unsigned long int bitovi = 8 * sizeof(double), bit;
  char c;

  printf("Unesite jednu realnu vrijednost: ");
  scanf("%lf", &broj);
  brint = *((long int*)&broj);

  printf("Velicina float-a je: %ld b.\n", bitovi);
  printf("Prikaz broja u big endian ili little endian nacinu(B/L): ");
  scanf(" %c",&c);

  puts("");

  switch(c)
  {
    case 'B':
      maska <<= bitovi - 1;
      test = 1;
      break;

    case 'L':
      test = 0;
      break;

    default:
      puts("Krivi unos!");
      return 1;
  }


  for(i = 1; i<= bitovi; i++)
  {
    bit = (brint&maska) ? 1 : 0;

    printf("%ld", bit);

    if(i % 4 == 0)
      printf(" ");
    
    if(test)
      maska >>= 1;
    else
      maska <<= 1;
  }

  puts("");

  printf("\n");
  system("pause");
  return 0;
}