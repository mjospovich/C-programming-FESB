// Online C compiler to run C program online
#include <stdio.h>


void Dijagonala(char znakovi[5][5], int *gMax, int *sMax, int m, int n)
{
    int i, j, z;
    
    for(i = 0; i<m; i++)
    for(j = 0; j<n; j++)
    {
        z = znakovi[i][j];
        
        if(i == j)
        {
            if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u')
                (*gMax)++;
        }
        
        if(i == (n-j-1))
        {
            if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u')
                (*sMax)++;
        }    
    }
}

int main() {
    
    char znakovi[5][5];
    int i,j,m,n, gMax=0, sMax=0;
    
    //unos korisnika
    printf("Unesite velicinu polja: [i] [j] \n");
    scanf("%d %d", &m,&n);
    
    //unos znakova u matricu
    for(i = 0; i<m; i++)
    for(j = 0; j<n; j++)
    {
        printf("Unesi clan znakovi[%d][%d]: ",i,j);
        scanf("%s", &znakovi[i][j]);
        printf("\n");
    }
    
    //ispis glavne i sporedne dijagonale
    for(i = 0; i<m; i++)
    for(j = 0; j<n; j++)
    {
        if(i == j)
            printf("%c",znakovi[i][j]);
    
        else if(i == (n-j-1))
            printf("%c",znakovi[i][j]);
    }
    
    //poziv funkcije koja broji samoglasnike na dijagonalama
    Dijagonala(znakovi, &gMax, &sMax, m, n);
    
    //ispis rezultata dobivenih u funkciji
    printf("\nBroj samoglasnika na glavnoj dijagonali: %d", gMax);
    printf("\nBroj samoglasnika na sporednoj dijagonali: %d", sMax);
    printf("\n");
    
    return 0;
}