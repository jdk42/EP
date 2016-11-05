#include <stdio.h>
#include <conio.h>
#define TOURS 23

void ingreso(float [],float[]);
void imprimir(float [],float[][3]);
void buscarmayor(float [],float[][3]);
float validar(float,float);
int buscar(float []);

int main()
{
    int i=0,j=0,cliente=0,cantidad,vendedor,codigo,ntour;
    float posicion[TOURS],precio[TOURS],basedatos[TOURS][3];

    //Inicializo los vectores y la matriz
    for (i=0;i<TOURS;i++)
    {
        posicion[i]=0;
        precio[i]=0;
    }

    for (i=0;i<TOURS;i++)
    {
        for (j=0;j<3;j++)
        {
            basedatos[i][j]=0;
        }
    }

    //Cargo el vector que contiene a los tours
    ingreso(posicion,precio);

    //Comienzo a cargar la base de datos
    printf("\nInserte numero de cliente: ");
    cliente = validar(0,1000);

    while(cliente != 0)
    {
        printf("\nInserte vendedor: ");
        vendedor = validar(1,20);

        //Utiliza la funcion buscar para verificar que existe el numero de tour
        ntour = buscar(posicion);

        if (ntour>-1) //El dato que devuelve la funcion sera mayor a -1 si el tour existe
        {
             printf("\nInserte cantidad: ");
        do
        {
            scanf("%d",&cantidad);
        }
        while(cantidad < 0);
        }
        else //Si no lo encontro
        {
            printf("\nCodigo erroneo");
        }

        basedatos[ntour][2] += cantidad; // Guarda la cantidad vendida en la columna 2

        printf("\nInserte numero de cliente: ");
        cliente = validar(0,1000);
    }

    imprimir(posicion,basedatos);
    buscarmayor(posicion,basedatos);

    getch();
    return 0;
}

float validar(float li,float ls) //Funcion clasica de validar
{
   float dato;

    do
    {
        scanf("%f",&dato);
    }
    while(dato < li || dato > ls);

    return (dato);
}

void ingreso(float vecA[],float vecB[]) // Guarda en el vector posicion / precio los distintos tours (Punto a)
{
    int i=0;
    float tour=0;
    float precio=0;

    for(i=0;i<TOURS;i++)
    {
        printf("\nInserte tour: ");
        tour = validar(11111,99999);
        vecA[i]=tour;
        printf("\nInserte precio: ");
        do
        {
                scanf("%f",&precio);
        }
        while(precio < 0);
        vecB[i] = precio;
    }

    return;
}

int buscar(float vector[])
{
    int ban=-1,cont=0,i=0,j=0;
    float tour=0,resultado=0;



        printf("\nInserte tour: ");
        scanf("%f",&tour);

       // printf("%f",tour);


        while(ban==-1 && cont < TOURS) // Mientras que ban sea -1 y el acumulador sea menor a la cantidad de tours, se ejecutara
        {
            if (tour == vector[cont])
            {
                ban = cont; // en caso de ser correcto, devolvera un numero mayor a cero
            }
            else
                cont++;
        }


    return(ban);
}

void imprimir(float veca[],float vecb[][3]) //Ingresa un vector con 3 columnas
{
    int i=0;
    printf("\n\tTOUR\t\tCANTIDAD");

    for(i=0;i<TOURS;i++)
    {
    printf("\n");
    printf("\t%.0f\t\t%.0f",veca[i],vecb[i][2]); //Lee la columna 2 (acordarse que empieza a contar desde cero)

    }

    return;
}

void buscarmayor(float veca[],float vecb[][3]) //Funcion clasica de buscar al mayor
{
    int i=0,sen=0;
    float maximonumero,maximocantidad;
    printf("\n\tMAXIMO");
    printf("\n\tNUMERO DE TOUR\t\tCANTIDAD");
    for(i=0;i<TOURS;i++)
    {
        if (sen==0)
        {
            maximonumero = veca[i];
            maximocantidad = vecb[i][2];
            sen = 1;
        }
        else
        {
            if (maximocantidad < vecb[i][2])
            {
            maximonumero = veca[i];
            maximocantidad = vecb[i][2];
            }
        }

    }

    printf("\n\t%.0f\t\t%.0f",maximonumero,maximocantidad);

    return;
}
