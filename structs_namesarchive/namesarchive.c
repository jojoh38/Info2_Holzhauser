#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int numberOfPersons = 0;
static Person archive[MAX_PERSONS];

// Fügt eine Person hinzu.
int addPerson(const Person newPerson)
{
    if(numberOfPersons >= MAX_PERSONS)
        return 0;

    archive[numberOfPersons] = newPerson;
    numberOfPersons++;

    return 1;
}

// Entfernt eine Person aus dem Archiv, nur wenn Name und Alter in einem Eintrag übereinstimmen.
int removePerson(const Person person)
{
    for(int i = 0; i < numberOfPersons; i++)
    {
        if((strcmp(archive[i].name, person.name) == 0) && (archive[i].age == person.age))
        {
            for(int j = i; j < numberOfPersons -1; j++)
                archive[j] = archive[j+1];
            numberOfPersons--;
            return 1;
        }
    }
    return 0;
}

// Gibt die enthaltenen Personen zeilenweise in der Form "<Name> ist <Alter> Jahre alt." aus.
void printPersons()
{
    for(int i = 0; i < numberOfPersons; i++)
        printf("%s ist %d Jahre alt. \n", archive[i].name, archive[i].age);
}

static int compareByName(const void *arg1, const void *arg2)
{
    const Person *person1 = (const Person *) arg1;
    const Person *person2 = (const Person *) arg2;

    int nameDiff = strcmp(person1->name, person2->name);

    if(nameDiff == 0)
        return person1->age - person2->age;
    else
        return nameDiff;
}

static int compareByAge(const void *arg1, const void *arg2)
{
    const Person *person1 = (const Person *) arg1;
    const Person *person2 = (const Person *) arg2;

    int ageDiff = person1->age - person2->age;

    if(ageDiff == 0)
        return strcmp(person1->name, person2->name);
    else
        return ageDiff;
}

// Sortiert das Archiv je nach Sortierungsart entweder nach Name und bei Übereinstimmung nach Alter oder umgekehrt.
void sortPersons(SortType type)
{
    int (*compareFunc) (const void*, const void *) = NULL;

    if(type == SORT_BY_NAME)
        compareFunc = compareByName;
    else if(type == SORT_BY_AGE)
        compareFunc = compareByAge;

    if(compareFunc != NULL)
        qsort(archive, numberOfPersons, sizeof(archive[0]), compareFunc );
}