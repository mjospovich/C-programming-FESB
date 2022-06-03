#include <stdio.h>
#include <malloc.h>

void unmat(int **matrica, int red, int stup){
    int i, j;
    
    for(i=0; i<red; i++){
        for(j=0; j<stup; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", *(matrica + i) + j); // ista stvar ka &matrica[i][j])
        }
    }
} //unos matrice

int ** zbrmat(int **m1, int **m2, int red, int stup){
    int **m3;
    int i, j;
    
    m3 = (int **)malloc(red * sizeof(int *));
    
    for(i=0; i<red; i++){
        m3[i] = (int *)malloc(stup * sizeof(int));
        for(j=0; j<stup; j++){
           *(*(m3 + i) + j)    =   *(*(m1 + i) + j)  +   *(*(m2 + i) + j);
           // ista stvar m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    
    return m3;
} //zbrajanje 2 matrice

int main() {
    int brRed, brStup, i, j;
    int **mat1, **mat2, **mat3;
    
    printf("upisi broj redaka: ");
    scanf("%d", &brRed);
    printf("upisi broj stupaca: ");
    scanf("%d", &brStup);
    
    //ovo je pokazivac na pokazivac a toe ustvari niz ka niz[1]==*(niz+1)
    mat1 = (int **)malloc(brRed * sizeof(int *));
    mat2 = (int **)malloc(brRed * sizeof(int *));
    
    for (i=0; i<brRed; i++){
        mat1[i]=(int *)malloc(brStup * sizeof(int));
        mat2[i]=(int *)malloc(brStup * sizeof(int));
    }
    
    printf("unos prve matrice: \n");
    unmat(mat1, brRed, brStup);
    printf("unos druge matrice: \n");
    unmat(mat2, brRed, brStup);
    
    mat3 = zbrmat(mat1, mat2, brRed, brStup);
    
    printf("ispis trece matrice: \n");
    for (i=0; i<brRed; i++)
      for (j=0; j<brStup; j++) printf("[%d][%d]: %d\n", i, j, mat3[i][j]);

    return 0;
}

/*
Napisati program za zbrajanje dvije matrice proizvoljnih dimenzija. Dimenzije matrica korisnik određuje tijekom izvođenja programa. Zbrajanje matrica izvršiti u funkciji prototipa
int ** zbrmat(int **, int **, int, int); koja za argumente prima pokazivače na pokazivače preko kojih se pristupa matricama koje zbrajaju te broj redaka i stupaca. Funkcija
vraća adresu koja pokazuje na polje pokazivača koji pokazuju na vrijednosti rezultata zbrajanja. Unos podataka vršiti pozivom na funkciju prototipa void unmat(int **, int, int);,
koja za argumente prima pokazivač na pokazivač, te broj redaka i stupaca. Ispis rezultata
izvršiti u glavnoj funkciji. Zadatak riješiti primjenom aritmetike pokazivača.
*/