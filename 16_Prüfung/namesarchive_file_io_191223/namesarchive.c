#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NodeStruct
{
    char *name;
    struct NodeStruct *left;
    struct NodeStruct *right;
} Node;

static Node *root = NULL;

static Node *createNode(const char *name)
{
    Node *node = (Node *) calloc(1, sizeof (Node));

    if(node != NULL)
    {
        node->name = (char *) malloc(sizeof (char) * (strlen(name) +1));
        if (node->name != NULL)
            strcpy(node->name, name);
        else
        {
            free(node);
            node = NULL;
        }
    }
    return node;
}

static Node *addNode(Node *currentNode, Node *newNode)
{
    if(currentNode == NULL)
        currentNode = newNode;
    else if(strcmp(newNode->name, currentNode->name) <= 0)
        currentNode->left = addNode(currentNode->left, newNode);
    else
        currentNode->right = addNode(currentNode->right, newNode);

    return currentNode;
}

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
// Der Name soll in beliebiger Länge gespeichert werden können.
int addName(const char *name)
{
    Node *newNode = createNode(name);

    if(newNode != NULL)
    {
        root = addNode(root, newNode);
        return 1;
    }
    else
        return 0;
}

static int existsNode(Node *currentNode, const char *name)
{
    if((currentNode == NULL) || (strcmp(name, currentNode->name) == 0))
        return currentNode != NULL;
    else if(strcmp(name, currentNode->name) < 0)
        return existsNode(currentNode->left, name);
    else
        return existsNode(currentNode->right, name);
}

static Node *removeNode(Node *currentNode, const char *name)
{
    if(currentNode != NULL)
    {
        if(strcmp(name, currentNode->name) < 0)
            currentNode->left = removeNode(currentNode->left, name);
        else if (strcmp(name, currentNode->name) > 0)
            currentNode->right = removeNode(currentNode->right, name);
        else
        {
            if(currentNode->left == NULL)
            {
                Node *node = currentNode->right;
                free(currentNode->name);
                free(currentNode);
                currentNode = node;
            }
            else if(currentNode->right == NULL)
            {
                Node *node = currentNode->left;
                free(currentNode->name);
                free(currentNode);
                currentNode = node;
            }
            else
            {
                Node *succPar = currentNode;
                Node *succ = currentNode->right;

                while(succ->left != NULL)
                {
                    succPar = succ;
                    succ = succ->left;
                }

                if(succPar != currentNode)
                    succPar->left = succ->right;
                else
                    succPar->right = succ->right;

                free(currentNode->name);
                currentNode->name = succ->name;
                free(succ);
            }
        }
    }

    return currentNode;
}

// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name)
{
    if(existsNode(root, name))
    {
        root = removeNode(root, name);
        return 1;
    }
    else
        return 0;
}

static void printNodes(Node *node)
{
    if(node != NULL)
    {
        printNodes(node->left);
        printf("%s\n", node->name);
        printNodes(node->right);
    }
}

// Gibt die Namen zeilenweise aus.
void printNames()
{
    printNodes(root);
}

static void clearNodes(Node *node)
{
    if(node != NULL)
    {
        clearNodes(node->left);
        clearNodes(node->right);
        free(node->name);
        free(node);
    }
}

// Leert das Archiv
void clearArchive()
{
    clearNodes(root);
    root = NULL;
}

// Lädt den Inhalt einer Textdatei zeilenweise in das Archiv. Gibt 1 bei Erfolg zurück.
int loadArchive(const char *path)
{
    char buffer[MAX_NAME_LEN];
    FILE *file = fopen(path, "r");

    if(file == NULL)
        return 0;

    while(fgets(buffer, MAX_NAME_LEN, file) != NULL)
    {
        if(buffer[strlen(buffer) -1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        if(!addName(buffer))
        {
            fclose(file);
            clearArchive();
            return 0;
        }
    }

    fclose(file);
    return 1;
}

static void writeNodesToFile(Node *node, FILE *file)
{
    if(node != NULL)
    {
        writeNodesToFile(node->left, file);
        fprintf(file, "%s\n", node->name);
        writeNodesToFile(node->right, file);
    }
}
// Speichert das Archiv zeilenweise in einer Textdatei. Gibt 1 bei Erfolg zurück.
int saveArchive(const char *path)
{
    FILE *file =fopen(path, "w");

    if(file == NULL)
        return 0;

    writeNodesToFile(root, file);

    fclose(file);

    return 1;
}