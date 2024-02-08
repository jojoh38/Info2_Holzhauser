#include "namesarchive_211123.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int numberOfNames = 0;
static char **archive = NULL;
static int compNames(const void*, const void*);

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
int addNameDynArr(const char *name)
{
    char **temp;

    temp = (char **)realloc(archive, sizeof(char *) * (numberOfNames+1));
    if(temp == NULL)
        return 0;
    archive = temp;

    char *addr_names = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    if (addr_names == NULL)
        return 0;

    archive[numberOfNames] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(addr_names, name);

    strcpy(archive[numberOfNames], name);

    numberOfNames++;
    return(1);
}

// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSortedDynArr(const char *name)
{
    char **temp;

    temp = (char **)realloc(archive, sizeof(char *) * (numberOfNames + 1));
    if(temp == NULL)
    {
        printf("SPEICHERPLATZMANGEL!!!\n");
        return -1;
    }
    archive = temp;

    int i;
    for(i = 0; i < numberOfNames; i++)
    { // 1. addName(name) -> 2. qsort -> return
        if(strcmp(archive[i], name) > 0)
        {
            // Make room for the new name by shifting elements to the right
            temp = (char **)realloc(archive, sizeof(char *) * (numberOfNames + 1));
            if (temp == NULL)
            {
                printf("SPEICHERPLATZMANGEL!!!\n");
                return -1;
            }

            archive = temp;

            for (int j = numberOfNames; j > i; j--)
            {
                archive[j] = archive[j - 1];
            }

            archive[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
            if (archive[i] == NULL)
            {
                printf("SPEICHERPLATZMANGEL!!!\n");
                return -1;
            }

            strcpy(archive[i], name);
            break;
        }

    }
    // If the new name is greater than all existing names, add it at the end
    if (i == numberOfNames)
    {
        archive[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        if (archive[i] == NULL)
        {
            printf("SPEICHERPLATZMANGEL!!!\n");
            return -1;
        }

        strcpy(archive[i], name);
    }

    numberOfNames++;
    return 1;
}


// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeNameDynArr(const char *name)
{
    for(int i = 0; i < numberOfNames; i++)
    {
        if(strcasecmp(archive[i], name) == 0)
        {
            free(archive[i]);
            for(int j = i; j < numberOfNames - 1; j++)
                archive[j] = archive[j + 1];

            // Reduce the size of the 'archive' array
            archive = (char **)realloc(archive, sizeof(char *) * (numberOfNames - 1));
            if (archive == NULL)
                return 0;

            numberOfNames--;
            return 1;
        }
    }
    return 0;
}



// Sortiert die Namen im Archiv aufsteigend.
void sortNamesDynArr() {
    qsort(archive, numberOfNames, sizeof(archive[0]), compNames);
}

// Gibt die Namen zeilenweise aus.
void printNamesDynArr()
{
    for(int i = 0; i < numberOfNames; i++){
        printf("%s\n", archive[i]);
    }

}

// Leert das Archiv
void clearArchiveDynArr()
{
    for (int i = 0; i < numberOfNames; i++)
    {
        free(archive[i]);
    }

    free(archive);
    numberOfNames = 0;
}

static int compNames(const void* arg1, const void* arg2)
{
        char* name1 = *(char**) arg1;
        char* name2 = *(char**) arg2;
/*
    int i = 0;
    while(name1[i]) {
        name1[i] = tolower(name1[i]);
        i++;
    }

    i = 0;
    while(name2[i]) {
        name2[i] = tolower(name2[i]);
        i++;
    }
*/
        int i;
        for(i = 0; name1[i] != '\0' && name2[i] != '\0'; i++) {
            if(tolower(name1[i]) > tolower(name2[i])) return 1;
            else if(tolower(name1[i]) < tolower(name2[i])) return -1;
        }
        if(name1[i] != '\0') return -1;
        if(name2[i] != '\0') return 1;
        return 0;
    }