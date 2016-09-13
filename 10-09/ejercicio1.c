/*
Ejercicio  1
Leer  una  secuencia  de  caracteres  que  finaliza  con  un  '*'.  Se  desea determinar e informar la cantidad total de
vocales ingresadas hasta que aparece el *
*/

#include <stdio.h>
#include <conio.h>

void main()
{
    int vocal=0;
    char car;

    printf("\nInserte caracteres: \n");
    scanf(" %c",&car);
    getchar();

    while (car != '*')
    {
        if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
            vocal++;

        scanf(" %c",&car);
    }

    printf("\nSe ingresaron %i vocales",vocal);
}
