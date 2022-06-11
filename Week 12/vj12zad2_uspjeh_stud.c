#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct
{
    char naziv[MAX];
    int ocjena;
} kolegij;

typedef struct
{
    char ime[MAX], prezime[MAX];
    int mat_br, br_kolegija;
    kolegij *kolegij_stud;
} student;

student *unos(char *input, int *br_stud);
float prosjek(int br_stud, student *stud, char *naziv_kol);

int main(int argc, char *argv[])
{

    student *baza;
    int br_stud, izbor, i;
    char *ime_datoteke = argv[1];
    char *kolegiji[10] = {"Elektrotehnika", "Fizika 1", "Matematika 1", "Uvod u racunala i programiranje", "Engleski jezik 1", "Elektronika", "Fizika 2", "Matematika 2", "Programiranje", "Engleski jezik 2"};

    fprintf(stdout, "Broj ulaznih argumenata: %d\n", argc);
    fprintf(stdout, "Ime datoteke koja ce se analizirati %s\n", ime_datoteke);
    printf("\n\n");

    baza = unos(ime_datoteke, &br_stud);

    printf("Ime: %s Prezime: %s, MB: %d, broj kolegija: %d\n", baza[0].ime, baza[0].prezime, baza[0].mat_br, baza[1].br_kolegija);
    for (i = 0; i < baza[0].br_kolegija; i++)
        printf("Kolegij: %s, ocjena %d\n", baza[0].kolegij_stud[i].naziv, baza[0].kolegij_stud[i].ocjena);

    printf("Izaberite kolegij:\n");
    for (i = 0; i < 10; i++)
        printf("%d - %s \n", i, kolegiji[i]);
    printf(": ");
    scanf("%d", &izbor);
    printf("%s - %f\n", kolegiji[izbor], prosjek(br_stud, baza, kolegiji[izbor]));

    return 0;
}

student *unos(char *ime_dat, int *br_stud)
{
    student *baza;
    int i, j;
    FILE *input;

    baza = malloc(*br_stud * sizeof(student));

    input = fopen(ime_dat, "r");
    if (input == NULL)
        exit(1);

    fscanf(input, "%d", br_stud); /* vidi treba li adresni operator = ne, jer je pokazivac */

    for (i = 0; i < *br_stud; i++)
    {

        fscanf(input, "%s %s %d %d", baza[i].ime, baza[i].prezime, &baza[i].mat_br, &baza[i].br_kolegija);
        baza[i].kolegij_stud = malloc(baza[i].br_kolegija * sizeof(kolegij));
        for (j = 0; j < baza[i].br_kolegija; j++)
        {
            fscanf(input, " %[^;]; %d", baza[i].kolegij_stud[j].naziv, &baza[i].kolegij_stud[j].ocjena);
        }
    }
    fclose(input);

    return baza;
}

float prosjek(int br_stud, student *baza, char *naziv_kol)
{

    int i, j, zbr = 0, br = 0;
    for (i = 0; i < br_stud; i++)
    {
        for (j = 0; j < baza[i].br_kolegija; j++)
        {
            if (strcmp(baza[i].kolegij_stud[j].naziv, naziv_kol) == 0)
            {
                zbr = zbr + baza[i].kolegij_stud[j].ocjena;
                br++;
            }
        }
    }

    return (float)zbr / br;
}

/*
Napisati program koji iz datoteke student.txt učitava podatke o uspješnosti studenata na
prvoj godini studija. Podatke iz datoteke učitati u polje struktura koja je zadana preko tipa
podatka _student. Tip podatka je:
typedef struct {
char ime [MAX] , prezime [MAX] ;
int maticni_br , br_kolegija ;
_ kolegij ∗ kolegij_student ;
} _student;
gdje _kolegij predstavlja strukturu pojedinog kolegija:
typedef struct {
char na zi v [MAX];
int ocjena;
} _kolegij;
Učitavanje iz datoteke obaviti pozivom na funkciju prototipa _student * unos(char *, int *);
koja za argumente prima naziv datoteke i adresu cjelobrojne varijable (ukupni broj studenata), a vraća adresu prvog člana polja u kojeg su učitani podatci iz datoteke. U programu je potrebno na standardni izlaz ispisati prosjek ocjena za odabrani kolegij. Odabir
kolegija obaviti tijekom izvod—enja programa. Prosjek računati pozivom funkcije prototipa
float prosjek(int, _student *, char *);, koja za argumente prima broj unesenih studenata, adresu prvog člana niza studenata i ime kolegija čiji se prosjek računa. Funkcija vraća
trazeni prosjek. Naziv datoteke zadati s nalogodavnog retka.
Nize je prikazan oblik datoteke koji u prvom retku sadrzi ukupan broj studenata, u drugom
retku nalaze se podatci o studentu: ime, prezime, mat. br. i br. polozenih kolegija, nakon
toga navode se kolegiji i ocjena i itd.
141
Ivana Ivic 2135 5
Fizika 1; 4
Matematika 1; 2
Uvod u racunala i programiranje; 3
Fizika 2; 2
Matematika 2; 5
...
*/