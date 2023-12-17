/*************************************************
 * Aufgabe 22_5_1 Binomialkoeffizient 18.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt    *
 *************************************************/

#include <stdio.h>
#include <stdlib.h>

// Funktionen definieren
int eingabe(int n);
int binom(int n, int k);

int main()
{
    // Variablen initialisieren
    int binkof = 0, k = 0, n = 0;
    // Benutzerabfrage starten
    printf("Wieviele Positionen:");
    n = eingabe(0);
    printf("\nWieviele Elemente (muss <= %d sein):", n);
    k = eingabe(n); // Uebergabe von n für die Eingabeueberpruefung
    // Funktionsaufruf
    binkof = binom(n, k);
    // Formatierte Ausgabe
    printf("\n /%5d\\", n);
    printf("\n|\t| = %d", binkof);
    printf("\n \\%5d/", k);

    return 0;
}

int eingabe(int n)
{
    // Variable initialisieren
    int eingabe = 0;
    while ((scanf("%d", &eingabe)) != 1 || eingabe < 0 || ((eingabe > n) && (n != 0))) // Eingabeueberpruefung
    {
        printf("\nFalsche Eingabe!\nKeine Buchstaben und keine negativen oder nicht-ganzen Zahlen!");
        fflush(stdin);
    }
    return eingabe;
}

// Funktion zur Berechnung des Binomialkoeffizienten
int binom(int n, int k)
{
    // Variable initialisieren
    int bin = 0;
    // Umsetzten der Funktionsvorschrift
    if (k == 0 || k == n)
        return 1;
    else
        bin = binom(n - 1, k) + binom(n - 1, k - 1);
    return bin;
}