#include<stdio.h>
#include<stdlib.h>

void upis(int**, int);
void ispis(int**, int);
void sorter(int**, int, int(*Fun)(int, int));
int vece(int, int);
int manje(int, int);


int main(void)
{
  int i, j, n;
  int **mat;
  char op;

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
  fflush(stdin);
  printf("\nZelite li sort < ili >?\n");
  scanf("%c", &op);

  if (op == '>')
    sorter(mat, n, vece);
  else
    sorter(mat, n, manje);
  
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



void sorter(int **matrix, int numRows, int(*Fun)(int, int))
{
  int temp = 0;
  int flag = 0;
  int i, j;

  for(i = 0; i < numRows; i++)
  {
    j = 0;

    while (1)
    {
      
      for(j = 0; j<numRows-1; j++)
      {
        if (Fun(matrix[i][j+1], matrix[i][j]))
        {
          temp = matrix[i][j];
          matrix[i][j] = matrix[i][j+1];
          matrix[i][j+1] = temp;

          flag = 1;
          temp = 0;
        }

        else
          continue;
      }

      if(flag == 0)
        break;

      flag = 0;
      
    }
  }

}


int manje(int a, int b)
{
  return a < b;
}

int vece(int a, int b)
{
  return a > b;
}


/*
Kreirati kvadratnu matricu i dinamički je alocirati, upis i ispis obaviti zasebnim
funkcijama. Dodati funkciju koja sortira redove matrice od najmanjem prema najvecem
ili obratno. Ponovno ispisati matricu pomocu funkcije ispis.
*/