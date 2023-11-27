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
    while(scanf("\nName : \t\t %c", Schueler[i].Vorname) != 1)
        {
          scanf("\n Vorname: \t\t%c\n Note:\t\t%d\n",Schueler[i].Vorname, &Schueler[i].note);
            i++;
            printf("----Eingabe des %d. Schuelers----",i);
            durchschnitt += Schueler->note;
        }
    //Tabellenausgabe
    printf("")
}