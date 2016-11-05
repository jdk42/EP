#include <conio.h>
#include <stdio.h>
#define FILAS 5
#define COLUMNAS 5

void inicializar(float vec[][COLUMNAS]);
void llenar(float vec[][COLUMNAS]);
void imprimir(float vec[][COLUMNAS]);
void sumadiagprincipal(float vec[][COLUMNAS]);
void promedios(float vec[][COLUMNAS]);
void mayor(float vec[][COLUMNAS]);
void menor(float vec[][COLUMNAS]);

int main()
{
    float matriz[FILAS][COLUMNAS];

    inicializar(matriz);
    llenar(matriz);
    imprimir(matriz);
    sumadiagprincipal(matriz);
    promedios(matriz);
    mayor(matriz);
    menor(matriz);

    getch();
    return 0;
}

void inicializar(float vec[][COLUMNAS])
{
    int i,j,numero;
    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
                vec[i][j]=0;
    }
    return;
}

void llenar(float vec[][COLUMNAS])
{
    int i=0,j=0,numero,numj,numi;

    printf("Inserte i: ");
    scanf("%i",&numi);
    printf("Inserte j: ");
    scanf("%i",&numj);

    while ((numi-1>=0 && numi-1 < FILAS ) || (numj-1>=0 && numj-1 < COLUMNAS))
    {
                printf("\nInserte un numero: ");
                scanf("%i",&numero);
                vec[numi-1][numj-1] = numero;

                printf("Inserte i: ");
                scanf("%i",&numi);
                printf("Inserte j: ");
                scanf("%i",&numj);
    }
    return;
}

void imprimir(float vec[][COLUMNAS])
{
    int i,j;

    printf("\n");
    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
               printf("%.0f ",vec[i][j]);
        printf("\n");
    }
    return;
}

void sumadiagprincipal(float vec[][COLUMNAS])
{
    int i,j,sumador=0;
    for(i=1;i<=FILAS;i++)
    {
        for(j=1;j<=COLUMNAS;j++)
        {
            if (i=j)
                sumador+= vec[i-1][j-1];
        }
    }

    printf("\nLa suma de la diagonal principal es igual a %d",sumador);
    return;
}

void promedios(float vec[][COLUMNAS])
{
    int i,j,sumador=0,promediador=0;
    float promedios;


    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if (vec[i][j] != 0)
            {
                promediador++;
            }
        }
    }



    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
              {
                    sumador+= vec[i][j];
              }
    }


    promedios = (float)(sumador/promediador);

    printf("\nPromedio total de la matriz es %.2f",promedios);

    return;
}

void mayor(float vec[][COLUMNAS])
{
    int i=0,j=0,sen=0,max_fila=0,max_columna=0,max_num=0;

    for(i=0;i<FILAS;i++)
    {
            for(j=0;j<COLUMNAS;j++)
        {
            if (sen==0)
            {
                    max_fila = i;
                    max_columna = j;
                    max_num = vec[i][j];
                sen = 2;
            }
            else
            {
                if (max_num < vec[i][j])
                {
                    max_fila = i;
                    max_columna = j;
                    max_num = vec[i][j];
                }
            }
        }
    }

    printf("\nEl mayor numero es %d,situado en la fila %d y columna %d",max_num,max_fila+1,max_columna+1);
    return;
}

void menor(float vec[][COLUMNAS])
{
    int i=0,j=0,sen=0,min_fila=0,min_columna=0,min_num=0;

    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if (vec[i][j] != 0)
            {
                if (sen==0)
                {
                        min_fila = i;
                        min_columna = j;
                        min_num = vec[i][j];
                    sen = 2;
                }
                else
                {
                    if (min_num > vec[i][j])
                    {
                        min_fila = i;
                        min_columna = j;
                        min_num = vec[i][j];
                    }
                }
            }
        }
    }

    printf("\nEl menor numero es %d,situado en la fila %d y columna %d",min_num,min_fila+1,min_columna+1);
    return;
}
