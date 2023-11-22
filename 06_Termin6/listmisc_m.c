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
    struct listen l1; 
    struct listen l2; 
    struct listen misch; 
    struct listen *zeiger = NULL;
    char name[MAX_NAME_LEN] = "\0";
    int auswahl = 0;
    l1.anzahl = 0; 
    l2.anzahl = 0;
    misch.anzahl = 0;
    printf("Name:");
    fgets(name,25,stdin);
    while(name[0] != '\n')
    {
        printf("Welche Liste (1 oder 2):");
        while ((scanf("%d",&auswahl) != 1) || auswahl <= 0 || auswahl > 2)
        {
            printf("\nFalsche Eingabe!");
            while (getchar() != '\n') getchar();
        }
        fflush(stdin);
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
        fgets(name,25,stdin);
    }
    qsort(l1.liste,l1.anzahl,sizeof(l1.liste[0]),vergleichen);
    qsort(l2.liste,l2.anzahl,sizeof(l2.liste[0]),vergleichen);
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
    zeiger->liste[namenzahl] =(char*)malloc(strlen(name) + 1);
    strcpy(zeiger->liste[namenzahl],name);
    zeiger->anzahl++;
}
static int vergleichen(const void* name1, const void* name2)
{
    int vergleich = 0;
    char *zwischenpuffer;
    vergleich = strcmp(*(char**)name1,*(char**)name2);
    if(vergleich > 0)
    {
        zwischenpuffer = (char*)malloc(strlen(name1)*sizeof(char));
        zwischenpuffer = *(char**)name1;
        *(char**)name1 = (char*)realloc(*(char**)name1,strlen(*(char**)name2)*sizeof(char));
        *(char**)name2 = (char*)realloc(*(char**)name2,strlen(zwischenpuffer)*sizeof(char));
        free(zwischenpuffer);
        return 1;
    }
    else
        return -1;
    return 0;
}