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

void ispis(FILE *output, _student *stud);

int main()
{
    int i;
    float granica;
    char tmp[MAX];
    FILE *input, *output;
    _student stud;

    input = fopen("kolokviji.txt", "r");
    output = fopen("polozili.txt", "w");

    if ((input == NULL) || (output == NULL))
    {
        printf("Neuspjesno otvaranje datoteka");
        exit(1);
    }

    printf("Upisite granicu prolaznosti\n");
    scanf("%f", &granica);

    for (i = 0; i < 3; i++)
    {
        while (fgetc(input) != '\n')
            ;
    }
    while (feof(input) == 0)
    {
        fscanf(input, "%s %s %d", stud.ime_prezime, tmp, &stud.maticni_br);
        strcat(stud.ime_prezime, " ");
        strcat(stud.ime_prezime, tmp);

        for (i = 0; i < 5; i++)
        {
            fscanf(input, "%d", &stud.bodovi[i]);
        }
        fscanf(input, "%f", &stud.prosjek);
        if (stud.prosjek >= granica)
        {
            ispis(output, &stud);
        }
    }
    return 0;
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
Na osnovu prvog zadatka, potrebno je iz kreirane datoteke kolokvij.txt, prepisati u novu
datoteku polozili.txt one studente koji imaju prosjek veći od graničnog prosjeka koji
korisnik zadaje tijekom izvod—enja programa. U zadatku je potrebno iskoristiti funkciju
void ispis(FILE *, _student *); i tip podatka _student koji su korišteni u prvom zadatku na način da se isti kopiraju u odvojeni file ispis.h, koji će se uključiti u kôd ovog
zadatka kao vanjska5 biblioteka.
*/