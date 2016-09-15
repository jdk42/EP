#include <stdio.h>
#include <conio.h>
#define ObraSocial  0.04
#define Jubilacion  0.11

void main()
{

    int numero_DeLegajo;
    int contador=0;
    int maximapaga_numero_DeLegajo;
    int maximohoras_numero_DeLegajo;
    int minimohoras_numero_DeLegajo;

    int cantidad_Horas,cantidad_HorasNormales,cantidad_HorasExtras;
    int total_cantidad_HorasNormales=0,total_cantidad_HorasExtras=0,total_cantidad_Horas=0;
    int maximapaga_total_cantidad_Horas;
    int maximohoras_total_cantidad_Horas=0;
    int minimohoras_total_cantidad_Horas;

    int jornal,jornal_HorasNormales,jornal_HorasExtras;
    int maximapaga_jornal;
    int maximohoras_jornal;
    int minimohoras_jornal;

    float importe_HorasNormales,importe_HorasExtras,importe_HorasTotal;
    float total_importe_HorasNormales,total_importe_HorasExtras,total_importe_HorasTotal=0;
    float maximapaga_importe_Horas_Total=0;
    float maximohoras_importe_Horas_Total;
    float minimohoras_importe_Horas_Total;

    float importe_neto;
    float total_importe_neto=0;
    float maximapaga_importeneto;
    float maximohoras_importeneto;
    float minimohoras_importeneto;
    float promedio_importeneto;

    float total_jubilacion=0;
    float total_obrasocial=0;

    float promedio_HorasNormales;
    float promedio_HorasExtras;
    float promedio_importe_HorasTotal;

    do
    {
        do
        {
        printf("\nInserte el numero de legajo: ");
        scanf("%i",&numero_DeLegajo);
        }
        while (numero_DeLegajo < 1 || numero_DeLegajo > 1500 && numero_DeLegajo != 9999);

        if (numero_DeLegajo != 9999)
        {
            do
            {
                printf("\nInserte la cantidad de horas: ");
                scanf("%i",&cantidad_Horas);

                if (cantidad_Horas <= 150)
                {
                    cantidad_HorasNormales = cantidad_Horas;
                    cantidad_HorasExtras = 0;
                    total_cantidad_Horas += cantidad_Horas;
                    total_cantidad_HorasNormales += cantidad_Horas;
                }
                else
                {
                    cantidad_HorasNormales = 150;
                    cantidad_HorasExtras = (cantidad_Horas - 150);
                    total_cantidad_Horas += cantidad_Horas;
                    total_cantidad_HorasNormales += 150;
                    total_cantidad_HorasExtras += cantidad_HorasExtras;
                }
            }
            while (cantidad_Horas < 1 || cantidad_Horas > 300);

            do
            {
                printf("\nInserte el importe del jornal: ");
                scanf("%i",&jornal);
            }
            while (jornal < 1 || jornal > 200);
        }

        else
            continue;

        importe_HorasNormales = jornal * cantidad_HorasNormales;
        total_importe_HorasNormales += importe_HorasNormales;

        importe_HorasExtras = jornal * cantidad_HorasExtras * 1.5;
        total_importe_HorasExtras += importe_HorasExtras;

        importe_HorasTotal = importe_HorasNormales + importe_HorasExtras;
        total_importe_HorasTotal += importe_HorasTotal;

        importe_neto = (importe_HorasTotal-((importe_HorasTotal*Jubilacion)+(importe_HorasTotal*ObraSocial)));
        total_importe_neto += importe_neto;
        total_jubilacion += (importe_HorasTotal*Jubilacion);
        total_obrasocial += (importe_HorasTotal*ObraSocial);

        printf("\nNumero de legajo: %i",numero_DeLegajo);
        printf("\nTotal de horas normales: %i",cantidad_HorasNormales);
        printf("\nTotal de horas extras: %i",cantidad_HorasExtras);
        printf("\nImporte a pagar de horas normales: %.2f",importe_HorasNormales);
        printf("\nImporte a pagar de horas extras: %.2f",importe_HorasExtras);
        printf("\nImporte total a pagar: %.2f",importe_HorasTotal);
        printf("\nImporte neto a pagar: %.2f",importe_neto);
        printf("\n----------------------\n");

        if (importe_HorasTotal > maximapaga_importe_Horas_Total)
        {
            maximapaga_importe_Horas_Total = importe_HorasTotal;
            maximapaga_jornal = jornal;
            maximapaga_numero_DeLegajo = numero_DeLegajo;
            maximapaga_total_cantidad_Horas = cantidad_Horas;
            maximapaga_importeneto = importe_neto;
        }

        if (cantidad_Horas > maximohoras_total_cantidad_Horas)
        {
            maximohoras_importe_Horas_Total = importe_HorasTotal;
            maximohoras_jornal = jornal;
            maximohoras_numero_DeLegajo = numero_DeLegajo;
            maximohoras_total_cantidad_Horas = cantidad_Horas;
            maximohoras_importeneto = importe_neto;
        }

        if (minimohoras_total_cantidad_Horas > cantidad_Horas)
        {
            minimohoras_importe_Horas_Total = importe_HorasTotal;
            minimohoras_jornal = jornal;
            minimohoras_numero_DeLegajo = numero_DeLegajo;
            minimohoras_total_cantidad_Horas = cantidad_Horas;
            minimohoras_importeneto = importe_neto;
        }
        contador++;

    }
    while (numero_DeLegajo != 9999);

    promedio_HorasNormales =(float)(total_cantidad_HorasNormales/contador);
    promedio_HorasExtras =(float)(total_cantidad_HorasExtras/contador);
    promedio_importe_HorasTotal =(float)(total_importe_HorasTotal/contador);
    promedio_importeneto = (float)(total_importe_neto/contador);


    printf("\nTotales generales de todos los obreros: ");
    printf("\n\tTotal de horas normales: %i",total_cantidad_HorasNormales);
    printf("\n\tTotal de horas extras: %i",total_cantidad_HorasExtras);
    printf("\n\tTotal de horas: %i",total_cantidad_Horas);
    printf("\n\tImporte a pagar de horas normales: %.2f",total_importe_HorasNormales);
    printf("\n\tImporte a pagar de horas extras: %.2f",total_importe_HorasExtras);
    printf("\n\tImporte total: %.2f",total_importe_HorasTotal);
    printf("\n\tImporte total de jubilaciones: %.2f",total_jubilacion);
    printf("\n\tImporte total de obra social: %.2f",total_obrasocial);

    printf("\n--------------------\n");

    printf("\nObrero con mayor ganancia: ");
    printf("\n\tNumero de legajo: %i",maximapaga_numero_DeLegajo);
    printf("\n\tTotal de horas: %i",maximapaga_total_cantidad_Horas);
    printf("\n\tJornal por hora: %i",maximapaga_jornal);
    printf("\n\tImporte total: %.2f",maximapaga_importe_Horas_Total);
    printf("\n\tImporte neto total: %.2f",maximapaga_importeneto);

    printf("\n--------------------\n");

    printf("\nObrero con mayor cantidad de horas: ");
    printf("\n\tNumero de legajo: %i",maximohoras_numero_DeLegajo);
    printf("\n\tTotal de horas: %i",maximohoras_total_cantidad_Horas);
    printf("\n\tJornal por hora: %i",maximohoras_jornal);
    printf("\n\tImporte total: %.2f",maximohoras_importe_Horas_Total);
    printf("\n\tImporte neto total: %.2f",maximohoras_importeneto);

    printf("\n--------------------\n");

    printf("\nObrero con menor cantidad de horas: ");
    printf("\n\tNumero de legajo: %i",minimohoras_numero_DeLegajo);
    printf("\n\tTotal de horas: %i",minimohoras_total_cantidad_Horas);
    printf("\n\tJornal por hora: %i",minimohoras_jornal);
    printf("\n\tImporte total: %.2f",minimohoras_importe_Horas_Total);
    printf("\n\tImporte neto total: %.2f",minimohoras_importeneto);

    printf("\n--------------------\n");

    printf("\nPromedios: ");
    printf("\n\tHoras normales: %.2f",promedio_HorasNormales);
    printf("\n\tHoras extras: %.2f",promedio_HorasExtras);
    printf("\n\tImporte a pagar: %.2f",promedio_importe_HorasTotal);
    printf("\n\tNeto a pagar: %.2f",promedio_importeneto);


    printf("\n--------------------\n");

    getch();
}
