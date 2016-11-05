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

	/*if(((archivo1=fopen("archivo1.dat","wb"))== NULL) && ((archivo2=fopen("archivo2","wb"))== NULL) && ((archivo3=fopen("archivo3","wb"))== NULL))
    {
        printf("\nError al crear los archivos");
        exit(0);
    }*/ //Comprueba que este vacio para no cagarla

    fwrite(&arch1[i],sizeof(struct archivo1),1,archivo1);
    
    for(i=0;i<ARTICULOS;i++)
    {
    	printf("\nInserte el año: ");
    	scanf("%i",arch1[i].fecha.anio);
    	
    	printf("\nInserte el mes: ");
    	do
    	{
    		scanf("%i",arch1[i].fecha.mes);
    	}
    	while ( arch1[i].fecha.mes < 0 || arch1[i].fecha.anio > 12 );
    	
    	printf("\nInserte el dia: ");
    	
    	if(arch1[i].fecha.mes == )
    	if ((arch1[i].fecha.anio % 4 == 0) && ((arch1[i].fecha.anio % 100 != 0) || (arch1[i].fecha.anio % 400 == 0) ))
    	{


    	}
    }
    /*
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
*/
	fclose(archivo1);
	fclose(archivo2);
	fclose(archivo3);

	getch();
	return(0);
}


