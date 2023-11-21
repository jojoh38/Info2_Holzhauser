/***********************************************************
 * Aufgabe 25_6_4 Mischen von Farben           25.10.2023  *
 * Johannes Holzhauser und Maximilian Schmidt              *
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int umwandeln(char eingabe[]);
void eingeben(char eingabe[], char anzahl[]);

int main()
{
    // Variablen definieren
    int x = 0, y = 0;
    char eingabe[MAX] = "\0";
    char *ergebniss[][3] = {{"Gruen", "Gelb", "Blau"}, {"Gelb", "Rot", "Purpur"}, {"Blau", "Purpur", "Violett"}};
    // Benutzerabfrage Starten
    eingeben(eingabe, "Erste");
    x = umwandeln(eingabe);
    eingeben(eingabe, "Zweite");
    y = umwandeln(eingabe);
    printf("\n...... Die Mischfarbe ist dann %s", ergebniss[x][y]);
    return 0;
}
int umwandeln(char eingabe[])
{
    int koord = 0;
    if (!strcmp(eingabe, "Gruen"))
        koord = 0;
    if (!strcmp(eingabe, "Rot"))
        koord = 1;
    if (!strcmp(eingabe, "Violett"))
        koord = 2;
    return koord;
}
void eingeben(char eingabe[], char anzahl[])
{
    printf("%s Grundfarbe (Gruen Rot Violett):", anzahl);
    while (scanf("%10s", eingabe) != 1 || (strcmp(eingabe, "Violett") && strcmp(eingabe, "Rot") && strcmp(eingabe, "Gruen")))
    {
        printf("\n.....Unbekannte Grundfarbe %s (Neue Eingabe machen)\n", eingabe);
        printf("%s Grundfarbe (Gruen Rot Violett):", anzahl);
        fflush(stdin);
    }
}
