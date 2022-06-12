#include <stdlib.h>
#include<stdio.h>


typedef struct
{
  unsigned int a;
  unsigned int b;
  unsigned int c;
  unsigned int d;
}_strukt1;


typedef struct
{
  unsigned int a:5;
  unsigned int b:2;
  unsigned int c:1;
  unsigned int d:5;
}_strukt2;


int main(void)
{
  _strukt1 sa = {1, 2, 3, 4};
  _strukt2 sb = {1, 2, 3, 4};

  printf("sa.a = %u   sa.b = %u   sa.c = %u   sa.d = %u\n", sa.a, sa.b, sa.c, sa.d);
  printf("Struktura sa zauzima %u B\n", sizeof(sa));


  printf("sb.a = %u   sb.b = %u   sb.c = %u   sb.d = %u\n", sb.a, sb.b, sb.c, sb.d);
  printf("Struktura sb zauzima %u B\n", sizeof(sb));



  system("pause");
}


/*
Napisati program u kojemu ce se prijaviti polje bitova. 
Pridati svakom polju neku brojcanuvrijednost. 
Raspraviti rezultat.
*/