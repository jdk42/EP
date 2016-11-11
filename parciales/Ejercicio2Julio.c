#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define SECCION 15
#define DIA 31

struct arch1{
    int dia;
    long int tarjeta;
    int legajo;
    int horas;
};

struct arch2{
    int codempleado;
    char apellido[20];
    char nombre[20];
    char direccion[20];
    int seccion;
    int categoria;
};

struct arch3{
    int codseccion;
    char desc_seccion[30];
};

struct arch4{
    int codcategoria;
    char desc_cat[30];
    float importehora;
};

int buscararchi2(int,struct arch2 bla[],int);
int buscararchi3(int,struct arch3 asd[],int);
int buscararchi4(int);

int main(){

    int i=0,j=0,pos,temp,temp1,pos1,temp2,sumadorgeneral=0,tlegajo=0,legajo_a,totalarchi1,totalarchi2,totalarchi3,totalarchi4;
    int mtlistado[SECCION][DIA]={{0}},codcategoria[200]={0},canthoras[200]={0};
    float sueldos[200]={0},imptarch4,importe;
    char mtdesc[15][30];

    FILE *archivo1,*archivo2,*archivo3;
    struct arch1 archi1;
    struct arch2 archi2[200];
    struct arch3 archi3[15];

    //Imprime listado inicial
	if(((archivo1=fopen("archivo1.dat","rb"))== NULL) && ((archivo2=fopen("archivo2","rb"))== NULL) && ((archivo3=fopen("archivo3","rb"))== NULL))
    {
        printf("\nError al abrir los archivos");
        exit(0);
    }


    fread(&archi2[i],sizeof(struct arch2),1,archivo2);

    while(!feof(archivo2))
    {
        i++;
        fread(&archi2[i],sizeof(struct arch1),1,archivo2);
    }

    totalarchi2 = i;
    i = 0;

    fread(&archi3[i],sizeof(struct arch2),1,archivo3);

    while(!feof(archivo3))
    {
        i++;
        fread(&archi3[i],sizeof(struct arch1),1,archivo3);
    }

    totalarchi3 = i;
    i=0;

    fread(&archi1,sizeof(struct arch1),1,archivo1);

    while(!feof(archivo1))
    {
        printf("\nDia: %i",archi1.dia);
        printf("\nNumero de tarjeta: %li",archi1.tarjeta);
        printf("\nLegajo: %i",archi1.legajo);
        temp = archi1.legajo;
        pos = buscararchi2(temp,archi2,200);
        fflush(stdin);
        printf("\nApellido: ");
        puts(archi2[pos].apellido);
        printf("\nNombre: ");
        fflush(stdin);
        puts(archi2[pos].nombre);
        printf("\nCodigo de seccion: %i",archi2[pos].seccion);
        temp1 = archi2[pos].seccion;
        pos1 = buscararchi3(temp1,archi3,15);
        fflush(stdin);
        puts(archi3[pos].desc_seccion);
        printf("\nCategoria: %i",archi2[pos].categoria);
        temp2 = archi2[pos].categoria;
        totalarchi4 = buscararchi4(temp2);
        printf("\nHoras trabajadas: %i",archi1.horas);

        mtlistado[temp1][archi1.dia] += archi1.horas; // Matriz

        //

        //Vectores


        codcategoria[pos]=temp2;
        //mtdesc[]=strcpy() vector denominacion
        canthoras[pos]+=archi1.horas;
        fread(&archi1,sizeof(struct arch1),1,archivo1);
    }

    //Corte de control (horas por legajo,total horas)

    while(!feof(archivo1))
    {
        tlegajo = 0;
        legajo_a=archi1.legajo;
        while(legajo_a=archi1.legajo)
        {
                tlegajo += archi1.horas;
                sumadorgeneral += archi1.horas;
        }
        printf("\nLegajo nro. %i - Horas totales: %i",legajo_a,tlegajo);

    }
    printf("\nTotal de horas trabajadas: %i",sumadorgeneral);

    //Listado por vectores

    for(i=0;i<200;i++)
    {
        printf("\nNombre: ");
        pos = buscararchi2(i,archi2,200);
        puts(archi2[pos].nombre);
        printf("\nCodigo de categoria: %d",codcategoria[i]);
        printf("\nDescripcion: ");
        imptarch4 = buscararchi4(codcategoria[i]);
        printf("\nCantidad de horas realizadas: %i",canthoras[i]);
        printf("Importe a pagar: %.2f",canthoras[i]*imptarch4);
    }

    //Imprimir matriz

    for(i=0;i<totalarchi3;i++)
    {
        printf("\nSeccion %i",i+1);
        for(j=0;j<DIA;j++)
        {
            printf("\nDia %i,horas trabajadas: %i",j+1,mtlistado[i][j]);
        }
    }

    // Ultimos vectores

    for(i=0;i<200;i++)
    {
        printf("Codigo de categoria: %i",codcategoria[i]);
        imptarch4 = buscararchi4(codcategoria[i]);
        printf("\nCantidad de horas realizadas: %i",canthoras[i]);
        if(canthoras[i]>6)
        {
            importe = (canthoras[i]-6)*imptarch4*1.5;
            importe += 6*imptarch4;
        }
        else
        {
            importe = canthoras[i]*imptarch4;
        }
        printf("\nImporte total a pagar: %.2f",importe);

    }

fclose(archivo1);
fclose(archivo2);
fclose(archivo3);

getch();
return(0);
}

int buscararchi2(int cod,struct arch2 archi2[],int cant)
{
        int pos=-1,i=0;

            while(pos==-1&&i<cant)
            {
                if(cod==archi2[i].codempleado)
                {
                    pos = i;
                }
                else
                {
                    i++;
                }
            }

            return (pos);
}

int buscararchi3(int cod,struct arch3 archi3[],int cant)
{
        int pos=-1,i=0;

            while(pos==-1&&i<cant)
            {
                if(cod==archi3[i].codseccion)
                {
                    pos = i;
                }
                else
                {
                    i++;
                }
            }

            return (pos);
}

int buscararchi4(int cod)
{
    FILE *archivo4;
    struct arch4 archi4;

    int sen=0,i=0;
    float impt;

    archivo4 = fopen("archivo4.dat","rb");
    fread(&archi4,sizeof(struct arch4),1,archivo4);


    while(!(feof(archivo4))||!(sen==1))
    {
           if(cod==archi4.codcategoria)
           {
               fflush(stdin);
               puts(archi4.desc_cat);
               impt = archi4.importehora;
               sen = 1;
           }
            fread(&archi4,sizeof(struct arch4),1,archivo4);

    }

    fclose(archivo4);

    return impt;
}
