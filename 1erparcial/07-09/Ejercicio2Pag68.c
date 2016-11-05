#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,division,acumulador;
    acumulador=0;
    for (i=1;i<=8000;i++) /* Rango de numeros */
        {
            for(j=1;j<i;j++) /* divisores*/
                if(i%j==0)
                    acumulador +=j;

                if (acumulador == i) // sigue adentro del for, determina si es perfecto
                    printf("\n%d es un numero perfecto.",i);

            acumulador =0; // pone en 0 la variable y repite el proceso
        }
    }




