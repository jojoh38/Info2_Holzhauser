/******************************************************************
 * Aufgabe 25_4_1 Streichen eines Zeichens aus String 19.10.2023  *
 * Johannes Holzhauser und Maximilian Schmidt                     *
 *****************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    // Variablen definieren
    char text[MAX];
    char teiler[] = "\0"; // Bedingungen für das Teilen des Arrays
    char *token;
    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    fgets(text, MAX, stdin); // String einlesen
    printf("\nGeben Sie das zu loeschende Zeichen ein:");
    fgets(teiler, 2, stdin);
    printf("\n......Die neue Zeichenkette ist dann:\n");
    token = strtok(text, teiler); // Erste teilung
    while (token != NULL)
    {
        printf("%s", token);
        token = strtok(NULL, teiler); // Nächste Unterteilungen
    }
}