#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 10

typedef struct
{
  char ime[50];
  char prez[50];
  int min;
  int sek;
  int ms;

}_trkaci;

void ispis(_trkaci*, int, int);
int najbrzi(_trkaci*, int);

int main(void)
{
  FILE *input;
  input = fopen("trkaci.txt", "r");

  _trkaci *trk;

  trk = (_trkaci*)malloc(sizeof(_trkaci)*MAX);

  int i, br_red = 0, naj = 0;
  char c;

  while((c = fgetc(input)) != EOF)
  {
    if (c == '\n')
      br_red++;
  }
  br_red = br_red - 1;

  trk = (_trkaci*)realloc(trk, sizeof(_trkaci) * br_red);

  rewind(input);

  while(fgetc(input) != '\n');

  for(i = 0; i<br_red; i++)
  {
    fscanf(input, "%s %s %02d %02d %02d", trk[i].ime, trk[i].prez, &trk[i].min, &trk[i].sek, &trk[i].ms);
  }

  naj = najbrzi(trk, br_red);

  ispis(trk, br_red, naj);
  fclose(input);


  system("pause");
}


int najbrzi(_trkaci *trk, int n)
{
  int naj = (trk[0].min * 60) + (trk[0].sek);
  int vrem = 0, i, naj_trk;

  for(i = 1; i<n; i++)
  {
    vrem = (trk[i].min * 60) + (trk[i].sek);

    if(naj > vrem){
      naj = vrem;
      naj_trk = i;
    }
    vrem = 0;
  }


  return naj_trk;
}


void ispis(_trkaci *trk, int n, int naj)
{
  int i;

  printf("Svi trkaci i njihova vremena:\n");

  for(i = 0; i<n; i++)
  {
    printf("%s\t\t%s\t\t%02d:%02d:%02d", trk[i].ime, trk[i].prez, trk[i].min, trk[i].sek, trk[i].ms);
    printf("\n");
  }
  printf("\nNajbrzi trkac je %s i otrcao je vrijeme: %02d:%02d:%02d\n", trk[naj].ime, trk[naj].min, trk[naj].sek, trk[naj].ms);
  printf("\n");

}