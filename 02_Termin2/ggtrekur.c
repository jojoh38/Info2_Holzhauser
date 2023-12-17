/********************************************************
 * Aufgabe 22_5_2 Größter gemeinsamer Teiler 17.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt           *
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximale eingabe an Zahlen die ueberprueft werden

// Funktionen definieren
int eingabe(int *anzahl);
int teiler(int m, int n);

int main()
{
    // Var,iablen initialisieren
    int anzahl = 0, aktuell = 1, ggt = 0;
    int einlese[MAX];
    // Benutzereingabe starten
    printf("Gib nicht-negative ganze zahlen ein (Ende = 0)\n");
    while ((aktuell != 0) && (anzahl <= (MAX - 1))) // Beenden bei über 100 Zahlen oder der eingabe 0
    {
        anzahl++;
        aktuell = eingabe(&anzahl);
        einlese[anzahl - 1] = aktuell;
    }
    // Aufruf der Rekursiven Funktion mir allen Zahlen des Arrays nacheinander
    for (int i = 0; i < anzahl; i++)
    {
        ggt = teiler(ggt, einlese[i]); // Die Funktion finden den ersten gemeinsamen Teiler und Startet mit diesem und der nächsten Zahl im Arry neu
    }
    // Ausgabe
    printf("=====> ggt = %d", ggt);

    return 0;
}

int eingabe(int *anzahl)
{
    // Variable initialisieren
    int eingabe = 0;
    printf("%d. Zahl:", *anzahl);
    while ((scanf("%d", &eingabe)) != 1 || eingabe < 0) // Eingabeüberprüfung
    {
        printf("\nFalsche Eingabe!\nKeine Buchstaben und keine negativen oder nicht-ganzen Zahlen!");
        fflush(stdin);
    }
    return eingabe;
}

int teiler(int n, int m)
{
    // Umsetzten der Funktionsvorschrift
    if (m == 0)
        return n;
    else
        return teiler(m, n % m);
}