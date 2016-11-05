#include <conio.h>
#include <stdio.h>
#define AGENCIAS 15
#define TOURS 40

void cambio(float vec[]);
void cambioarray2d(float vec[][TOURS]);
void promedios_(float vec[][TOURS]);

int main()
{
    int i=0,j=0,agencia,tour,cantpasajes,mayor=0,maxagencia;
    float matriz[AGENCIAS][TOURS],maximaagencia[AGENCIAS];

    cambioarray2d(matriz);

    do
    {
        printf("Inserte cod. de agencia: ");
        scanf("%i",&agencia);
    }
    while(agencia<0 || agencia > 15);

    while ( agencia != 0)
    {
    do
    {
        printf("Inserte tour: ");
        scanf("%i",&tour);
    }
    while(tour<0 || tour > 40);

    do
    {
        printf("Inserte cantidad de pasajes: ");
        scanf("%i",&cantpasajes);
    }
    while(cantpasajes<0 || cantpasajes > 20);

    matriz[agencia-1][tour-1] += cantpasajes;


    do
    {
        printf("Inserte cod. de agencia: ");
        scanf("%i",&agencia);
    }
    while(agencia<0 || agencia > 40);

    }

    promedios_(matriz);

    /*Agencia con mayor cantidad de pasajes*/

    for(i=0;i<AGENCIAS;i++)
    {
        for(j=0;j<TOURS;j++)
        {
            maximaagencia[i] += matriz[i][j];
        }
    }

    for(i=0;i<AGENCIAS;i++)
    {
        if(maximaagencia[i]>mayor)
        {
            maxagencia = i+1;
            mayor = maximaagencia[i];
        }
    }

    printf("\n");
    printf("\nLa agencia que mas pasajes vendio fue la nro. %d con un total de %d pasajes\n",maxagencia,mayor);

    /*Pasajes sin ventas*/
    for (i=0;i<AGENCIAS;i++)
    {
        printf("\nAgencia nro %d :",i+1);
        printf("\nPasajes sin venta: ");
        for(j=0;j<TOURS;j++)
        {
            if (matriz[i][j] == 0)
                printf("%d ",j+1);
        }
        printf("\n");
    }



return(0);
getch();
}


void cambio(float vec[])
{
    int i;
    for(i=0;i<TOURS;i++)
    vec[i]=0;
    return;
}

void cambioarray2d(float vec[][TOURS])
{
    int i,j;
    for(i=0;i<AGENCIAS;i++)
    {
        for(j=0;j<TOURS;j++)
                vec[i][j]=0;
    }
    return;
}

void promedios_(float vec[][TOURS])
{
    int i,j;
    float pasajesxtours[TOURS],sumador[TOURS],promedios[TOURS];

    cambio(pasajesxtours);
    cambio(sumador);
    cambio(promedios);

    for(i=0;i<AGENCIAS;i++)
    {
        for(j=0;j<TOURS;j++)
        {
            pasajesxtours[j] += vec[i][j];
            if (vec[i][j] != 0)
            {
                sumador[j]++;
            }
        }
    }


    for(i=0;i<TOURS;i++)
    {
        if (sumador[i] != 0)
        {
            promedios[i] = pasajesxtours[i]/sumador[i];
         }
         else
         {
             promedios[i] = 0;
         }
    }


    for(i=0;i<TOURS;i++)
    {
            printf("\nPromedio pasaje tour %d es %.2f",i+1,promedios[i]);
            }
    return;
}
