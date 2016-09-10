#include <stdio.h>
#include <conio.h>

void main()
{
    int i,j,calculo;

    for (i=1;i<=10;i++)
    {
        for (j=1;j<=10;j++)
            {
                calculo = j*i;
                if (calculo % 2 == 0)
                {
                    //system("color 2");
                    printf("%d ",calculo);
                }
                else
                    printf("%d ",calculo);
            }
        printf("\n");
    }
}
