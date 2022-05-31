#include <stdio.h>
#include <stdlib.h>

void Aritm(int *p[5])
{
    int i, j;
    float aritmA = 0.0, aritmR = 0.0;
    float sumaR = 0.0, suma = 0.0;
    
    for(i = 0; i<5; i++)
    {
        j = 0, suma = 0, aritmR = 0;
        
        while(p[i][j] != 0)
        {
            suma = suma + p[i][j];
            j++;
        }
        
        if (j == 0)
            aritmR = 0;
        else
            aritmR = suma/j;
        
        printf("\nAritmeticka sredina %d retka je: %.2f", i, aritmR);
        sumaR = sumaR + aritmR;
        printf("\n");
    }
    aritmA = (float)sumaR/5;
    printf("\nUkupna aritmeticka sredina je: %.2f", aritmA);
}

int main() 
{
    int i, j, n;
    int *p[5];
    
    for(i = 0; i<5; i++)
    {
        printf("Unesi broj stupaca za %d redak: ", i);
        scanf("%d", &n);
        p[i] = (int*)malloc((n+1) * sizeof(int));
        
        for (j = 0; j<n; j++)
        {
            printf("Unesi brojeve>0 p[%d][%d]: ", i, j);
            scanf("%d", &p[i][j]);
        }
        p[i][j] = 0;
    }
    
    for(i = 0; i<5; i++)
    {
        j = 0;
        
        while(p[i][j] != 0)
        {
            printf("%d ",p[i][j]);
            j++;
        }
        printf("\n");
    }
    
    Aritm(p);
    
    
    return 0;
}

/*
Zadatak je napraviti niz od pointera, koji ce predstavljati redke.
Zatim za svaki redak korisnika pitati koliko zeli stupaca te dinamicki alocirati
iste za svaki redak.
Nakon upisa brojeva u takvu strukturu, pozvati funkciju Aritm(?) koja ce primati
tu matricu kroz pointer i ispisati aritmeticku sredinu svakog retka i svih redaka.
*/