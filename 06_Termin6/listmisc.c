/*****************************************************************
 * Aufgabe 28_6_1 Mischen von zwei Listen             16.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30

struct listen
{
    char *liste[100];
    int anzahl;
};

void add_name(char *name, int namenzahl, struct listen *zeiger);
static int vergleichen(const void* name1, const void* name2);

int main ()
{
    // Structs Erstellen
    struct listen l1, l2, misch; 
    struct listen *zeiger = NULL;
    //Variablen initialisieren
    char name[MAX_NAME_LEN] = "\0";
    int auswahl = 0;
    l1.anzahl = 0, l2.anzahl = 0, misch.anzahl = 0;
    //Benutzerabfrage starten
    printf("Name:");
    fgets(name,29,stdin); 
    while(name[0] != '\n') //Abbruchbedingung 
    {
        printf("Welche Liste (1 oder 2):");
        while ((scanf("%d",&auswahl) != 1) || auswahl <= 0 || auswahl > 2)
        {
            printf("\nFalsche Eingabe!");
            fflush(stdin);
        }
        fflush(stdin); // Eingabepuffer löschen
        if (auswahl == 1)
        {
            zeiger = &l1;
            add_name(name,l1.anzahl,zeiger);
        }
        else
        {
            zeiger = &l2;
            add_name(name,l2.anzahl,zeiger);
        }
        printf("\nName:");
        fgets(name,29,stdin);
    }
    //Liste 1 und 2 sortieren
    qsort(l1.liste,l1.anzahl,sizeof(l1.liste[0]),vergleichen);
    qsort(l2.liste,l2.anzahl,sizeof(l2.liste[0]),vergleichen);
    //Misch liste zusammenfügen
    for (int i = 0; i < l1.anzahl; i++)
    {
        misch.liste[i] = (char*)malloc(strlen(l1.liste[i]) + 1);
        strcpy(misch.liste[i],l1.liste[i]);
    }
    int j = 0;
    for (int i = l1.anzahl; i < (l2.anzahl + l1.anzahl); i++)
    {
        misch.liste[i] = (char*)malloc(strlen(l2.liste[j]) + 1);
        strcpy(misch.liste[i],l2.liste[j]);
        j++;
    }
    misch.anzahl = (l2.anzahl + l1.anzahl);
    qsort(misch.liste,misch.anzahl,sizeof(misch.liste[0]),vergleichen);
    //Ausgabe
    printf("\n....1.Liste.......\n");
    for(int i = 0; i < l1.anzahl; i++)
        printf("%s", l1.liste[i]);
    printf("....Listenende....\n\n....2.Liste.......\n");
    for(int b = 0; b < l2.anzahl; b++)
        printf("%s", l2.liste[b]);
    printf("....Listenende....\n\n.....Gemischte. Liste.........\n");
    for(int i = 0; i < (l1.anzahl + l2.anzahl); i++)
        printf("%s", misch.liste[i]);
    return 0;
}
void add_name(char *name, int namenzahl, struct listen *zeiger)
{
    zeiger->liste[namenzahl] =(char*)malloc(strlen(name) * sizeof(char));
    strcpy(zeiger->liste[namenzahl],name);
    zeiger->anzahl++;
}
static int vergleichen(const void* name1, const void* name2)
{
    int vergleich = 0;
    vergleich = stricmp(*(char**)name1,*(char**)name2); //1.* aus Funktionsaufruf 2.* Zeigt die Stelle im Array 3. * Zeigt auf die Zeichenkette dahinter 
    if(vergleich > 0) //Falls getauscht wird, Speicher neu reservieren
    {
        if (strlen(*(char**)name1) > strlen(*(char**)name2))
            *(char**)name2 = realloc(*(char**)name2,strlen(*(char**)name1) * sizeof(char));
        else if(strlen(*(char**)name2) > strlen(*(char**)name1))
            *(char**)name1 = realloc(*(char**)name1,strlen(*(char**)name2) * sizeof(char));
        return 1;
    }
    else
        return -1;
    return 0;
}
