/****************************************************************
 * Aufgabe 25_5_3 Tagesnummer zu Datum und umgekehrt 23.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                   *
 ****************************************************************/

#include <stdio.h>
// Definition der maximalen Größe für Arrays
#define MAX 13
// Funktionsdeklarationen
int auswahl(int wahl);
void datumzutagesnr(int array[], int tage[][MAX], int reihen);
void tagesnrzudatum(int array[], int tage[][MAX], int reihen);
int schaltjahr(int jahr);

int main()
{
    // Initialisierung der Benutzerauswahl und Datum-Array
    int gewaehlt = 0;
    int datum[MAX];
    // Array für die Anzahl der Tage in jedem Monat für Schaltjahre und Nicht-Schaltjahre
    int monat_tage[][MAX] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 31}};
    // Benutzerauswahl abfragen
    gewaehlt = auswahl(gewaehlt);
    // Schleife für das Hauptmenü des Programms
    while (gewaehlt != 0)
    {
        // Abhängig von der Benutzerauswahl die entsprechende Funktion aufrufen
        if (gewaehlt == 1)
            tagesnrzudatum(datum, monat_tage, MAX);
        else
            datumzutagesnr(datum, monat_tage, MAX);       
        // Benutzerauswahl erneut abfragen
        gewaehlt = auswahl(gewaehlt);
    }
}
// Funktion zur Benutzerauswahl
int auswahl(int wahl)
{
    // Benutzerauswahl anzeigen
    printf("0\tEnde\n1\tTagesnummer zu einem Datum bestimmen\n2\tDatum zu einer Tagesnummer\n\nDein Wahl:");
    // Schleife für die Benutzereingabe mit Überprüfung auf Gültigkeit
    while (scanf("%d", &wahl) != 1 || wahl > 2)
    {
        printf("Falsche Eingabe!");
        fflush(stdin);
    }
    // Rückgabe der Benutzerauswahl
    return wahl;
}
// Funktion zur Umrechnung von Datum zu Tagesnummer
void datumzutagesnr(int array[], int tage[][MAX], int reihen)
{
    int schalt1 = 0, zahl = 0, i = 0;
    // Benutzereingabe für Tagesnummer und Jahr
    printf("\n\nGib Tagesnummer und Jahr (nr,jahr) ein:");
    // Schleife für die Benutzereingabe mit Überprüfung auf Gültigkeit
    while (scanf("%d,%4d", &array[0], &array[2]) < 2 || array[0] > 365)
    {
        printf("\nFalsche Eingabe!\n");
        fflush(stdin);
    }
    // Überprüfen, ob das Jahr ein Schaltjahr ist
    schalt1 = schaltjahr(array[2]);
    // Berechnung der Tagesnummer in Abhängigkeit von Schaltjahr und Monatslängen
    for (zahl = 0; zahl < array[0]; zahl += tage[schalt1][i])
        i++;
    // Ausgabe des Ergebnisses
    printf(".... %3d. Tag im Jahr = %2d.%2d.%4d\n\n", array[0], (array[0] - zahl + tage[schalt1][i]), i, array[2]);
}
// Funktion zur Umrechnung von Tagesnummer zu Datum
void tagesnrzudatum(int array[], int tage[][MAX], int reihen)
{
    int schalt2 = 0, zahl = 0;
    // Benutzereingabe für das Datum
    printf("\n\nGib dein Datum (tt.mm.jjjj) ein:");
    // Schleife für die Benutzereingabe mit Überprüfung auf Gültigkeit
    do
    {
        while (scanf("%02d.%02d.%4d", &array[0], &array[1], &array[2]) < 3 || array[1] > 12 || array[2] < 1)
        {
            printf("\nFalsche Eingabe!\n");
            fflush(stdin);
        }
        // Überprüfen, ob der Tag im Monat gültig ist
        schalt2 = schaltjahr(array[2]);
        if (array[0] > tage[schalt2][array[1]])
            printf("\nFalsche Eingabe!\n");
    } while (array[0] > tage[schalt2][array[1]]);
    // Berechnung der Tagesnummer in Abhängigkeit von Schaltjahr und Monatslängen
    for (int i = 1; i <= (array[1] - 1); i++)
        zahl += tage[schalt2][i];
    zahl += array[0];
    // Ausgabe des Ergebnisses
    printf("\n.... %02d.%02d.%4d = %d. Tag im Jahr\n\n", array[0], array[1], array[2], zahl);
}
// Funktion zur Überprüfung, ob ein Jahr ein Schaltjahr ist
int schaltjahr(int jahr)
{
    int ergebnis = 0;
    // Überprüfen der Schaltjahrregeln
    if ((jahr % 400 == 0 && jahr % 100 > 0) || (jahr % 4 == 0))
        ergebnis = 1;
    else
        ergebnis = 0;
    // Rückgabe des Ergebnisses
    return ergebnis;
}
