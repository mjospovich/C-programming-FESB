#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  system("color 0b");
  FILE *input, *output;

  int a;

  char b[50];
  char c[50];
  char temp[50];
  int br_lin = 0;

  input = fopen("zad2.txt", "w");

  fprintf(input, "%s", "Mate Kovac");
  fprintf(input, "%s\n%d\n", "\nCrni Ante", 5);
  fclose(input);

  output = fopen("zad2.txt", "r");

  while (!feof(output))
    {
        if (fgetc(input) == '\n')
            br_lin++;
    }

  rewind(output);

  for(int i = 0; i<br_lin; i++)
  {
    if(i == 0)
    {
      fscanf(output, "%s %s", b, temp);
      strcat(b, " ");
      strcat(b, temp);
    }

    if(i == 1)
    {
      fscanf(output, "%s %s", c, temp);
      strcat(c, " ");
      strcat(c, temp);
    }

    if(i == 2)
      fscanf(output, "%d\n", &a);
  }

  printf("Zove se %s, a %s ima %d krava!\n", b, c, a);

  system("pause");
  system("start zad2.txt");
}