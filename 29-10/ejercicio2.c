#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ARTICULOS 20

struct fecha
{
	int anio;
	int mes;
	int dia;
};

struct archivo1
{
	struct fecha fecha;
	int tipo;
	int nocomprobante;
	int codcliente;
	int codarticulo;
	int cantidad;
	float precio;
};

struct archivo2
{
	int codigo;
	char denominacion[30];
	char callenumero[50];
	char localidad[30];
	char provincia[30];
	int condiva;
	int cuit[13];
};

struct archivo3
{
	int codarticulo;
	char descripcion[30];
	int ubicacion;
	int entradas;
	int salidas;
};

int main()
{
	int i=0,contarch1,contarch2,contarch3,acumuladorventas=0,clientventas[100]={0},itemventas[150]={0},diaventas[31]={0};
	float acumimpt=0,importe,clientimpt[100]={0},itemimpt[150]={0},diaimpt[31]={0};

	FILE *archivo1;
	FILE *archivo2;
	FILE *archivo3;

	struct archivo1 arch1[ARTICULOS];
	struct archivo2 arch2[100];
	struct archivo3 arch3[150];

	if(((archivo1=fopen("archivo1.dat","rb"))== NULL) && ((archivo2=fopen("archivo2","rb"))== NULL) && ((archivo3=fopen("archivo3","rb"))== NULL))
    {
        printf("\nError al abrir los archivos");
        exit(0);
    }

    fread(&arch1[i],sizeof(struct archivo1),1,archivo1);
    while(!feof(archivo1))
    {
        i++;
        fread(&arch1[i],sizeof(struct archivo1),1,archivo1);
    }

    contarch1 = i;

    i=0;

    fread(&arch2[i],sizeof(struct archivo2),1,archivo2);
    while(!feof(archivo1))
    {
        i++;
        fread(&arch2[i],sizeof(struct archivo2),1,archivo2);
    }

    contarch2 = i;

    i=0;

    fread(&arch3[i],sizeof(struct archivo3),1,archivo3);
    while(!feof(archivo3))
    {
        i++;
        fread(&arch3[i],sizeof(struct archivo3),1,archivo3);
    }

    contarch3 = i;

    i=0;

	fclose(archivo1);
	fclose(archivo2);
	fclose(archivo3);

	i=0;

	while (i < ARTICULOS) // PUNTO 4
    {
        printf("\nFecha: %i // %i // %i ",arch1[i].fecha.dia,arch1[i].fecha.mes,arch1[i].fecha.anio);
        printf("\nCodigo de articulo: %i",arch3[i].codarticulo);
        printf("\nDescripcion: ");
        fflush(stdin);
        puts(arch3[i].descripcion);
        printf("\nCodigo de cliente: %i",arch2[i].codigo);
        printf("\nDenominacion: ");
        fflush(stdin);
        puts(arch2[i].denominacion);
        printf("\nCantidad: %i",arch1[i].cantidad);
        printf("\nPrecio: %.2f",arch1[i].precio);
        importe = (float)(arch1[i].cantidad)*(float)(arch1[i].precio);
        printf("\nImporte: %i",importe);

        //Punto 5
        acumimpt += importe;
        acumuladorventas += arch1[i].cantidad;

        //Punto 6
        clientventas[i] += arch1[i].cantidad;
        clientimpt[i] += importe;

        //Punto 7

        itemventas[arch3[i].codarticulo] += arch1[i].cantidad;
        itemimpt[arch3[i].codarticulo] += importe;

        //Punto 8

        itemventas[arch1[i].fecha.dia] += arch1[i].cantidad;
        itemimpt[arch1[i].fecha.dia] += importe;


        i++;
    }

    printf("\nCantidad total vendida: %i",acumuladorventas);
    printf("\nTotal de los importes: %.2f",acumimpt);

    //Punto 6: totalizar ventas por cliente

    for(i=0;i<100;i++)
    {
        printf("\nCliente %i",i+1);
        fflush(stdin);
        puts(arch2[i].denominacion);
        printf("\nTotal cantidad de ventas: %i",clientventas[i]);
        printf("\nTotal importe de ventas: %.2f",clientimpt[i]);
    }

    //Punto 7: totalizar ventas por articulo

     for(i=0;i<150;i++)
    {
        printf("\nArticulo: %i",i+1);
        fflush(stdin);
        puts(arch3[i].descripcion);
        printf("\nTotal cantidad de ventas: %i",itemventas[i]);
        printf("\nTotal importe de ventas: %.2f",itemimpt[i]);
    }

        //Punto 8: totalizar ventas por dia

    for(i=0;i<31;i++)
    {
        printf("\nDia: %i",i+1);
        printf("\nTotal cantidad de ventas: %i",diaventas[i]);
        printf("\nTotal importe de ventas: %.2f",diaimpt[i]);
    }

	getch();
	return(0);
}
