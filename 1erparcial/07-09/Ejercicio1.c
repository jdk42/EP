#include <stdio.h>
#include <conio.h>

void main()
{
    int num;
    int i=1;
    int multp=0;

    printf("\nInserte un numero: ");
    scanf(" %i",&num);

    for (i;i<=10;i++)

        {
        multp = num * i;
        printf("%i ",multp);
        }


    getch();
}
