#include <stdio.h>
#include <conio.h>
#include <string.h>
#define ALUMNOS 5

struct alumnos
{
    int documento;
    char apellido[20];
    char nombre[20];
    char calle[20];
    int nro;
    char localidad[20];
    char provincia[20];
};

int main()
{
    struct alumnos db[ALUMNOS];
    struct alumnos aux;

    int i=0,j=0,pos=-1;
    char apellido[20];
    char opcion;
    struct alumnos auxalum;

    printf("\nOpcion ""a"": carga la base de datos");
    printf("\nOpcion ""b"": ordena por apellido");
    printf("\nOpcion ""c"": ordena por dni");
    printf("\nOpcion ""d"": busca un apellido");
    printf("\nOpcion ""e"": finaliza el programa");
    printf("\nIngrese caracter: ");
    fflush(stdin);
    opcion = getchar();

    system("cls");
    while(opcion != 'e')
    {
        switch(opcion)
        {
        case 'a':
                system("cls");
            for(i=0;i<ALUMNOS;i++)
            {
            printf("\nIngrese nro. de documento: ");
            scanf("%i",&db[i].documento);

            fflush(stdin);
            printf("\nIngrese apellido: ");
            gets(db[i].apellido);

            fflush(stdin);
            printf("\nIngrese nombre: ");
            gets(db[i].nombre);

            fflush(stdin);
            printf("\nIngrese nombre de calle: ");
            gets(db[i].calle);


            printf("\nIngrese nro. de calle: ");
            scanf("%i",&db[i].nro);

            fflush(stdin);
            printf("\nIngrese nombre de localidad: ");
            gets(db[i].localidad);

            fflush(stdin);
            printf("\nIngrese nombre de provincia: ");
            gets(db[i].provincia);

            }
            break;

        case 'b':
            system("cls");
            for(i=0;i<ALUMNOS;i++)
            {
                for(j=0;j<ALUMNOS-1;j++)
                {
                    if (strcmp(db[j].apellido,db[j+1].apellido) == 0)
                    {
                        if(strcmp(db[j].nombre,db[j+1].nombre) > 0)
                        {
                        aux = db[j];
                        db[j] = db[j+1];
                        db[j+1] = aux;
                        }
                    }
                    else
                    {
                        if(strcmp(db[j].apellido,db[j+1].apellido) > 0)
                        {
                            aux = db[j];
                            db[j] = db[j+1];
                            db[j+1] = aux;
                        }
                    }
                }
            }
            for(i=0;i<ALUMNOS;i++)
            {
                printf("\nNro. de documento: ");
            printf("%i",db[i].documento);

            fflush(stdin);
            printf("\nApellido: ");
            puts(db[i].apellido);

            fflush(stdin);
            printf("\nNombre: ");
            puts(db[i].nombre);

            fflush(stdin);
            printf("\nNombre de calle: ");
            puts(db[i].calle);


            printf("\nNro. de calle: ");
            printf("%i",db[i].nro);

            fflush(stdin);
            printf("\nNombre de localidad: ");
            puts(db[i].localidad);

            fflush(stdin);
            printf("\nNombre de provincia: ");
            puts(db[i].provincia);
            }
        break;

        case 'c':
            system("cls");
            for(i=0;i<ALUMNOS;i++)
                {
                for(j=0;j<ALUMNOS-1;j++)
                    {
                        if (db[j].documento > db[j+1].documento)
                        {
                        auxalum = db[j];
                        db[j] = db[j+1];
                        db[j+1] = auxalum;
                        }
                    }
                }
            for(i=0;i<ALUMNOS;i++)
            {
                printf("\nNro. de documento: ");
            printf("%i",db[i].documento);

            fflush(stdin);
            printf("\nApellido: ");
            puts(db[i].apellido);

            fflush(stdin);
            printf("\nNombre: ");
            puts(db[i].nombre);

            fflush(stdin);
            printf("\nNombre de calle: ");
            puts(db[i].calle);


            printf("\nNro. de calle: ");
            printf("%i",db[i].nro);

            fflush(stdin);
            printf("\nNombre de localidad: ");
            puts(db[i].localidad);

            fflush(stdin);
            printf("\nNombre de provincia: ");
            puts(db[i].provincia);
            }
            break;

        case 'd':
            system("cls");
            printf("\nIngrese apellido a buscar:");
            fflush(stdin);
            gets(apellido);

            for(i=0;i<ALUMNOS;i++)
            {
                if(strcmp(apellido,db[i].apellido)==0)
                    pos=i;
            }

            if(pos>=0)
                printf("\nEncontrado en la posicion %d",pos+1);
            else
                printf("\nApellido no encontrado");
            break;

        case 'e':
            system("cls");
            return(0);

        default:
            printf("\nError");
            break;
        }
        printf("\nIngrese caracter: ");
        fflush(stdin);
        opcion = getchar();
    }
}
