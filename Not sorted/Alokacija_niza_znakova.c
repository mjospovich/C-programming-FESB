#include <stdio.h>
#include <stdlib.h>


void Ispis(char *X, int n, int *br) 
//1. isto kao char X[], 2. obican integer jer nista ne triba vracat, 
//3. pointer jer trebamo vratit tu vrijednost u main.
{
    for (int i = 0; i<n; i++)
    {
        if((X[i] % 2) == 0)
            {
                printf("Adresa X[%d]: %d\n",i, X[i]);
                (*br)++;
            }
    }
}

int main() 
{
    int n = 0, br = 0;
    char *X = (char*)malloc(50*sizeof(char));
    //alociramo pocentu memoriju prije nego znamo koliko korisnik zeli
    
    printf("Unesi zeljeni broj znakova!\n");
    scanf("%d", &n);
    
    X = (char*)realloc(X, n*sizeof(char));
    //nakon sto saznamo koliko zeli, relociramo memoriju na tocno tolko
    
    for (int i = 0; i<n; i++)
    {
        printf("Unos X[%d]: ", i);
        scanf("%s", &X[i]);
        printf("\n");
    }
    
    printf("\nAdrese clanovo s parnom ASCII vrijednosti:\n");
    Ispis(X, n, &br);
    //poziv ispis funkcije (niz, broj clanova, adresa br integera)
    
    printf("\nTakvih brojeva je: %d\n",br);
    
    system("pause");
    return 0;
}


/*
Dinamički alocirati niz znakova (prethodno pitati korisnika) te provjeriti koji
znakovi su na parnim adresnim mjestima, prebrojit ih te ispisat koji su!
*/