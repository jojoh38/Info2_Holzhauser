/******************************************************************
 * Aufgabe 25.4.2 Ersetzen von Wörtern in einem String 21.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                     *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void eingabe(char text[]);

int main()
{
    // Variablen und Strings definieren
    char original[MAX];        // String für die Eingabe
    char zusammen[MAX] = "\0"; // Neu zusammengesetzer String
    char zuersetzen[MAX];
    char ersatz[MAX];
    char *teiler = " \0"; // Bedingungen für das Teilen des Arrays
    char *token;          // Token anlegen

    printf("Geben Sie einen String ein:\n"); // Originalstring einlesen starten
    eingabe(original);
    do
    {
        fflush(stdin);
        printf("\nWelchses Wort soll ersetzt werden:");
        eingabe(zuersetzen);
        while (strstr(original, zuersetzen) == 0)
        {
            printf("\nFalsche Eingabe!\n");
            eingabe(zuersetzen);
        }
        printf("\nDurch welches Wort soll dieses ersetzt werden:");
        eingabe(ersatz);
        token = strtok(original, teiler); // Erste Teilung
        while (token != NULL)
        {
            if (strncmp(token, zuersetzen, strlen(zuersetzen)) != 0) // Vorgehen bei Ungleich
            {
                strcat(zusammen, token);
                strcat(zusammen, " "); // Wiederanfügen des Leerzeichen
            }
            else if (strncmp(token, zuersetzen, strlen(zuersetzen)) == 0) // Vorgehen bei Gleich
            {
                strcat(zusammen, ersatz);
                strcat(zusammen, " "); // Wiederanfügen des Leerzeichen
            }
            token = strtok(NULL, teiler); // Teilung für den nächsten Durchlauf
        }
        printf("\n........Neuer String:\n%s\nNoch eine Ersetzung (j/n):", zusammen);
        strcpy(original, zusammen); // Herstellen des neuen Originalstrings
        strcpy(zusammen, "");       // Rücksetzten des zusammengefügten Strings
    } while (getchar() == 'j');

    return 0;
}
void eingabe(char text[])
{
    int c = 0;
    fgets(text, MAX, stdin);
    c = strlen(text);
    text[c - 1] = '\0'; // \n durch \0 ersetzen
}
