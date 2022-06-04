#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ovo je matrica koja za redove pokazuje nizove znakova (recenice)

int brzn(char **niz, int n, char c){
    int i, j, br, brMax=0, imax; //imax je u kojoj rec po redu ima najvise tih znakova
    
    for(i=0; i<n; i++){
        br = 0; j = 0;
        while (niz[i][j] != '\0'){
            if (niz[i][j] == c) br++;
            j++;
        }
        if (brMax < br){
            brMax = br;
            imax = i;
        }
    }
    return imax;
}

int main() {
    char znak, rec[80], **rniz=NULL;
    int i, j, brRec = 0, brSlova, red;
    
    do{
        printf("%d. recenica: ", brRec + 1); //da neide od 0.te
        fgets(rec, sizeof(rec), stdin);
        brSlova = strlen(rec) - 1; //funkija sta broji znakove u stringu, -1 jer je zadnji uvik \0 za kraj striga
        if (brSlova == 0) break; //prazna recenica, iznacuje nas iz petlje
        brRec++;
        
        rniz = (char **)realloc(rniz, brRec * sizeof(char *));
        if (rniz == NULL) return 1; //iskreno nisan svatia cemu ovo sluzi radi isto bez?
        
        rniz[brRec - 1] = (char *)malloc((brSlova + 1) * sizeof(char));
        j = 0;
        while(rec[j] != '\n'){
            rniz[brRec - 1][j] = rec[j]; //prepisujemo napisanu rec u matricu
            j++;
        }
    } while (brSlova != 0);
    
    printf ("unesi slovo: ");
    scanf(" %c", &znak);
    
    red = brzn(rniz, brRec, znak);
    printf("u recenici: %s ima najvise tog slova", *(rniz + red)); //isto ka rniz[red]
    
    return 0;
}

/*
Napisati program u kojem korisnik sa standardnog ulaza unosi proizvoljan broj riječi i jedan
znak. Program treba ispisati onu riječ u kojoj se uneseni znak pojavljuje najviše puta. Koristiti funkciju prototipa int brzn(char **, int, char); koja za argument prima pokazivač
na polje znakovnih nizova, broj znakovnih nizova u nizu, te slovo koje se ispituje. Funkcija
vraća indeks znakovnog niza s najviše pojavljivanja traženog znaka. Najveća dužina jednog
niza znakova neka je 80. Znakovni nizovi se unose sve dok se ne unese prazni redak. Unesene
znakovne nizove kopirati u polje znakovnih nizova koje treba zauzeti memorije točno koliko
ima znakova i pojedinom nizu.
Napomena: Za određivanje duljine znakovnog niza koristiti funkciju int strlen(char *);
koja za argument prima pokazivač na znakovni niz, te vraća broj znakova u nizu. Funkcija se
nalazi u biblioteci string.h.
*/