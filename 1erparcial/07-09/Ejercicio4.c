#include <stdio.h>
#include <conio.h>

void main()
{
    int exp,base,error;
    int multp = 1;
    int i=0;

    printf("\nInserte la base: ");
    scanf("%i",&base);
    printf("\nInserte el exponente: ");
    scanf("%i",&exp);
    if (base >= 0 && exp>=0)
        {
            for (i;i<exp;i++)
            multp *= base;
            i++;

        }
    else
        {
            printf("\nInserte dos numeros positivos.");
            error = 1;
        }

    if (error != 1)
        {
            printf("\nEl resultado es %i",multp);
        }

    getch();
}
