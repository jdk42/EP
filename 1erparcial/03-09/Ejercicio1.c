#include <stdio.h>
#include <conio.h>

void main()
{
    int nro,sum,i,n;
    float prom;
    sum = 0;
    i=1;
    n=1;

    printf("Ingrese cuantas veces quiere repetir el ciclo: ");
    scanf("%i",&n);

    for (i;i<=n;i++)
    {
        printf("\nInserte un numero: ");
        scanf("%i",&nro);
        sum += nro;
    }

    prom = sum/(i-1);
    printf("\nEl promedio es: %.2f",prom);
    printf("\nLa suma de los numeros es %i",sum);
    getch();
}
