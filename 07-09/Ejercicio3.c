#include <stdio.h>
#include <conio.h>

void main()
{
    int suma=0,num,i;


    printf("Inserte un numero: ");
    scanf("%i",&num);

    i=num;

    for (i;i>0;i--)
        suma+=i;
        i--;

    printf("%d",suma);
    getch();
}
