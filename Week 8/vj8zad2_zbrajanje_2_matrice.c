#include <stdio.h>
#include <stdlib.h>

void unmat(int *mat[], int r, int s){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<s; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void zbr(int *m3[], int *m2[], int *m1[], int r, int s){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<s; j++){
          m3[i][j]=m2[i][j]+m1[i][j];
        }
    }
}

int main()
{
    int i, j, red, stup;
    int *mat1[20];
    int *mat2[20];
    int *mat3[20];
    
    printf("br redova: ");
    scanf("%d", &red);
    printf("br stupaca: ");
    scanf("%d", &stup);
    
    for(i=0; i<red; i++){
        mat1[i]=(int *)malloc(stup*sizeof(int));
        mat2[i]=(int *)malloc(stup*sizeof(int));
        mat3[i]=(int *)malloc(stup*sizeof(int));
    }
    
    printf("prva matrica: ");
    unmat(mat1, red, stup);
    printf("druga matrica: ");
    unmat(mat2, red, stup);
    
     
    for(i=0; i<red; i++){
        for(j=0; j<stup; j++){
            printf("%d ", mat1[i][j]);
        }
         printf("   ");
        for(j=0; j<stup; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    zbr(mat3, mat2, mat1, red, stup);
    printf("zbrojena matrica: \n");
    for(i=0; i<red; i++){
        for(j=0; j<stup; j++){
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
Napisati program za zbrajanje matrica. Svaka matrica moˇze imati najviˇse po 20 redaka ili
stupaca. Zbrajanje matrica izvrˇsiti u funkciji prototipa void zbrmat(int *[], int *[],
int *[], int, int); koja za argumente prima polja pokazivaˇca matrica koje se zbrajaju i
matrice u koju se upisuju rezultati, te broj redaka i stupaca. Unos podataka vrˇsiti pozivom na
funkciju prototipa void unmat(int *[], int, int);, koja za argumente prima pokazivaˇc
na polje pokazivaˇca, te broj redaka i stupaca. Ispis rezultata izvrˇsiti u glavnoj funkciji.
*/