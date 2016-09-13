#include <stdio.h>
#include <conio.h>

void main()
{
    float importe,codigoC,codigoE,codigoT,totalC,totalE=0,totalT=0,total=0,iva=0,acumuladorT,acumuladorE,acumuladorC;
    char codigo;

    printf("Ingresa la forma de pago: ");
    scanf(" %c",&codigo);
    getchar();

    while (codigo != 'F')
    {
        printf("\nIngresar el importe: ");
        scanf("%f",&importe);

        if ( codigo == 'C')
        {
            codigoC = (importe * 30)/100;
            //printf("\n%.2f",codigoC);
            totalC = (importe-codigoC);
            acumuladorC += totalC;
            //printf("\n%.2f",totalC);
            total+=totalC;
            //printf("\nTotal %.2f",total);
        }
        else
        {
            if ( codigo == 'E')
            {
                codigoE = (importe * 10)/100;
                totalE = (importe)-codigoE;
                acumuladorE += totalE;
                total+=totalE;
            }
            else{
                if ( codigo == 'T')
                {
                codigoT = (importe * 12)/100;
                totalT = (importe)+codigoT;
                acumuladorT += totalT;
                total+=totalT;
                }
                else
                    printf("Inserte E, F o T");
            }
        }

        printf("\nIngresa la forma de pago: ");
        scanf(" %c",&codigo);
    }

    iva = (total * 21)/100;

    printf("\nEfectivo en caja: %4.2f",acumuladorE);
    printf("\nVentas con tarjeta: %4.2f",acumuladorT);
    printf("\nTotal de ventas: %4.2f",total);
    printf("\nImporte del IVA: %4.2f",iva);

    getch();

}
