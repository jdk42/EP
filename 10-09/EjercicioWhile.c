#include <conio.h>
#include <stdio.h>

void main()
{
    int articulo,cantidad,error=0,maxcantidad=0,maxorden=0,maxarticulo=0,mincantidad=0,minorden=0,minarticulo=0;
    float precio,promediocant=0,promedioimporte=0,importe,maxprecio=0,minprecio,test=0,contador_articulo=0,totalcantidad=0,acumuladorIMPT=0;

    printf("\nIngrese el codigo del producto: ");
    scanf("%i",&articulo);

    while ( articulo != 999)
    {

        printf("\nIngrese la cantidad del producto: ");
        scanf("%i",&cantidad);
        printf("\nIngrese el precio del producto: ");
        scanf("%f",&precio);

        if (articulo != 999)
        {
            totalcantidad += cantidad;
            contador_articulo++;
            importe = (precio*cantidad);
            acumuladorIMPT += importe;


            if (precio > maxprecio)
            {
                maxprecio = precio;
                maxcantidad = cantidad;
                maxorden = contador_articulo;
                maxarticulo = articulo;
            }
            else
            {
                if (precio > maxprecio)
                {
                    maxprecio = precio;
                    maxcantidad = cantidad;
                    maxorden = contador_articulo;
                    maxarticulo = articulo;
                }
            }

            if (precio < minprecio)
            {
                minprecio = precio;
                mincantidad = cantidad;
                minorden = contador_articulo;
                minarticulo = articulo;
            }

            else
            {
                if (precio < minprecio)
                {
                    minprecio = precio;
                    mincantidad = cantidad;
                    minorden = contador_articulo;
                    minarticulo = articulo;
                }
            }

            printf("\n-------------------------------------");
            printf("\nIngrese el codigo del producto: ");
            scanf("%i",&articulo);
        }
        else
            error++;
    }

    if (error < contador_articulo)
    {
        promediocant = (totalcantidad/contador_articulo);
        promedioimporte = (acumuladorIMPT/totalcantidad);

        printf("\nEl promedio de cantidad es %.2f",promediocant);
        printf("\nEl promedio de importe es %.2f",promedioimporte);
        printf("\nEl mayor precio es %.2f,perteneciente al producto %d con una cantidad %d ingresado numero %d",maxprecio,maxarticulo,maxcantidad,maxorden);
        printf("\nEl menor precio es %.2f,perteneciente al producto %d con una cantidad %d ingresado numero %d",minprecio,minarticulo,mincantidad,minorden);
    }
    else
        printf("error");

    getch();

}
