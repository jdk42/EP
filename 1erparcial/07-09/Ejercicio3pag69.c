#include <stdio.h>
#include <conio.h>

void main()
{
    float temperatura,maxima,minima,promedio;
    int i,j,ordenmax,ordenmin,contadorpromedio=0;

    for (i=0;i<18;i++)
    {
        printf("\nInserte la temperatura: ");
        scanf(" %f",&temperatura);

        if (temperatura > maxima)
            {
                maxima = temperatura;
                ordenmax = i;
            }
        if (temperatura < minima)
            {
                minima = temperatura;
                ordenmin = i;
            }

        if (temperatura < 0)
        {
            promedio += temperatura;
            contadorpromedio++;
            }

    }
    promedio = (float)(promedio / contadorpromedio);
    printf("\nEl mayor valor ingresado es de %.2f ingresado numero %d",maxima,ordenmax+1);
    printf("\nEl menor valor ingresado es de %.2f ingresado numero %d",minima,ordenmin+1);
    printf("\nEl promedio de los negativos ingresados es de %.2f",promedio);

    getch();
}
