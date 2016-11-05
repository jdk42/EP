#include <stdio.h>
#include <conio.h>

void main()
{
    int numero,error,i,cero,contadorpositivo,contadornegativo;
    float promnegativo,prompositivo;
    error = 0;
    cero = 0;
    promnegativo = 0;
    prompositivo = 0;
    contadornegativo = 0;
    contadorpositivo = 0;

    for (i=1;i<=12;i++)
        {
        printf("\nInserte un numero: ");
        scanf("%i",&numero);

        if (numero <= 12)
            {
            if (numero > 0)
                {
                    prompositivo += numero;
                    contadorpositivo++;
                }
            else if (numero < 0)
                {
                    promnegativo += numero;
                    contadornegativo++;
                }
            else if (numero == 0)
            {
                cero++;
            }
            }
        else
            {
            printf("\nVALOR EXCEDIDO");
            error++;
            break;
            }

        }

    if (contadornegativo > 0)
        promnegativo = (float)(promnegativo/(contadornegativo));
    else
        promnegativo = 0;

    if (contadorpositivo > 0)
        prompositivo = (float)(prompositivo/contadorpositivo);
    else
        prompositivo = 0;

    if (error < 1 )
    {
        printf("\nEl promedio de positivos es %.2f",prompositivo);
        printf("\nEl promedio de negativos es %.2f",promnegativo);
        printf("\nLa cantidad de ceros es %d",cero);
    }
}
