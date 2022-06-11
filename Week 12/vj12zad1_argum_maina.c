#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) // moze i char **argv
{
    char *ime_datoteke = argv[1];
    char znak;

    FILE *input;
    input = fopen(ime_datoteke, "r");

    printf("\n\n");
    while (!feof(input))
    {
        znak = fgetc(input);
        fprintf(stdout, "%c", znak);
    }
    printf("Kraj ispisa\n\n");

    return 0;
}

/*
Napisati program koji će na zaslon računala ispisati sadrzaj nekoga spisa. Ime spisa treba
zadati zajedno s imenom programa (argument s nalogovnoga retka).
*/