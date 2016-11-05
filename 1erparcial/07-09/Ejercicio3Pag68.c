#include <stdio.h>
#include <conio.h>

/*
 ______ _____            _____ _____ _
 |  ____|  __ \     /\   / ____|_   _| |
 | |__  | |__) |   /  \ | |  __  | | | |
 |  __| |  _  /   / /\ \| | |_ | | | | |
 | |    | | \ \  / ____ \ |__| |_| |_| |____
 |_|    |_|  \_\/_/    \_\_____|_____|______|

 */

void main()
{
    int temperatura,hora,dia,mes,maximo,minimo,contador600,maximo600,mes600;
    float promedio;

    promedio = 0;

    for (mes=1;mes<=12;mes++)
    {
        for (dia=1;dia<=31;dia++)
        {
            for (hora=1;hora<=24;hora++)
            {
                printf("\nSon las %d del %d del mes %d",hora,dia,mes);
                printf("\nInserte una temperatura:");
                scanf("%i",&temperatura);

                if (minimo > temperatura)
                    minimo = temperatura;
                if (maximo < temperatura)
                    maximo =temperatura;

                promedio += temperatura;
            }
            printf("\nLa menor temperatura del dia %d a las %d del mes %d fue de %d.",dia,hora-1,mes,minimo);

            temperatura=0;

            if (maximo > 600)
                contador600++;
        }
        if (maximo600 < contador600 )
            {
                maximo600 = contador600;
                mes600 = mes;
            }

        contador600 = 0;
    }
    promedio = promedio/(30*12*24);
    printf("\nEl promedio es %.2f",promedio);
    printf("\nEl mes con mayores temperaturas fue el mes numero %d con un total de %d",mes600,maximo600);
}
