#include <stdio.h>
#include <conio.h>

void main()
{
    int nro,sum,i,n,elemmax;
    float prom;
    float min;

    sum = 0;
    i=1;
    n=1;

    printf("Ingrese cuantas veces quiere repetir el ciclo: ");
    scanf("%i",&n);

    for (i;i<=n;i++)
    {
        printf("\nCiclo num.: %d",i);
        printf("\nInserte un numero: ");

        scanf("%i",&nro);
        sum += nro;
        if ( i==1)
            {
                min=nro;
                elemmax=i;
            }
        else if ( min>  nro)
            {
                min = nro;
                elemmax = i;
            }
    }


    prom = sum/(i-1);
    printf("\nEl promedio es: %.2f",prom);
    printf("\nLa suma de los numeros es %i",sum);
    printf("\nEl minimo del conjunto es %.2f",min);
    printf("\nFue ingresado en el ciclo: %d",elemmax);
    getch();
}
