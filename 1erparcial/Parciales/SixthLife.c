#include <conio.h>
#include <stdio.h>
#define CAMIONES 80
#define MESES 12

int validar(int,int);
void ordenar(float vec[]);

int main()
{
    float vector13[MESES]={0},importe[CAMIONES][MESES]={{0}},sumaEspecial=0,minkms,kilometros[CAMIONES][MESES]={{0}},impt,kms,totalxCamion[CAMIONES]={0},totalxCamionKms[CAMIONES]={0};
    int camion,mincamion,mes,i,j,contador=0,sen=0,mes1st,dia1st;

    printf("Ingrese el mes: ");
    mes1st = validar(1,12);
    if (mes1st==2)
    {
    printf("Ingrese el dia: ");
    dia1st = validar(1,28);

    }
    else if (mes1st == 4 || mes1st==6 || mes1st==9 || mes1st == 10)
    {
            printf("Ingrese el dia: ");
    dia1st = validar(1,30);

    }
    else
    {
    printf("Ingrese el dia: ");
    dia1st = validar(1,31);

    }

    printf("\nInserte el camion: ");
    camion = validar(0,80);

    while (camion != 0)
    {
        printf("\nInserte el mes: ");
        mes = validar(1,12);

        printf("\nInserte el importe: ");

        do
        {
            scanf("%f",&impt);
        }
        while(impt < 0);

        printf("\nInserte cantidad de kilometros: ");

        do
        {
            scanf("%f",&kms);
        }
        while(kms < 0);

        importe[camion-1][mes-1] += impt;
        kilometros[camion-1][mes-1] += kms;

        printf("\nInserte el camion: ");
        camion = validar(0,80);

    }

    for(i=0;i<CAMIONES;i++)
    {
        for(j=0;j<MESES;j++)
        {
            totalxCamion[i] += importe[i][j];
        }
    }

    printf("%d/%d/2016",dia1st,mes1st);

    printf("\nNRO CAMION\t\tTOTAL RECAUDADO");

    for(i=0;i<CAMIONES;i++)
    {
        printf("\n");
        printf("%d\t\t%.2f",i+1,totalxCamion[i]);
    }

    printf("\nCAMIONES SIN RECAUDACION: ");
    for(i=0;i<CAMIONES;i++)
    {
        for(j=0;j<MESES;j++)
        {
            if(importe[i][j]==0)
            {
                contador++;
            }
        }

        if(contador>4)
        {
            printf("%d ",i+1);
        }

        contador=0;
    }

    for(i=0;i<CAMIONES;i++)
    {
        for(j=0;j<MESES;j++)
        {
            totalxCamionKms[i] += kilometros[i][j];
        }
    }

    for(i=0;i<CAMIONES;i++)
    {
        if (sen==0)
        {
            minkms=totalxCamionKms[i];
            mincamion=i;
            sen=1;
        }
        else
        {
            if(minkms<totalxCamionKms[i]) //es maximo, no minimo
                        {
            minkms=totalxCamionKms[i];
            mincamion=i;
            sen=1;
        }
        }
    }

    printf("\nCAMION CON MAS KILOMETROS: %d CON UN TOTAL DE %.2f",mincamion+1,minkms);

    for(i=75;i<CAMIONES;i++)
    {
        for(j=0;j<MESES;j++)
        {
            sumaEspecial += importe[i][j];
        }
    }

    printf("\nTOTAL RECAUDADO POR CAMIONES ESPECIALES: %.2f",sumaEspecial);

    printf("\nCAMION 13 DE MENOR A MAYOR");

        for(j=0;j<MESES;j++)
        {
            vector13[j] += importe[12][j];
        }

    ordenar(vector13);

    getch();
    return 0;
}

int validar (int li,int ls)
{
    int dato;

    do
    {
        scanf("%i",&dato);
    }
    while(dato<li || dato>ls);

    return(dato);
}

void ordenar(float vec[])
{
    int i=0,j=0;
    float aux;

    for(i=0;i<MESES;i++)
    {
        if(vec[i]!=0)
        {
            printf("\n");
            printf("%.2f",vec[i]);
        }
    }
return;
}
