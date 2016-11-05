#include <stdio.h>
#include <conio.h>

void main()
{
    int n,i,cont=0;

    printf("\nInserte un numero: ");
    scanf("%i",&n);

    for (i;i<n;i++)
        if ((n % i) == 0)
            cont++;

    if (cont<1)
        printf("\nEl numero es primo.");
    else
        printf("\nEl numero no es primo.");

    getch();
}
