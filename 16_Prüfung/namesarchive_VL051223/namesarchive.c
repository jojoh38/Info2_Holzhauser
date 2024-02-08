#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct names
{
    char *name;
    struct names *next;
} namesarchive;

static namesarchive *head = NULL;

static namesarchive *createEntry(const char *name)
{
    namesarchive *elem = (namesarchive *)calloc(sizeof(namesarchive), 1);
    if (elem == NULL)
        return NULL;

    elem->name = (char *)malloc(sizeof(char) *(strlen(name)+1));
    if(elem->name == NULL)
    {
        free(elem);
        return NULL;
    }
    strcpy(elem->name, name);

    return elem;
}

int addName(const char *name)
{
    namesarchive *newName, *currentName;
    if(head == NULL)
    {
        head = (namesarchive *)calloc(sizeof(namesarchive), 1);
        if(head == NULL)
            return 0;
    }

    newName = createEntry(name);

    if(newName == NULL)
        return 0;

    currentName = head;
    while((currentName->next != NULL) && (strcmp(currentName->next->name, newName->name) <0))
    {
        currentName = currentName->next;
    }

    newName->next = currentName->next;
    currentName->next = newName;

    return 1;
}

int removeName(const char *name)
{
    namesarchive *elem = head, *elemToDelete;

    if(elem == NULL)
        return 0;

    while((elem->next != NULL) && (strcmp(elem->next->name, name) != 0))
        elem = elem->next;

    if(elem->next == NULL)
        return 0;

    elemToDelete = elem->next;
    elem->next = elemToDelete->next;
    free(elemToDelete->name);
    free(elemToDelete);

    return 1;
}

void printNames()
{
    if(head == NULL)
        return;

    namesarchive *elem = head->next;

    while(elem!= NULL)
    {
        printf("%s\n", elem->name);
        elem = elem->next;
    }
}

void clearArchive()
{
    namesarchive *prevName;

    while(head != NULL)
    {
        prevName = head;
        head = head->next;
        free(prevName->name);
        free(prevName);
    }
    head = NULL;
}