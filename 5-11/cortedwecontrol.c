#include <stdio.h>
#include <conio.h>

int main()
{
    int tgral=0,cli=0,cli_a=0,tcli=0,tart=0,art_a=0,art=0,impt=0;

    printf("\nInserte cliente: ");
    scanf("%i",&cli);
    printf("\nInserte art: ");
    scanf("%i",&art);

    printf("\nInserte impt: ");
    scanf("%i",&impt);

    while(cli!=999)
    {
    tcli=0;
    cli_a=cli;
    while(cli!=999&&cli_a==cli)
    {
        tart=0;
        art_a=art;
        while(cli!=999&&cli_a==cli&&art_a==art)
        {
            tgral += impt;
            tcli += impt;
            tart += impt;

        printf("\nInserte cliente: ");
        scanf("%i",&cli);

        printf("\nInserte art: ");
        scanf("%i",&art);

        printf("\nInserte impt: ");
        scanf("%i",&impt);

        }
        printf("\nArticulo: %i Importe Total: %i",art_a,tart);
    }
    printf("\nCliente: %i Importe Total: %i",cli_a,tcli);
    }
    printf("\nImporte total: %i",tgral);

    getch();
    return (0);
}
