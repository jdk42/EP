#include <stdio.h>
#include <conio.h>

int main()
{
    int codigo,contador,cantidad,error;
    float precioFinal,descuento;

    contador = 0;
    printf("Ingrese numero de producto:\n");
    scanf("%i",&codigo);
    printf("Ingrese cantidad de producto:\n");
    scanf("%i",&cantidad);

    switch(codigo)
    {
        case 1:
        case 10:
        case 100:
            contador=10;
            break;
        case 2:
        case 22:
        case 222:
             contador=7;
             break;
        case 3:
        case 33:
            contador=3;
            break;
        case 4:
        case 44:
            contador=1;
            break;
        default:
            printf("CODIGO MAL INGRESADO\n");
            error=1;
            break;
    }

    if (contador == 10 )
        {
            precioFinal = contador * cantidad;
        }
    else
    {
        if (contador==7 && ((cantidad % 10 == 0)))
            precioFinal = (cantidad/10) * 65;
        else{
            if (contador==7 && ((cantidad % 10 != 0)))
            {
                precioFinal = contador * cantidad;
            }
            else
            {
                if (contador==3 && cantidad >=10)
                {
                    descuento = (cantidad * contador * 10) / 100;
                    precioFinal = (contador * cantidad) - descuento;
                }
                else
                    {
                        if (contador==3 && cantidad <10)
                        {
                            precioFinal = contador * cantidad;
                        }
                        else
                            precioFinal = contador * cantidad;
                    }

            }
        }
    }
    if (error != 1)
        printf("ARTICULO\t %i \t CANTIDAD \t %i \t IMPORTE A PAGAR $ %.2f",codigo,cantidad,precioFinal);
    else{}

    printf("\nPresione una tecla para finalizar\n");
    getch();
    return(0);
}
