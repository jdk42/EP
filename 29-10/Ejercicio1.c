#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct ventacompra
{
    int dia;
    int movimiento;
    int codConcepto;
    float importe;
};

struct codigo
{
    int codConcepto;
    char descripcion[30];
    int imputacionContable;
};

int main()
{
    int i=0,contadorVC,contadorCOD,acumuladorPOS=0,acumuladorNEG=0,total;

    FILE *VentasCompras;
    FILE *Codigos;

    struct ventacompra vecVC[31]; // Solo 31 ventas y compras
    struct codigo vecCOD[999];

    if(((VentasCompras=fopen("ventascompras.dat","rb"))== NULL) && ((Codigos=fopen("codigos.dat","rb"))== NULL))
    {
        printf("Error al abrir los archivos");
        exit(0);
    }

    fread(&vecVC[i],sizeof(struct ventacompra),1,VentasCompras);
    while(!feof(VentasCompras))
    {
        i++;
        fread(&vecVC[i],sizeof(struct ventacompra),1,VentasCompras);
    }

    contadorVC = i;

    i=0;

    fread(&vecCOD[i],sizeof(struct codigo),1,Codigos);
    while(!feof(Codigos))
    {
        i++;
        fread(&vecCOD[i],sizeof(struct codigo),1,Codigos);
    }

    contadorCOD = i;

    fclose(Codigos);
    fclose(VentasCompras);

    for(i=0;i<contadorVC;i++)
    {
    printf("\n Dia: %i",vecVC[i].dia);
    printf("\nTipo de movimiento: %i",vecVC[i].movimiento);
    fflush(stdin);
    printf("\nDescripcion: ");
    puts(vecCOD[i].descripcion);
    printf("\nImputacion contable: %i",vecCOD[i].imputacionContable);
    }


    for(i=0;i<contadorVC;i++)
    {
     if (vecVC[i].movimiento == 1)
     {
         acumuladorPOS += vecVC[i].movimiento;
     }
    else if (vecVC[i].movimiento == 2)
     {
         acumuladorNEG += vecVC[i].movimiento;
     }

     total = acumuladorPOS - acumuladorNEG;
     printf("\n----DIA %i----",i);
     printf("\nTotal de cobros: %i",acumuladorPOS);
     printf("\nTotal de pagos: %i",acumuladorNEG);
    printf("\nSaldo del dia %i: %i",total);

    acumuladorPOS=0;
    acumuladorNEG=0;
    total=0;
     }


}
