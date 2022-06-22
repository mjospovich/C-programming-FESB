#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{

    char ime[50];
    int GF;
 	int GA;
 	int GR;

} klub;

void trazi(klub* , int, FILE*); //FILE* je dodano kako bi mogli ispisat u novi txt
//to je dodano, netrazi se u zadatku
int main(){

	FILE *input = fopen("rezultati.txt", "r");
	FILE *output = fopen("rez.txt", "w");
	klub *klubovi;

	int br_klub=0;
	int i=0;

	klubovi = (klub*)malloc(sizeof(klub)*MAX);//MAX je samo br 10 vidi gore

	if (input==NULL){ 
		printf("greska\n");
		exit(1);
	}

	while(feof(input) == 0){
		if(fgetc(input) == '\n') br_klub++;
	}
	br_klub--; //broji se novi red od prvog reda koji nan je nebitan

	klubovi = (klub*)realloc(klubovi, sizeof(klub)*br_klub);

	rewind(input);
	while(fgetc(input) != '\n'); //preskacemo prvi red

	for(i=0;i<=br_klub;i++){
		fscanf(input,"%s %02d %02d", klubovi[i].ime, &klubovi[i].GF, &klubovi[i].GA);
		klubovi[i].GR = klubovi[i].GF - klubovi[i].GA;
		//ispis
		printf("%s %02d %02d %02d\n", klubovi[i].ime, klubovi[i].GF, klubovi[i].GA, klubovi[i].GR);
		fprintf(output, "%s %02d %02d %02d\n", klubovi[i].ime, klubovi[i].GF, klubovi[i].GA, klubovi[i].GR);
		//if(feof(input)) break;
	}

	trazi(klubovi, br_klub, output);

	fclose(input);
	fclose(output);
	system("pause");
	system("start rez.txt");
	return 0;
}

void trazi(klub* klubovi, int br_klub, FILE* output){
	int i, maxGR, n=0;
	maxGR = klubovi[0].GR;
	for(i=1;i<=br_klub;i++){
		if(maxGR<klubovi[i].GR){
			maxGR=klubovi[i].GR;
			n = i; //redni broj kluba s najvecin GR
		}
	}
	printf ("najvecu gol razliku ima %s, gol razlika: %d\n", klubovi[n].ime, klubovi[n].GR);
	fprintf (output, "najvecu gol razliku ima %s, gol razlika: %d\n", klubovi[n].ime, klubovi[n].GR);
}

/*

10) Zadana je tekstualna datoteka proizvoljne veličine 
(sami je napravite u notepad-u) rezultati.txt koja sadrži 
rezultate malonogometnog turnira prema sljedećem formatu:

Ime kluba    GF GA

Cibalija     21 10

Istra        18 16

Karlovac     25 12

Zadar        19 9

...

Na standardni izlaz ispiši ime onog klub koji ima najveću 
gol razliku (max(GF-GA)). Koristiti strukturu koja je definirana tipom:

typedef struct{

       char ime[50];

       int GF;

       int GA;

} klub;

b.     (10) Zadatak riješiti koristeći dinamičku alokaciju memorije, funkciju 
realloc(), čime se svi podaci iz datoteke pohrane u polje struktura. Traženje 
kluba s najvećom gol razlikom obaviti u posebnoj funkciji prototipa v
oid trazi(klub *, int); gdje je prvi argument adresa polja 
tipa strukture klub, a drugi argument veličina tog polja.
 
*/
