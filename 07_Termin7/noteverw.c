/*****************************************************************
 * Aufgabe 28_4_4 Notenübersicht                      27.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste{
    char Vorname[10];
    char Nachname[10];
    int note;
}List;

int main()
{
    int i = 0;
    int durchschnitt = 0;
    printf("----Eingabe des 1. Schuelers----\n");
    List Schueler[10];
    printf("\nName:\t\t");
    while(scanf("%s", Schueler[i].Nachname) == 1)
        {
          scanf("\n Vorname: \t\t%s\n Note:\t\t%d\n",Schueler[i].Vorname, &Schueler[i].note);
            i++;
            printf("----Eingabe des %d. Schuelers----",i);
            durchschnitt += Schueler[i].note;
        }
    //Tabellenausgabe
    printf("\t Name \t\t, Vorname \t\t , Note \n--------------------------------------------------------");
    for( int j = 0; j<=i; j++)
        {
            printf("%d . %s \t\t, %s \t\t , %d\n ", j, Schueler[j].Nachname, Schueler[j].Vorname, Schueler[j].note );
        }
    if(i > 0)
    {
        durchschnitt /= i;
        printf("Durchschnittsnote: %d\n", durchschnitt);
    }
}