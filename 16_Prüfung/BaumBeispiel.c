#include <stdio.h>
#include <stdlib.h>

// Definition eines Baumknotenelements
struct zahlen {
    int zahl;
    struct zahlen *links;
    struct zahlen *rechts;
};

typedef struct zahlen NODE; // Alias für struct zahlen

// Funktion zur Berechnung der Summe aller int-Werte im Baum
int addiere(NODE *root) {
    if (root) // Basisfall: Wenn der Knoten NULL ist, ist die Summe 0
        return root->zahl + addiere(root->links) + addiere(root->rechts);
    return 0;
}
int blattaddiere(NODE *root) {
    int summe = 0;
    if ((root->links)&&(root->rechts))
        return blattaddiere((root->links))+blattaddiere((root->rechts));
    else if ((root->links == NULL) && !(root->rechts == NULL)) 
        return blattaddiere((root->rechts));
    else if ((root->rechts == NULL) && !(root->links == NULL))
        return blattaddiere((root->links));
    else
    {
        summe += root->zahl;
        return root->zahl;
    }
    return summe;
}
int addiereMitTiefe(struct zahlen *wurzel, int tiefe)
{
    int summe = 0;
    if(wurzel != NULL)
    {
        summe += addiereMitTiefe(wurzel->links,tiefe+1);
        summe += wurzel->zahl * tiefe;
        summe += addiereMitTiefe(wurzel->rechts,tiefe+1);
    }
    return summe;
}
// Funktion zum Erstellen des Beispielbaums
NODE *erstelleBeispielbaum() {
    NODE *root = (NODE *)malloc(sizeof(NODE));
    root->zahl = 5;
    
    root->links = (NODE *)malloc(sizeof(NODE));
    root->links->zahl = 3;
    root->links->links = (NODE *)malloc(sizeof(NODE));
    root->links->links->zahl = 2;
    root->links->links->links = NULL;
    root->links->links->rechts = NULL;
    root->links->rechts = (NODE *)malloc(sizeof(NODE));
    root->links->rechts->zahl = 4;
    root->links->rechts->links = (NODE *)malloc(sizeof(NODE));
    root->links->rechts->links->zahl = 1;
    root->links->rechts->links->links = NULL;
    root->links->rechts->links->rechts = NULL;
    root->links->rechts->rechts = NULL;
    
    root->rechts = (NODE *)malloc(sizeof(NODE));
    root->rechts->zahl = 8;
    root->rechts->links = (NODE *)malloc(sizeof(NODE));
    root->rechts->links->zahl = 6;
    root->rechts->links->links = NULL;
    root->rechts->links->rechts = NULL;
    root->rechts->rechts = (NODE *)malloc(sizeof(NODE));
    root->rechts->rechts->zahl = 10;
    root->rechts->rechts->links = (NODE *)malloc(sizeof(NODE));
    root->rechts->rechts->links->zahl = 9;
    root->rechts->rechts->links->links = NULL;
    root->rechts->rechts->links->rechts = (NODE *)malloc(sizeof(NODE));
    root->rechts->rechts->links->rechts->zahl = 7;
    root->rechts->rechts->links->rechts->links = NULL;
    root->rechts->rechts->links->rechts->rechts = NULL;
    root->rechts->rechts->rechts = (NODE *)malloc(sizeof(NODE));
    root->rechts->rechts->rechts->zahl = 12;
    root->rechts->rechts->rechts->links = NULL;
    root->rechts->rechts->rechts->rechts = NULL;
    
    return root;
}

// Freigabe des Speichers für den Baum
void baumFreigeben(NODE *root) {
    if (root == NULL)
        return;
    baumFreigeben(root->links);
    baumFreigeben(root->rechts);
    free(root);
}

// Beispiel für die Verwendung
int main() {
    NODE *root = erstelleBeispielbaum();
    int summe = addiere(root);
    printf("Summe aller Werte im Baum: %d\n", summe);
    int blattsumme = blattaddiere(root);
    printf("Summe aller Werte der Blatt-Knoten im Baum: %d\n", blattsumme);
    int tiefesumme = addiereMitTiefe(root,1);
    printf("Summe aller Werte der Knoten im Baum mit Tiefe: %d\n",tiefesumme);
    baumFreigeben(root);
    return 0;
}
