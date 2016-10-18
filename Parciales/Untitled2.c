#include <stdio.h>
#include <conio.h>
#define GRANJEROS 5

int valida(int,int);
void fechahoy();
void langostas(int []);

int main()
{
    float precios[4]={18,20,22,30},descuento,matriz[GRANJEROS][3]={{0}},importe,meses[GRANJEROS],maximporte,acumGusanos[12]={0},porcentaje,sumadorgranjeros[GRANJEROS]={0};
    int granjero,fumigacion,metros,mes,tipofumigacion[4]={0},mespedido,sumador=0,i=0,j=0,sen=0,maxgranjero;

    //fechahoy();

    printf("\nIngrese numero de granjero: ");
    granjero = valida(0,50);

    while(granjero!=0)
    {
        printf("\nIndique tipo de fumigacion: ");
        fumigacion = valida(1,4);

        printf("\nIngrese cantidad de metros cuadrados a fumigar: ");
        do
        {
            scanf("%i",&metros);
        }
        while(metros<0);

        printf("\nIngrese el mes: ");
        mes = valida(1,12);


        meses[granjero-1]++; // Punto b

        tipofumigacion[fumigacion-1]++; //Punto c

        if (metros>10000)
        {
            importe = (float)(precios[fumigacion] * metros);
            descuento = 0.7*importe;
            importe = importe-descuento;

        }
        else
        {
        importe = (float)(precios[fumigacion] * metros);
        }

        matriz[granjero-1][mes-1] += importe;

        if (fumigacion == 3) // Punto d
        {
            acumGusanos[mes-1] += importe;
        }

        matriz[granjero-1][mes-1] += importe; // Punto a

        printf("\nIngrese numero de granjero: ");
        granjero = valida(0,50);
    }

    printf("\nIngrese mes que desea ver: ");
    mespedido = valida(1,12);

    printf("\nNUMERO GRANJERO\t\tIMPORTE");
    for(i=0;i<GRANJEROS;i++)
    {
        printf("\n%d\t\t%.2f",i+1,matriz[i][mespedido-1]);
    }

    printf("\nGranjeros que fumigaron mas de 3 meses: ");
    for(i=0;i<GRANJEROS;i++)
    {
        if(meses[i]>3)
            printf("%d",i+1);
    }

    langostas(tipofumigacion);

    printf("\nFumigaciones contra gusanos");
    printf("\nMES  IMPORTE");
    for(i=0;i<12;i++)
    {
        printf("\n%d  %.2f",i+1,acumGusanos[i]);
    }

    for(i=0;i<GRANJEROS;i++)
    {
        for(j=0;j<12;j++)
        {
            sumadorgranjeros[i] += matriz[i][j];
        }
    }

    for (i=0;i<GRANJEROS;i++)
    {
            if ( sen == 0)
        {
            maxgranjero = i;
            sen = 1;
            maximporte = sumadorgranjeros[i];
        }
        else
        {
            if (maximporte < sumadorgranjeros[i])
            {
                       maxgranjero = i;
            maximporte = sumadorgranjeros[i];
            }
        }
    }

    printf("\n");

    printf("Granjero que mas facturo: %i con un total de %.2f",maxgranjero+1,maximporte);

    getch();
    return(0);
}
int valida(int li,int ls)
{
    int dato;

    do
    {
        scanf("%i",&dato);
    }
    while(dato<li||dato>ls);

    return(dato);
}

void fechahoy()
{

    int mes,dia;

    printf("\nIngrese mes: ");
    mes = valida(1,12);

    if (mes==4||mes==6||mes==9||mes==11)
    {
    printf("\nIngrese dia: ");
    dia = valida(1,30);
    }
    else if(mes==2)
        {
                printf("\nIngrese dia: ");
    dia = valida(1,28);
        }
    else
    {
    printf("\nIngrese dia: ");
    dia = valida(1,31);
    }

    printf("\nDIA: %d MES: %d",dia,mes);
}

void langostas(int vec[])
{

    int sumador=0,i=0;
    float porcentaje=0;

    for(i=0;i<4;i++)
    {
        sumador += vec[i];
    }

    porcentaje = (float)((vec[1]*100)/sumador);

    printf("\nEl porcentaje total de fumigacion contra langostas es %.2f",porcentaje);

    return;
}
