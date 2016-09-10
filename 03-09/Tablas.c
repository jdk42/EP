#include <stdio.h>
#include <conio.h>

int main()
{
    int i,d,j;


        for (i=1;i<=10;i++)
        {
            for (j=1;j<=10;j++)
                {
                    d=j*i;
                    printf("%d ",d);
                }
                printf("\n");
        }

    getch();
    return(0);
}
