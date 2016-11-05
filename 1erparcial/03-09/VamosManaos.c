#include <stdio.h>
#include <conio.h>

void main()
{
    int cantidad_DeEnvases,i,cantidad_DeM,cantidad_DeE,VinoMaximo,cantidad_TotalEnvases,error;
    char clase_DeVino,ClaseMaxima,clase_DeVinoMayuscula;
    float porcentaje_VinosE;

    //Inicialización de variables
    cantidad_DeEnvases = 0;
    i = 0;
    error = 0;
    cantidad_DeM = 0;
    cantidad_DeE = 0;
    VinoMaximo = 0;
    cantidad_TotalEnvases = 0;
    porcentaje_VinosE = 0;

    for (i=0;i<200;i++)
    {
        printf("\nIngrese clase de vino: ");
        scanf(" %c",&clase_DeVino);
        if (isalpha(clase_DeVino))
            {
                clase_DeVinoMayuscula = toupper(clase_DeVino);
                printf("\nIngrese cantidad de vinos: ");
                scanf(" %i",&cantidad_DeEnvases);

                if (clase_DeVinoMayuscula == 'M') // Si el vino es M, le suma la cantidad de envases
                    {
                        cantidad_DeM += cantidad_DeEnvases;
                    }

                if (clase_DeVinoMayuscula == 'E') // Si el vino es E, le suma la cantidad de envases
                    {
                        cantidad_DeE += cantidad_DeEnvases;
                    }

                if ((cantidad_DeEnvases == 1 )||(cantidad_DeEnvases > VinoMaximo)) // Determina el vino con mayor cantidad de envases
                    {
                        VinoMaximo = cantidad_DeEnvases;
                        ClaseMaxima = clase_DeVinoMayuscula;
                    }

                cantidad_TotalEnvases += cantidad_DeEnvases; // Guarda la cantidad total de envases
            }
        else
            {
                printf("\nIngresa un caracter correcto [A-Z]");
                error++;
            }
    }

    if (error < 200)
        {
            printf("\nLa mayor cantidad de envases son del vino clase %c , con un total de %d.",ClaseMaxima,VinoMaximo);
            printf("\nHay %d envases del vino de clase M.",cantidad_DeM);
            porcentaje_VinosE = (float)(cantidad_DeE * 100) / cantidad_TotalEnvases;
            printf("\nLos vinos clase E (%d) representan un %.2f %% del total (%d).",cantidad_DeE,porcentaje_VinosE,cantidad_TotalEnvases);
        }
    else
        {
            printf("\nIntenta de nuevo, la clase de vino solo puede ser un caracter del intervalo [A-Z].");
        }
    getch();
}
