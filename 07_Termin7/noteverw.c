/*****************************************************************
 * Aufgabe 28_4_4 Notenübersicht                      27.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste
{
    char Vorname[25];
    char Nachname[25];
    int note;
} List;

int main()
{
    int i = 0;
    int durchschnitt = 0;
    printf("----Eingabe des 1. Schuelers----\n");
    List Schueler[10];
    printf("Name:");
    fgets(Schueler[0].Nachname, 25, stdin);
    while (Schueler[i].Nachname[0] != '\n')
    {
        printf("\nVorname:");
        fgets(Schueler[i].Vorname, 25, stdin);
        printf("\nNote:");
        scanf("%d", &Schueler[i].note);
        durchschnitt += Schueler[i].note;
        i++;
        printf("----Eingabe des %d. Schuelers----\n", (i+1));
        fgets(Schueler[i].Nachname, 25, stdin);
        // while(getchar());
    }
    // Tabellenausgabe
    printf("\t Name \t\t, Vorname \t\t , Note \n--------------------------------------------------------\n");
    for (int j = 0; j <= i; j++)
    {
        printf("%d . %s \t\t\t, %s \t\t , %d\n ", (j+1), Schueler[j].Nachname, Schueler[j].Vorname, Schueler[j].note);
    }
    if (i > 0)
    {
        durchschnitt /= i;
        printf("Durchschnittsnote: %d\n", durchschnitt);
    }
}