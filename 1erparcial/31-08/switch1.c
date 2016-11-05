#include <stdio.h>
#include <conio.h>

int main()
{
    int rubro;
    printf("Ingrese numero de rubro:\n");
    scanf("%i",&rubro);

    switch(rubro)
    {
        case 1:
        case 2: printf("CARNICERIA\n"); break;
        case 3: printf("ALMACEN\n"); break;
        case 4: printf("TIENDAS\n"); break;
        default: printf("NUMERO MAL INGRESADO\n"); break;
    }
    printf("Presione cualquier tecla para finalizar");
    getch();
    return(0);
}
