#include <stdio.h>


char *fun(int m){
    char *mjSlova[]={"sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac"};
    return *(mjSlova + m - 1); 
}

int main() {
    int dan, mj, god;

    do{
        printf("unesi datum (dan): ");
        scanf("%d", &dan);
    }while(dan < 0 || dan > 31);

    do {
        printf("unesi datum (mjesec): ");
        scanf("%d", &mj);
    }while(mj < 0 || mj > 12);

    do{
        printf("unesi datum (godina): ");
        scanf("%d", &god);    
    }while(god < 0);

    printf("Datum je %d.%d.%d. \n", dan, mj, god);
    printf("Datum je %d. %s %d. \n", dan, fun(mj), god);
    return 0;
}

/*
Napisati program koji pretvara naˇcin prikaza unesenog datuma. Datum se unosi u obliku
DD.MM.GGGG te nakon poziva funkcije prototipa char * mjesec(int); potrebno je isti
prebaciti u oblik DD.MMMM.GGGG. Funkcija za argument prima cijeli broj (mjesec), a za
rezultat vra´ca znakovni niz. U programu je potrebno prije poziva funkcije ispitati brojˇcanu
ispravnost unesenog mjeseca
*/