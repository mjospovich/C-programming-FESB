#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char ime_prezime[MAX];
    int maticni_br;
    int bodovi[5];
    float prosjek;
} _student;

float prosjek(_student *stud);
void ispis(FILE *output, _student *stud);

int main()
{

    _student *stud;
    int br_stud;
    int i, j;
    char tmp[MAX];

    FILE *input, *output;

    input = fopen("lista.txt", "r");
    output = fopen("kolokviji.txt", "w");

    if ((input == NULL) || (output == NULL))
    {
        printf("Neuspjesno otvaranje datoteka");
        exit(1);
    }

    while (!feof(input))
    {
        if (fgetc(input) == '\n')
            br_stud = br_stud + 1;
    }
    rewind(input);

    stud = malloc(br_stud * sizeof(_student));

    for (j = 0; j < br_stud; j++)
    {
        fscanf(input, "%s %s %d", stud[j].ime_prezime, tmp, &stud[j].maticni_br);
        strcat(stud[j].ime_prezime, " ");
        strcat(stud[j].ime_prezime, tmp);
        for (i = 0; i < 5; i++)
            fscanf(input, "%d", &stud[j].bodovi[i]);
        stud[j].prosjek = prosjek(stud + j);
    }

    for (i = 0; i < br_stud; i++)
    {
        ispis(output, stud + i);
    }
    return 0;
}

float prosjek(_student *stud)
{
    int i, suma = 0;

    for (i = 0; i < 5; i++)
    {
        suma = suma + stud->bodovi[i];
    }
    return (float)suma / 5;
}

void ispis(FILE *output, _student *stud)
{
    int i;

    fprintf(output, "\n%-27s %-5d ", stud->ime_prezime, stud->maticni_br);

    for (i = 0; i < 5; i++)
        fprintf(output, "%-.3d ", stud->bodovi[i]);

    fprintf(output, "      %5.2f", stud->prosjek);

    fprintf(output, "\n");
}

/*
Napisati program u kojem se u strukturu zadanu kao tip podataka _student unose podatci o
studentima koji se nalaze u datoteci na disku. Tip podataka _student jest struktura podataka
oblika:
typedef struct {
char ime_prezime [MAX] ;
int maticni_br ;
int bodovi [ 5 ] ;
float prosjek;
} _student ;
U strukturu se unose podatci o postignutim bodovima na kolokviju. Kolokvij sadrži pet
pitanja gdje svako pitanje nosi najviše 20 bodova. Za svakog studenta se, tijekom unosa,
izračunava i prosječna uspješnost na kolokviju koristeći funkciju prototipa float prosjek
(_student *);, gdje funkcija za argument prima adresu strukture čiji se prosjek računa, a
vraća izračunat prosjek. Uneseno polje podataka je potrebno pomoću poziva funkcije prototipa void ispis(FILE *, _student *); pohraniti u tekstualnu datoteku "kolokvij.txt"
na tvrdom disku. Funkcija za argumente prima pokazivač na datotečni tok i adresu onog
člana strukture koji se upisuje u datoteku.

*/
