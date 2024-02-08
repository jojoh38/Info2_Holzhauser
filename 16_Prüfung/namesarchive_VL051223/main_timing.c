/*
 * Vervollständigen Sie das untenstehende Programm, indem Sie das Modul namesarchive in der
 * namesarchive.h bzw. namesarchive.c implementieren.
 * Die öffentlichen Schnittstellen mit genaueren Details entnehmen Sie der namesarchive.h.
 * Das Programm soll das Modul als dynamische Laufzeitbibliothek nutzen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "namesarchive.h"
#include "namesarchive_141123.h"
#include "namesarchive_211123.h"

#define NUM_NAMES 100000

void testAddRandom(int numberOfTimes, const char *names[], int numNames);
void testRemoveRandom(int numberOfPersonsToRemove, const char *names[], int numNames);
void testAddRandomStatArr(int numberOfTimes, const char *names[], int numNames);
void testRemoveRandomStatArr(int numberOfPersonsToRemove, const char *names[], int numNames);
void testAddRandomDynArr(int numberOfTimes, const char *names[], int numNames);
void testRemoveRandomDynArr(int numberOfPersonsToRemove, const char *names[], int numNames);

char *generateRandomString();
void generateRandomNames(const char *randomNames[], int numNames);
void freeRandomNames(const char *randomNames[], int numNames);

int main()
{
    const char *randomNames[NUM_NAMES];

    // Generate random names
    generateRandomNames(randomNames, NUM_NAMES);
    int numNames = sizeof(randomNames) / sizeof(randomNames[0]);

    // Startzeit festhalten
    printf("\n################################################################\n");
    printf("Mit statischem Array 87302 Namen hinzufuegen und 25024 loeschen.");
    clock_t start = clock();

    // Liste mit zufälligen Namen erzeugen
    testAddRandomStatArr(87302, randomNames, numNames);
    printf("\nNamen sortiert hinzugefuegt.\n");

    // wie lange hat das gedauert?
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    start = clock();
    printf("Name \"Matthias\" sortiert hinzufuegen.\n");
    addNameSortedStatArr("Matthias");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    // Timer erneut setzen
    start = clock();

    // zufällig Namen aus Liste löschen
    testRemoveRandomStatArr(25024, randomNames, numNames);
    printf("Namen entfernt.\n");

    // wie lange hat das gedauert?
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    // Startzeit festhalten
    printf("\n################################################################\n");
    printf("Mit dynamischem Array 87302 Namen hinzufuegen und 25024 loeschen.");
    start = clock();

    // Liste mit zufälligen Namen erzeugen
    testAddRandomDynArr(87302, randomNames, numNames);
    sortNamesDynArr();
    printf("\nNamen sortiert hinzugefuegt.\n");

    // wie lange hat das gedauert?
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    start = clock();
    printf("Name \"Matthias\" sortiert hinzufuegen.\n");
    addNameSortedDynArr("Matthias");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    // Timer erneut setzen
    start = clock();

    // zufällig Namen aus Liste löschen
    testRemoveRandomDynArr(25024, randomNames, numNames);
    printf("Namen entfernt.\n");

    // wie lange hat das gedauert?
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);
    clearArchiveDynArr();

    // Startzeit festhalten
    printf("\n################################################################\n");
    printf("Mit verketteter Liste 87302 Namen hinzufuegen und 25024 loeschen.");
    start = clock();

    // Liste mit zufälligen Namen erzeugen
    testAddRandom(87302, randomNames, numNames);
    printf("\nNamen sortiert hinzugefuegt.\n");

    // wie lange hat das gedauert?
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    start = clock();
    printf("Name \"Matthias\" sortiert hinzufuegen.\n");
    addName("Matthias");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    // Timer erneut setzen
    start = clock();

    // zufällig Namen aus Liste löschen
    testRemoveRandom(25024, randomNames, numNames);
    printf("Namen entfernt.\n");

    // wie lange hat das gedauert?
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("dauerte: %f sec\n", cpu_time_used);

    return EXIT_SUCCESS;
}

void testAddRandom(int numberOfTimes, const char *names[], int numNames)
{
    srand(time(NULL));

    const char *addedNames[numNames];  // Array to store added names
    int numAddedNames = 0;

    // Call testAdd function with random values
    for (int i = 0; i < numberOfTimes; ++i)
    {
        int randomIndex = rand() % numNames;

        // Check if the name is not already added
        int isAlreadyAdded = 0;
        for (int j = 0; j < numAddedNames; ++j)
        {
            if (strcmp(addedNames[j], names[randomIndex]) == 0)
            {
                isAlreadyAdded = 1;
                break;
            }
        }

        if (!isAlreadyAdded)
        {
            if (addName(names[randomIndex]))
                addedNames[numAddedNames++] = names[randomIndex];
            else
                printf("Fehler beim Hinzufuegen!\n");
        }
    }
}

void testRemoveRandom(int numberOfPersonsToRemove, const char *names[], int numNames)
{
    srand(time(NULL));

    // Call testRemove function with random values
    for (int i = 0; i < numberOfPersonsToRemove; ++i)
    {
        int randomIndex = rand() % numNames;
        removeName(names[randomIndex]);
    }
}

void testAddRandomStatArr(int numberOfTimes, const char *names[], int numNames)
{
    srand(time(NULL));

    const char *addedNames[numNames];  // Array to store added names
    int numAddedNames = 0;

    // Call testAdd function with random values
    for (int i = 0; i < numberOfTimes; ++i)
    {
        int randomIndex = rand() % numNames;

        // Check if the name is not already added
        int isAlreadyAdded = 0;
        for (int j = 0; j < numAddedNames; ++j)
        {
            if (strcmp(addedNames[j], names[randomIndex]) == 0)
            {
                isAlreadyAdded = 1;
                break;
            }
        }

        if (!isAlreadyAdded)
        {
            if (addNameSortedStatArr(names[randomIndex]))
                addedNames[numAddedNames++] = names[randomIndex];
            else
                printf("Fehler beim Hinzufuegen!\n");
        }
    }
}

void testRemoveRandomStatArr(int numberOfPersonsToRemove, const char *names[], int numNames)
{
    srand(time(NULL));

    // Call testRemove function with random values
    for (int i = 0; i < numberOfPersonsToRemove; ++i)
    {
        int randomIndex = rand() % numNames;
        removeNameStatArr(names[randomIndex]);
    }
}

void testAddRandomDynArr(int numberOfTimes, const char *names[], int numNames)
{
    srand(time(NULL));

    const char *addedNames[numNames];  // Array to store added names
    int numAddedNames = 0;

    // Call testAdd function with random values
    for (int i = 0; i < numberOfTimes; ++i)
    {
        int randomIndex = rand() % numNames;

        // Check if the name is not already added
        int isAlreadyAdded = 0;
        for (int j = 0; j < numAddedNames; ++j)
        {
            if (strcmp(addedNames[j], names[randomIndex]) == 0)
            {
                isAlreadyAdded = 1;
                break;
            }
        }

        if (!isAlreadyAdded)
        {
            if (addNameDynArr(names[randomIndex]))
                addedNames[numAddedNames++] = names[randomIndex];
            else
                printf("Fehler beim Hinzufuegen!\n");
        }
    }
}

void testRemoveRandomDynArr(int numberOfPersonsToRemove, const char *names[], int numNames)
{
    srand(time(NULL));

    // Call testRemove function with random values
    for (int i = 0; i < numberOfPersonsToRemove; ++i)
    {
        int randomIndex = rand() % numNames;
        removeNameDynArr(names[randomIndex]);
    }
}


// Funktion, um zufälligen String von zufälliger Länge zu erzeugen
char *generateRandomString()
{
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = rand() % 10 + 1;  // zufällige Länge zwischen 1 und 10 Zeichen
    char *randomString = malloc(length + 1);  // +1 wg null Terminator

    if (randomString == NULL)
    {
        fprintf(stderr, "Speicherfehler\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; ++i)
    {
        int index = rand() % (int)(sizeof(charset) - 1);
        randomString[i] = charset[index];
    }

    randomString[length] = '\0';  // Null-terminierter String
    return randomString;
}

// Funktion um ein Array mit zufälligen strings zu erzeugen
void generateRandomNames(const char *randomNames[], int numNames)
{
    srand(time(NULL));

    for (int i = 0; i < numNames; ++i)
        randomNames[i] = generateRandomString();
}

// Funktion, um Speicher der Zufallsstrings freizugeben
void freeRandomNames(const char *randomNames[], int numNames)
{
    for (int i = 0; i < numNames; ++i)
        free((char *)randomNames[i]);
}