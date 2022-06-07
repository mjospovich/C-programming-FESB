#include <stdio.h>
#include <stdlib.h>


float Operation(float a, float b, float(*Fun)(float, float))
{
    return Fun(a,b);
}

float Add(float a, float b);
float Subtract(float a, float b);
float Multiply(float a, float b);

int main()
{
    int choice = 0;
    char sign;
    float a, b, result;
    float (*formula)(float, float);
    
    printf("Enter two decimal numbers you'd like to work with!\n");
    scanf("%f %f", &a, &b);
    printf("\n\n");
    
    do{
        printf("1 - Add || 2 - Subtract || 3 - Multiply\n");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 3)
            break;
        
    }while (1);
    
    switch (choice)
    {
        case 1:
            formula = Add;
            sign = '+';
            break;
        case 2:
            formula = Subtract;
            sign = '-';
            break;
        case 3:
            formula = Multiply;
            sign = '*';
            break;
        default:
            break;
    }
    
    result = Operation(a, b, formula);
    
    printf("\nResult:");
    printf("\n%.3f %c %.3f = %.3f\n", a, sign, b, (float)result);
    
    return 0;
}

float Add(float a, float b)
{
    return a + b;
}

float Subtract(float a, float b)
{
    return a - b;
}

float Multiply(float a, float b)
{
    return a * b;
}