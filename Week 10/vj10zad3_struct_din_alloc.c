#include<stdlib.h>
#include<stdio.h>

typedef struct
{
  char ime_prez[50];
  int mat_br;
  int br_pol_isp;
  float posto_uspj;

}_student;


void upis(int br_clan, _student* studenti)
{
  int i;

  for(i = 0; i<br_clan; i++)
  {
    printf("\nUnosite podatke za studenta broj %d\n", i+1);

    printf("Unesite ime (i prezime) studenta: ");
    scanf("%s",studenti[i].ime_prez);

    printf("\nUnesite maticni broj studenta: ");
    scanf("%d", &studenti[i].mat_br);

    printf("\nUnesi broj polozenih ispita studenta(<=6): ");
    scanf("%d", &studenti[i].br_pol_isp);

    studenti[i].posto_uspj = (float)(studenti[i].br_pol_isp/0.06);
  }

  return;
}

void ispis(_student *s)
{
  printf("Student imena %s ima maticni broj %d!", s->ime_prez, s->mat_br);
  printf("\nProsao je %d ispita te ima prolaznost od %.2f%%", s->br_pol_isp, s->posto_uspj);
  printf("\n");

  return;
}



int main(void)
{
  int i, n;
  _student *pStud;

  printf("Koliko studenata zelite unjeti: ");
  scanf("%d", &n);

  pStud = (_student *)malloc(n * sizeof(_student));

  upis(n, pStud);

  printf("\nIspis podataka:\n");
  for(i = 0; i<n; i++)
  {
    ispis(pStud + i);
  } 



  system("pause");
}