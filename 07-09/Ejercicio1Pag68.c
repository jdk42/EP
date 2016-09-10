#include <stdio.h>
#include <conio.h>
void main()
{
    int cant_lineas,aster,linea,espacio;
    cant_lineas = 6;
    espacio = 1;

    for (linea = 1;linea <=cant_lineas;linea++) // Part de arriba
        {
            for (aster=1;aster<=cant_lineas-linea;aster++) // Se repite hasta que la cantidad de espacios sea igual a la cantidad de lineas (6) menos la linea actual.
                printf(" ");

            for (aster = 1; aster <=2*linea;aster++)
                printf("*");
        printf("\n");
        }

        for (linea = cant_lineas-1;linea>=1;linea--) // Part de abajo. La linea es igual al maximo de lineas (6) y se le resta 1 para formar la linea de abajo. Sigue bajando hasta que linea sea igual a 1
        {
            for (aster=1;aster<=cant_lineas-linea;aster++)
                printf(" ");

            for (aster = 1; aster <=2*linea;aster++)
                printf("*");
        printf("\n");
        }

}
