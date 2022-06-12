#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, broj, test;
  unsigned maska = 1;
  unsigned bitovi = 8 * sizeof(int), bit;
  char c;

  printf("Unesite jednu cjelobrojnu vrijednost: ");
  scanf("%d", &broj);

  printf("Velicina int-a je: %d b.\n", bitovi);
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
    bit = (broj&maska) ? 1 : 0;

    printf("%d", bit);

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


/*
Napisati program koji ce:
a)prikazati uneseni cijeli broj u obliku niza bitova. Prikazane rezultate objediniti u skupine
po cetiri binarne znamenke,
b)uneseni decimalni broj (tipa float) prikazati u obliku niza bitova. Prikazane rezultate
objediniti u grupe prema IEEE 754 standardu (MSB, eksponent, mantisa),
c)uneseni decimalni broj (tipa double) prikazati u obliku niza bitova. Prikazane rezultate
objediniti u grupe prema IEEE 754 standardu (MSB, eksponent, mantisa).
U programu je potrebno omoguciti prikaz binarnog broja u “little-endian" ili “big-endian"
zapisu.

*/