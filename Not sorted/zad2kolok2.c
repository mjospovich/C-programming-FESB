#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char korisnik[50];
	char adresa[30];
    char broj[15];

} osoba;

void ispis(osoba *, int);

int main(){

	int N;
	int i=0;

	osoba *lik;

	printf("upisi br osoba: ");
	scanf("%d", &N);

	lik = (osoba*)malloc(N * sizeof(osoba));

	for(i=0;i<N;i++){
		fflush(stdin);
		printf("ime i prezime %d. lika:\n", i);
		scanf("%[^\n]s", lik[i].korisnik);
		fflush(stdin);
		printf("adresa %d. lika:\n", i);
		scanf("%[^\n]s", lik[i].adresa);
		fflush(stdin);
		printf("tel.broj %d. lika:\n", i);
		scanf("%s", lik[i].broj);
		fflush(stdin);
	}

	ispis(lik, N);
	return 0;
}

void ispis(osoba* lik, int N){

	FILE *output = fopen("adresar.txt", "w");
	int i=0, j=0;

	osoba temp;

	fprintf(output, "KORISNIK\t\tADRESA\t\tTEL.BROJ\n");

//dio za dio b koi ne radi
/*
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if(strcmp(lik[i].korisnik, lik[j].korisnik)<0){
				temp=lik[i];
				lik[i]=lik[j];
				lik[j]=temp;
			}
		}
	}
*/
	for(i=0;i<N;i++){
		fprintf(output ,"%s\t\t%s\t\t%s\n", lik[i].korisnik, lik[i].adresa, lik[i].broj);
	}
	system("pause");
	fclose(output);
	system("start adresar.txt");
}


/*

10) Potrebno je izraditi program koji će stvoriti tekstualnu datoteku adresar.txt u sljedećem obliku:

KORISNIK            ADRESA        TEL.BROJ

Juric Jure          Drziceva 10         021/123456

.....

 

Korisnik unos podatke za N osoba (koristiti dinamičku alokaciju memorije) te ih sprema u polje čiji je 
član definiran strukturom tipa:

typedef struct{

       char korisnik[50];

char adresa[30];

       char broj[15];

} osoba;

Ispis polja u datoteku obaviti u posebnoj funkciji prototipa void ispis(osoba *, int); gdje je prvi 
argument adresa polja tipa strukture osoba, a drugi argument veličina tog polja.

b.     (10) Ispis u datoteku obaviti abecedno po vrijednosti niza korisnik.

*/