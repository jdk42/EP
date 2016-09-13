#include <stdio.h>
#include <conio.h>

void main()
{
    int numero,n=0,suma=0;

    printf("\nInserte un numero: ");
    scanf("%i",&numero);

    while ( n < numero)
    {
        n++;
        suma+=n;
    }

    printf("\nEl total es %i",suma);
}
