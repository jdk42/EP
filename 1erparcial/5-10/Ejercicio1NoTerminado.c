#include <conio.h>
#include <stdio.h>
#define SUCURSALES 20
#define RUBROS 20

void cambio(float vec[]);
void cambioarray2d(float vec[][RUBROS]);
void promedios_(float vec[][RUBROS]);

int main()
{
    int i=0,j=0,sucursales,rubros,cantidad,sen=0,max_codigorubro,max_unidades,k=15;
    float matriz[SUCURSALES][RUBROS],maximasucursales[SUCURSALES],cantxsucursal[SUCURSALES];

    cambioarray2d(matriz);
    cambio(cantxsucursal);

    do
    {
        printf("Inserte cod. de sucursal: ");
        scanf("%i",&sucursales);
    }
    while(sucursales<0 || sucursales > 15);

    while (sucursales != 0)
    {
    do
    {
        printf("Inserte rubro: ");
        scanf("%i",&rubros);
    }
    while(rubros<0 || rubros > 40);

    do
    {
        printf("Inserte cantidad: ");
        scanf("%i",&cantidad);
    }
    while(cantidad<0 || cantidad > 20);

    matriz[sucursales-1][rubros-1] += cantidad;


    do
    {
        printf("Inserte cod. de sucursal: ");
        scanf("%i",&sucursales);
    }
    while(sucursales<0 || sucursales > 40);

    }

 /* for(i=0;i<SUCURSALES;i++)
    {
        for(j=0;j<RUBROS;j++)
        {
            printf("%.0f ",matriz[i][j]);

        }
        printf("\n");
    }*/

        printf("\n");


  for(i=0;i<SUCURSALES;i++)
    {
        for(j=0;j<RUBROS;j++)
        {
            cantxsucursal[i] += matriz[i][j];

        }
    }

    for(i=0;i<SUCURSALES;i++)
    {
            printf("\nSucursal numero: %i \t Pedidos: %.0f",i+1,cantxsucursal[i]);
    }

    promedios_(matriz);


   // Pasajes sin ventas
       for(j=0;j<RUBROS;j++)
        {
            if (sen==0)
            {
                max_codigorubro = j;
                max_unidades = matriz[14][j];
                sen = 2;
            }
            else
            {
                if (max_unidades < matriz[14][j])
                {
                    max_codigorubro = j;
                    max_unidades = matriz[14][j];
                }
            }
        }

    if (max_unidades != 0)
            printf("\nEl rubro con mayor cantidad en la sucursal 15 fue el nro. %d",max_codigorubro+1);
    else
        printf("\nNo hay productos en la sucursal 15");



return(0);
getch();
}


void cambio(float vec[])
{
    int i;
    for(i=0;i<RUBROS;i++)
    vec[i]=0;
    return;
}

void cambioarray2d(float vec[][RUBROS])
{
    int i,j;
    for(i=0;i<SUCURSALES;i++)
    {
        for(j=0;j<RUBROS;j++)
                vec[i][j]=0;
    }
    return;
}

void promedios_(float vec[][RUBROS])
{
   int i,j,min_codigorubro,min_unidades,senx=0;
    float minimorubros[RUBROS];

    cambio(minimorubros);

    for(i=0;i<SUCURSALES;i++)
    {
        for(j=0;j<RUBROS;j++)
        {
            minimorubros[j] += vec[i][j];

        }
    }
    printf("\n");
        for(j=0;j<RUBROS;j++)
        {
            printf("%.0f ",minimorubros[j]);

        }
    printf("\n");

    for(j=0;j<RUBROS;j++)
        {
            if (senx==0)
            {
                min_codigorubro = j;
                min_unidades = minimorubros[j];
                senx = 2;
            }
            else
            {
                if (min_unidades > minimorubros[j])
                {
                    min_codigorubro = j;
                    min_unidades = minimorubros[j];
                }
            }
        }


        printf("\nEl rubro que menos unidades requirio fue %i",min_codigorubro);

    /* for(i=0;i<RUBROS;i++)
    {
        if (minimorubros[i]==min_unidades)
        {
            printf("La menor cantidad fue %d",min_unidades);
        }

            }*/
    return;
}
