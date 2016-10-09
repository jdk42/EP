#include <stdio.h>
#include <conio.h>
#define LEGAJOS 50
#define DIAS    24
#define HORAS   12

int validar(int,int);
int main()
{
    int dia,aux,horasmayor=0,sen=0,horas,sueldos[LEGAJOS],legajo,empleados[LEGAJOS][DIAS],i=0,j=0,acumuladorHoras=0,acumulador[DIAS],horastotales=0,horastotalesXempleado[LEGAJOS];

    for (i=0;i<LEGAJOS;i++)
    {
        for (j=0;j<DIAS;j++)
        {
                    empleados[i][j] = 0;
        }
    }

    for (j=0;j<DIAS;j++)
        {
                    acumulador[j] = 0;
        }

    for (i=0;i<LEGAJOS;i++)
        {
                    horastotalesXempleado[i] = 0;
        }

           for (i=0;i<LEGAJOS;i++)
        {
                   sueldos[i] = 0;
        }

    printf("\nInserte numero de legajo: ");
    legajo = validar(0,50);

    while (legajo != 0)
    {
        printf("\nInserte dia: ");
        dia = validar(1,24);

        printf("\nInserte horas: ");
        horas = validar(1,12);

        empleados[legajo-1][dia-1] = horas;

        printf("\nInserte numero de legajo: ");
        legajo = validar(0,50);
    }

    printf("\nDIA \t HORAS TRABAJADAS");

    for (i=0;i<LEGAJOS;i++)
    {
        for (j=0;j<DIAS;j++)
        {
                    acumulador[j] += empleados[i][j];
        }
    }

        for (j=0;j<DIAS;j++)
        {
                    printf("\n%d \t %d",j+1,acumulador[j]);
        }

    for (i=0;i<LEGAJOS;i++)
    {
        for (j=0;j<DIAS;j++)
        {
                    horastotales += empleados[i][j];
        }
    }

    printf("\nHoras totales: %d",horastotales);

    for (i=0;i<LEGAJOS;i++)
    {
         for (j=0;j<DIAS;j++)
        {
            horastotalesXempleado[i] += empleados[i][j];
        }
    }

    for (i=0;i<LEGAJOS;i++)
    {
        sueldos[i] = (horastotalesXempleado[i])*15;
    }

    for(i=0;i<LEGAJOS;i++)
    {
        for(j=0;j<LEGAJOS-1;j++)
        {
            if (sueldos[j] < sueldos[j+1])
            {
                aux=sueldos[j];
                sueldos[j]=sueldos[j+1];
                sueldos[j+1]=aux;

            }
        }
    }

    printf("\nLEGAJO \t SUELDO");

    for (i=0;i<LEGAJOS;i++)
    {
        printf("\n%d \t %d",i+1,sueldos[i]);
    }

    for(i=0;i<LEGAJOS;i++)
    {
        if (sen==0)
        {
            horasmayor = horastotalesXempleado[i];
            sen = 1;
        }
        else
        {
            if (horasmayor < horastotalesXempleado[i])
            {
                horasmayor = horastotalesXempleado[i];
            }
        }
    }

    printf("\nLEGAJO \t HORAS TOTALES");
    for (i=0;i<LEGAJOS;i++)
    {
        if (horasmayor == horastotalesXempleado[i])
            printf("\n%d \t %d",i+1,horasmayor);
    }

    printf("\n Empleados que no trabajaron: ");

    for(i=0;i<LEGAJOS;i++)
    {
        if(horastotalesXempleado[i] == 0)
            printf("%d  ",i+1);
    }

    getch();
    return 0;
}

int validar(int li,int ls)
{
    int dato;

    do
    {
        scanf("%i",&dato);
    }
    while(dato < li || dato > ls);

    return (dato);
}
