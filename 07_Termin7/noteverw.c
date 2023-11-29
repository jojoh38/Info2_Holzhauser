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
    float durchschnitt = 0;
    int noten[6] = {0};
    printf("----Eingabe des 1. Schuelers----\n");
    List Schueler[25];
    printf("Nachname:");
    while (fgets(Schueler[i].Nachname, 25, stdin) && Schueler[i].Nachname[0] != '\n')
    {
        Schueler[i].Nachname[strlen(Schueler[i].Nachname)-1] = '\0';
        printf("\nVorname:");
        fgets(Schueler[i].Vorname, 25, stdin); 
        int z = 0;
        while(Schueler[i].Vorname[z]!= '\n')
                z++;
        Schueler[i].Vorname[z] = '\0'; 
        printf("\nNote:");
        scanf("%d", &Schueler[i].note);
        durchschnitt += Schueler[i].note;
        if(Schueler[i].note == 1)
            noten[0]++;
        else if(Schueler[i].note == 2)
            noten[1]++;
        else if(Schueler[i].note == 3)
            noten[2]++;
        else if(Schueler[i].note == 4)
            noten[3]++;
        else if(Schueler[i].note == 5)
            noten[4]++;
        else if(Schueler[i].note == 6)
            noten[5]++;
        i++;
        printf("----Eingabe des %d. Schuelers----\n", (i+1));
        printf("Nachname:");
        fflush(stdin);  
    }
    printf("Nachname \t\t, Vorname \t\t , Note \n--------------------------------------------------------\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d . %s \t\t, %s \t\t , %d \n", (j+1), Schueler[j].Nachname, Schueler[j].Vorname, Schueler[j].note);
    }
    if (i > 0)
    {
        durchschnitt /= i;
        printf("Durchschnittsnote: %.3f\n", durchschnitt);
    }
    for(int k = 0; k < 6; k++)
    {
        printf("\nNote %d:",(k+1));
        for(int l = 1; l <= noten[k];l++)
            printf("*");
    }
    return 0;
}