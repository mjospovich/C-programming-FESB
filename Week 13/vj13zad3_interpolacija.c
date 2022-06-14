#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  double x;
  double y;

}_tocka;

double linintp(int, _tocka*, double);
double lagnintp(int, _tocka*, double);


int main(void)
{
  FILE *ulz;
  int i, nt;

  _tocka *t;
  double x, yln, ylg;

  ulz = fopen("interpol.dat", "r");
  fscanf(ulz, "%d", &nt);
  t = (_tocka *)malloc(nt * sizeof(_tocka));

  for(i = 0; i<nt; i++)
  {
    fscanf(ulz, "%lf %lf", &t[i].x, &t[i].y);
  }
  fclose(ulz);

  printf("Unesite jednu tocku u rasponu (%.2f, %.2f): ", t[0].x, t[nt-1].x);
  scanf("%lf", &x);

  if(x < t[0].x || x > t[nt - 1].x)
  {
    puts("Tocka je izvan zadanog podrucja!");
    return 1;
  }

  yln = linintp(nt, t, x);
  ylg = lagnintp(nt, t, x);

  printf("\nLinearna interpolacija: x = %.2f\ty = %.4f\n"
    "Lagrangeova interpolacija: x = %.2f\ty = %.4f\n", x, yln, x, ylg);


  system("pause");
}



double linintp(int n, _tocka *t, double x)
{
  int i = 0;
  while (t[i].x <x)
    i++;
  i--;

  return (t[i+1].y - t[i].y)/(t[i+1].x - t[i].x) * (x-t[i].x) + t[i].y;
}



double lagnintp(int n, _tocka *t, double x)
{
  int i, j;
  double y = 0, yp;

  for(i = 0; i < n; i++)
  {
    yp = t[i].y;

    for(j = 1; j < n; j++)
    {
      if(i != j)
        yp *= (x - t[j].x) / (t[i].x - t[j].x);
      
    }
    y += yp;
  }

  return y;
}


/*

U spisu interpol.dat dani su tabelarni podatci kvadratne funkcije opisane s cetiri tocke u
podrucju od 0 do 10. Ime spisa zadati zajedno s pozivom programa u nalogodavnog retku.
Potrebno je napisati program u kojem ce se linearnom i polinomskom interpolacijom Lagrangeovim
polinomom procijeniti iznos funkcije za proizvoljni argument unutar zadanog podrucja.
Linearnu interpolaciju izvršiti pozivom na funkciju prototipa double linint(int, _tocka *,
double);, a interpolaciju Lagrangeovim polinomom izvršiti pozivom na funkciju prototipa
double lagint(int, _tocka *, double);. Funkcije imaju jednake argumente: cjelobrojna
vrijednost koja odgovara broju tocaka u spisu, adresa prvog clana niza tipa _tocka, u kojem
su ucitane vrijednosti iz spisa i realnu vrijednost koja predstavlja tocku za koju se interpolacijom
traži odgovarajuca vrijednost koju funkcija vraca. Tip podatka _tocka je struktura
oblika:
typedef struct {
double x ;
double y ;
}_tocka ;

*/