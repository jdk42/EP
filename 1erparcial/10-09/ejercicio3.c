#include <stdio.h>
#include <conio.h>

void main()
{
    int capicuatriple=0,quintuple=0,num1,num2,num3,num4,num5;

    scanf("%i %i %i %i %i",&num1,&num2,&num3,&num4,&num5);

    while ((num1 + num2 +num3 + num4 +num5) !=0)
    {

        if (num1==num2 && num2==num3 && num3==num4 && num4==num5)
            quintuple++;

        else if ((num1==num5) && (num2==num3 && num3==num4))
            capicuatriple++;

        printf("\n----------------\n");
        scanf("%i%i%i%i%i",&num1,&num2,&num3,&num4,&num5);
    }

    printf("\nHubo %i capicuas triples",capicuatriple);
    printf("\nHubo %i quintuples",quintuple);
    getch();
}
