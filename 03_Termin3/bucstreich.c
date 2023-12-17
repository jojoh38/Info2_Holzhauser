/******************************************************************
 * Aufgabe 25_4_1 Streichen eines Zeichens aus String 19.10.2023  *
 * Johannes Holzhauser und Maximilian Schmidt                     *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void loeschen(char text[], char neu[], char loeschen);
char eingabe(char text[]);
void ausgeben(char text[]);

int main()
{
    // Variablen definieren
    char text[MAX];
    char neuertext[MAX];
    char loesche = '0';
    // Benutzereingabe starten
    loesche = eingabe(text);
    loeschen(text, neuertext, loesche);
    // Neuen Text ausgeben
    ausgeben(neuertext);
}

void loeschen(char text[], char neu[], char loeschen)
{
    int i = 0, a = 0;       // Zwei Zählvariablen um in den Strings variabel hochzuzählen
    while (text[a] != '\n') // Durchlaufen des Eingabe Strings bis zum Enter
    {
        if (text[a] != loeschen) // Übernahme des Eingabestrings fall das zu Löschende Zeichen nicht vorkommt
        {
            neu[i] = text[a];
            i++;
            a++;
        }
        else // Ansonsten überspringen der Stelle
            a++;
    }
    neu[i] = '\0'; // Ende des neuen Strings durch '\0' markieren
}
char eingabe(char text[])
{
    char loesche = '0';
    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    fgets(text, MAX, stdin); // String einlesen

    printf("\nGeben Sie das zu loeschende Zeichen ein:");
    loesche = getchar(); // Zu löschendes Zeichen einlesen
    printf("\n......Die neue Zeichenkette ist dann:\n");

    return loesche;
}
void ausgeben(char text[])
{
    int i = 0;
    while (text[i] != '\0') // Neuen String bis zum Enter ausgeben
    {
        printf("%c", text[i]);
        i++;
    }
}