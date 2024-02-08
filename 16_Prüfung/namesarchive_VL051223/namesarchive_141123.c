#include "namesarchive_141123.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int numberOfNames = 0;
static char archive[MAX_NAMES][MAX_NAME_LEN] = {0};
static int compNames(const void*, const void*);

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
int addNameStatArr(const char *name)
{
    // Versuch Philipp
    if(numberOfNames >= MAX_NAMES) return(0); //Abbrechne wenn alle Berreiche vergeben oder Name zu lang
    char *addr_names = archive[numberOfNames];
    for(int i = 0; i < MAX_NAME_LEN; i++) *(addr_names +i) = *(name + i);
    numberOfNames++;
    return(1);
}

// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSortedStatArr(const char *name)
{
    for(int i = 0; i < numberOfNames; i++)
    { // 1. addName(name) -> 2. qsort -> return
        if(strcmp(archive[i], name) > 0)
        {
            for(int j = numberOfNames; j >= i; j--)
                strncpy(archive[j],archive[j-1],MAX_NAME_LEN);

            strncpy(archive[i], name, MAX_NAME_LEN);
            break;
        }

    }
    numberOfNames++;
    return 1;
}

// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeNameStatArr(const char *name)
{
    for(int i = 0; i < numberOfNames; i++) {
        if(strncmp(archive[i], name, MAX_NAME_LEN) == 0) {
            for(int j = i; j < numberOfNames; j++) {
                strcpy(archive[j-1], archive[j]); // Hans [j+1] -> Alexander [j] -> Hans\0nder [j]
            }
            numberOfNames--;
            return 1;
        }
    }
    return 0;
}

// Sortiert die Namen im Archiv aufsteigend.
void sortNamesStatArr() {
    qsort(archive, numberOfNames, sizeof(archive[0]), compNames);
}


// Gibt die Namen zeilenweise aus.
void printNamesStatArr()
{
    for(int i = 0; i < numberOfNames; i++){
        printf("%s\n", archive[i]);
    }
}

static int compNames(const void* arg1, const void* arg2) { // returns 1 when arg1 > arg2
    char* name1 = (char*) arg1;
    char* name2 = (char*) arg2;

    int i;
    for(i = 0; name1[i] != '\0' && name2[i] != '\0'; i++) {
        if(tolower(name1[i]) > tolower(name2[i])) return 1;
        else if(tolower(name1[i]) < tolower(name2[i])) return -1;
    }
    if(name1[i] != '\0') return -1;
    if(name2[i] != '\0') return 1;
    return 0;
}