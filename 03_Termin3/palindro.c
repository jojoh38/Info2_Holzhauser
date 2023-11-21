/*************************************************************
 * Aufgabe 25.4.3 Palindrome in einem Text finden 21.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                *
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main()
{
    // Variablen definieren
    char string[MAX];     // String für die Eingabe
    char *teiler = " \n"; // Bedingungen für das Teilen des Arrays
    char *token;          // Token anlegen
    char ende[] = "STOP"; // Endbedingung festlegen
    int u = 0, eins = 0, zwei = 0, b = 0, n = 4;
    // Benutzerabfrage starten
    printf("Geben Sie einen Text Satz fuer Satzt ein!(Ende mit STOP)\n");
    while (strncmp(string, ende, n) != 0) // Wiederholen bis STOP
    {
        fgets(string, MAX, stdin);      // Einlesen des Satzes
        token = strtok(string, teiler); // Erste teilung
        while (token != NULL)
        {
            u = 0;                          // Zählvariable für den Abgleich auf Palindrome
            b = strlen(token);              // Länge des einzelnen Tokens auf int casten und in b speichern
            for (size_t i = 1; i <= b; i++) // Eigentliche überprüfung
            {
                eins = token[i - 1];                                                  // Cast auf int um den dezimalwert des ASCII Zeichens zu erhalten
                zwei = token[b - i];                                                  // Cast auf int um den dezimalwert des ASCII Zeichens zu erhalten
                if ((eins == zwei) || ((eins + 32) == zwei) || ((eins - 32) == zwei)) // Vergleich auch mit Groß und Kleinschreibung
                    u++;
            }
            if (b == u) // Augabe bei Gleichheit
                printf("........%s\n", token);
            token = strtok(NULL, teiler);//Nächste Unterteilung
        }
        if (strncmp(string, ende, n) != 0) // Ausgabe nur wenn nicht STOP eingegeben wurde
            printf("\nAndere Beispiele sind:");
    }
    return 0;
}