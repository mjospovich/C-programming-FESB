#include<stdio.h>
#include<stdlib.h>


typedef struct
{
  int brojnik;
  int nazivnik;

}_razl;

int najmanj_zaj_dj(int, int);
_razl zbroji(_razl, _razl);
_razl oduzmi(_razl, _razl);
_razl pomnozi(_razl, _razl);
_razl podijeli(_razl, _razl);
_razl skrati_raz(_razl);


_razl razlomke(_razl a, _razl b, _razl(*operacija)(_razl, _razl))
{
  return skrati_raz(operacija(a,b));
}


//glavna funkcija

int main(void)
{
  _razl a, b, c;
  char oper;
  char simbol;
  int aBR, aNZ, bBR, bNZ;

  printf("Unos prvog razlomka u formatu brojnik/nazivnik:\n");
  scanf("%d/%d", &a.brojnik, &a.nazivnik);

  fflush(stdin);

  printf("Unos drugog razlomka u formatu brojnik/nazivnik:\n");
  scanf("%d/%d", &b.brojnik, &b.nazivnik);

  aBR = a.brojnik; aNZ = a.nazivnik;
  bBR = b.brojnik; bNZ = b.nazivnik;

  printf("Sada unesite zeljenu operaciju: A - zbroji, B - oduzmi, C - pomnozi, D - podijeli\n");
  fflush(stdin);
  scanf("%c", &oper);


  switch(oper)
  {
    case 'A':
      c = razlomke(a, b, zbroji);
      simbol = '+';
      break;

    case 'B':
      c = razlomke(a, b, oduzmi);
      simbol = '-';
      break;

    case 'C':
      c = razlomke(a, b, pomnozi);
      simbol = '*';
      break;

    case 'D':
      c = razlomke(a, b, podijeli);
      simbol = '/';
      break;

    default:
      printf("Krivi unos!\n");
      break;
  }

  printf("%d/%d  %c  %d/%d  =  %d/%d\n", aBR, aNZ, simbol, bBR, bNZ, c.brojnik, c.nazivnik);


  system("pause");
}


//fukcije za skracivanje razlomka:

int najmanj_zaj_dj(int a, int b)
{
  int i, j;

  if(a < b)
  {
    i = a;
    a = b;
    b = i;
  }

  j = a%b;

  while(j != 0)
  {
    a = b;
    b = j;
    j = a%b;
  }

  return b;
}

_razl skrati_raz(_razl a)
{
  int d;
  _razl r;

  d = najmanj_zaj_dj(a.brojnik, a.nazivnik);
  r.nazivnik = a.nazivnik/d;
  r.brojnik = a.brojnik/d;

  return r;
}


//funkcije za operacije:

_razl zbroji(_razl a, _razl b)
{
  _razl c;

  c.nazivnik = a.nazivnik * b.nazivnik;
  c.brojnik = a.brojnik * b.nazivnik + b.brojnik * a.nazivnik;
  

  return c;
}

_razl oduzmi(_razl a, _razl b)
{
  _razl c;

  c.nazivnik = a.nazivnik * b.nazivnik;
  c.brojnik = a.brojnik * b.nazivnik - b.brojnik * a.nazivnik;

  return c;
}

_razl pomnozi(_razl a, _razl b)
{
  _razl c;

  c.nazivnik = a.nazivnik * b.nazivnik;
  c.brojnik = a.brojnik * b.brojnik;

  return c;
}

_razl podijeli(_razl a, _razl b)
{
  _razl c;

  c.brojnik = a.brojnik * b.nazivnik;
  c.nazivnik = a.nazivnik * b.brojnik;

  return c;
}


/*
Napisati program koji ce obavljati osnovne operacije s dva razlomka (zbrajanje, oduzimanje,
množenje i dijeljenje). Definirati tip podatka _razl koji se sastoji strukture koja sadrži
dvije cjelobrojne varijable (brojnik i nazivnik). Matematicke operacije obaviti pozivom funkcije
prototipa _razl razlomke(_razl, _razl, _razl(*)(_razl, _razl));, koja za argumente
prima dva razlomka te funkciju željene matematicke operacije. Operacije su: zbroji,
oduzmi, pomnozi i podijeli. Funkcija vraca rezultat zadane operacije te skracuje razlomak.
Skracivanje razlomka obaviti primjenom Euclidovog algoritma pozivom funkcije prototipa
_razl skrati(_razl);, koja za argument prima razlomak i vraca skracen. Postupak traženja
najmanjeg zajednickog djelitelja obaviti pozivom funkcije prototipa int nzd(int, int);,
koja za argumente prima dva cijela broja te vraca najmanji zajednicki djelitelj od unesena
dva broja.
*/