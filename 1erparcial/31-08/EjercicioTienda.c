#include <stdio.h>
#include <conio.h>

int main()
{
    int rubro,cantidad;
    float precio,importe,descuento,importeneto;
    printf("\nCodigo\t\t\tRubro");
    printf("\n1\t\t\tVERDULERIA");
    printf("\n2\t\t\tCARNICERIA");
    printf("\n3\t\t\tALMACEN");
    printf("\n4\t\t\tTIENDAS");
    printf("\n\nIngrese el codigo del rubro:");
    scanf("%i",&rubro);

    printf("Ingrese el precio del producto:");
    scanf("%f",&precio);

    printf("Ingrese la cantidad del producto:");
    scanf("%i",&cantidad);

    switch(rubro)
        {
        case 1:
            importe = cantidad * precio;
            descuento = (importe * 15) / 100;
            printf("\nRubro del producto: Verduleria");
            importeneto = importe - descuento;
            printf("\nEl importe a pagar es %.2f\n",importeneto);
            break;
        case 2:
            importe = cantidad * precio;
            descuento = (importe * 10) / 100;
            printf("\nRubro del producto: Carniceria");
            importeneto = importe - descuento;
            printf("\nEl importe a pagar es %.2f\n",importeneto);
            break;
        case 3:
            importe = cantidad * precio;
            descuento = (importe * 20) / 100;
            printf("\nRubro del producto: Almacen");
            importeneto = importe - descuento;
            printf("\nEl importe a pagar es %.2f\n",importeneto);
            break;
        case 4:
            importe = cantidad * precio;
            descuento = (importe * 20) / 100;
            printf("\nRubro del producto: Tiendas");
            importeneto = importe - descuento;
            printf("\nEl importe a pagar es %.2f\n",importeneto);
            break;
        default:
            printf("\nCodigo incorrecto\n");
            break;
        }
        printf("\nPresione una tecla para finalizar\n");
        getch();
        return(0);
}
