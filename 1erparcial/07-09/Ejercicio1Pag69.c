#include <stdio.h>
#include <conio.h>

void main()
{
    int i,j;
    printf("\nImpar \tPar");
    for (i=1;i<=30;i++)
    {
                if ( i % 2 != 0)
                {
            printf("\n %d ",i);
                }
           if ( i % 2 == 0)
                {
            printf("\t %d ",i);
                }
    }
    getch();
}
