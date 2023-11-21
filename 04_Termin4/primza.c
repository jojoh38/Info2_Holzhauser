/****************************************************
 * Aufgabe 27_3 Berechnen von Primzahlen 09.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt       *
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
 
void sieb(int prim[], int n); 
int eingabe();
 
int main()
{
    int *primzahlen;
    int anzahl = 0;
    primzahlen = (int *)malloc(100 * sizeof(int)); // Primzahlen in dynamischem Speicher
    anzahl = eingabe();
    while (anzahl != 0)
    {
        if (anzahl > 100) // Unterscheidung in ueber 100 und unter 100 
            primzahlen = (int *)realloc(primzahlen, anzahl * sizeof(int)); // Überschreibung der Groeße des Speichers
        sieb(primzahlen, anzahl); 
        anzahl = eingabe();
    }
}
void sieb(int prim[], int n)
{
    int start = 2, a = 0, i = 0; // start = 2, weil bei zwei gestartet werden muss
    for (i = 0; i <= n; i++)     // Array füllen
        prim[i] = i;
    do // Sieb Starten
    {
        i = start + 1; // Beginnen mit der nächsthöheren Zahl zu "start"
        while (i <= n) // Löschen der vielfachen von Start
        {
            if (prim[i] % start == 0) // Löschen bei Vielfachen
                prim[i] = 0;
            else if (prim[i] % start != 0) // Unberührt bei keinem Vielfachen
                prim[i] = prim[i];
            i++;
        }
        if (prim[start] != 0) // Ausgabe wenn die Stelle noch nicht gelöscht wurde
        {
            printf("%-7d", prim[start]); // Augabe mit Formatierung
            start++;
            a++; // Zählvariable für das "\n" erhöhen
            if ((a % 10) == 0) // Absatz nach jeder 10ten Ausgabe
                printf("\n");
        }
        else if (prim[start] == 0) // Wechseln zur nächsthöheren ohne Ausgabe
            start++;
    } while (start <= n);
}
int eingabe()
{
    int eingegeben = 0;
    printf("\nBis wohin sollen die Primzahlen berechnet werden (Ende = 0)? ");
    while ((scanf("%d", &eingegeben) != 1) || (eingegeben < 0) || (eingegeben == 1)) // Eingabeueberpruefung
    {
        printf("\nFalsche Eingabe! Primzahlen beginnen bei 2 ");
        fflush(stdin);
    }
    return eingegeben;
}
