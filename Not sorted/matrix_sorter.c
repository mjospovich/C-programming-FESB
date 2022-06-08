#include<stdio.h>
#include<stdlib.h>

void upis(int**, int);
void ispis(int**, int);
void sorter(int**, int);


int main(void)
{
  int i, j, n;
  int **mat;

  printf("Upisite velicinu vase kvadratne matrice: ");
  scanf("%d", &n);

  //alokacija matrice
  mat = (int**)malloc(sizeof(int)*n);
  for(i = 0; i < n; i++)
    mat[i] = (int*)malloc(sizeof(int)*n);


  //upis matrice
  upis(mat, n);

  //ispis matrice
  ispis(mat, n);

  //sortiranje matrice
  system("pause");
  sorter(mat, n);
  ispis(mat, n);

  system("pause");
}



void upis(int **matrix, int numRows)
{
  char kraj;
  int i,j;

  while(1)
  {
     for(i = 0; i < numRows; i++)
      {
        for(j = 0; j < numRows; j++)
        {
          printf("Unesi arr[%d][%d]: ", i, j);
          scanf("%d", &matrix[i][j]);
        }
        printf("\n");
      }

    fflush(stdin);
    printf("Jeste li zadovoljni su upisom: y/n?\n");
    scanf("%c", &kraj);

    if(kraj == 'y')
      break;

  }
  system("cls");

}



void ispis(int **matrix, int numRows)
{
  int i, j;
  
  printf("Ispis matrice:\n");
  for(i = 0; i < numRows; i++)
  {
    for(j = 0; j < numRows; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

}


void sorter(int **matrix, int numRows)
{
  int temp = 0;
  int flag = 0;
  int i, j;

  for(i = 0; i < numRows; i++)
  {
    j = 0;

    while (1)
    {
      
      if (j == numRows)
      {
        j = 0;
        flag = 0;
      }

      if (matrix[i][j+1] <= matrix[i][j])
      {
        temp = matrix[i][j];
        matrix[i][j] = matrix[i][j+1];
        matrix[i][j+1] = temp;

        flag = 1;
        temp = 0;
      }

      j++;

      if(flag == 0 && j == numRows-1)
        break;
      
    }
  }

}




/*
Kreirati kvadratnu matricu i dinamički je alocirati, upis i ispis obaviti zasebnim
funkcijama. Dodati funkciju koja sortira redove matrice od najmanjem prema najvecem
ili obratno. Ponovno ispisati matricu pomocu funkcije ispis.
*/