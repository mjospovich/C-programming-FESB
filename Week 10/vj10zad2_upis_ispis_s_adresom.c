#include<stdio.h>
#include <stdlib.h>


typedef struct
{
  char ime[50];
  int maticni_broj;
  int br_pol_ispita;
  float postotak_uspj;

}podaci;


void upis(int br_clan, podaci *studenti)
{
  int i;

  for(i = 0; i<br_clan; i++)
  {
    printf("\nUnosite podatke za studenta broj %d\n", i+1);

    printf("Unesite ime studenta: ");
    scanf("%s",&studenti[i].ime);

    printf("\nUnesite maticni broj studenta: ");
    scanf("%d", &studenti[i].maticni_broj);

    printf("\nUnesi broj polozenih ispita studenta(<=6): ");
    scanf("%d", &studenti[i].br_pol_ispita);

    studenti[i].postotak_uspj = (float)(studenti[i].br_pol_ispita/0.06);
  }
  return;
}


void ispis(podaci* s)
{

  printf("Student imena %s ima maticni broj %d!", s->ime, s->maticni_broj);
  printf("\nProsao je %d ispita te ima prolaznost od %.2f%%", s->br_pol_ispita, s->postotak_uspj);
  printf("\n");

  return;
}


int main(void)
{
  int i, n;
  podaci studenti[50];
  podaci *pStud;

  printf("Koliko studenata zelite unjeti: ");
  scanf("%d", &n);

  upis(n, studenti);

  printf("\nIspis podataka:\n");
  for(i = 0; i<n; i++)
  {
    pStud = &studenti[i];
    ispis(pStud);
  } 

  system("pause");
}



/*
Napravi strukturu podaci koja ce sadrzavati ime, maticni broj, broj polozenih ispita
i postotak prolaznosti(od 6 ispita).
Prijaviti nekoliko clanova ove struktire upisati njhove podatke te ih ispisati.
Korisnika prvobitno pitati koliko clanova zeli prijaviti prije nego krece s upisom.
Upis obaviti u funkciji void upis(int, struct podaci[]) gdje je prvi argument ukupni broj
clanova koji je korisnik odabrao.
Ispis obaviti funkcijom void ispis(struct podaci*).

*/