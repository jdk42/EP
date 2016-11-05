#include <stdio.h>
#include <conio.h>

void main()
{
    int nro,sum,i,n,elemmax;
    float prom;
    float max;

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
        if ( i==1)
            {
                max=nro;
                elemmax=i;
            }
        else if ( max < nro)
            {
                max = nro;
                elemmax = i;
            }
    }


    prom = sum/(i-1);
    printf("\nEl promedio es: %.2f",prom);
    printf("\nLa suma de los numeros es %i",sum);
    printf("\nEl maximo del conjunto es %.2f",max);
    printf("\nFue ingresado en el ciclo: %d",elemmax);
    getch();
}
