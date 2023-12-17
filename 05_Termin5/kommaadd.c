/*****************************************************************
 * Aufgabe 28_2_2 Addieren von deutschen Kommazahlen  15.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct kommazahl
{
    int vorkomma;
    float nachkomma;
    float kontrolle;
};
int main()
{
    struct kommazahl zahl;
    // Variablen definieren
    char eingabe[MAX] = "\0";
    // double kontrolle = 0;
    char teiler[] = ",\n\0", *vorkomma, *nachkomma, kontrolle[MAX] = "\0"; // Bedingungen für das Teilen des Arrays
    // Benutzerabfrage starten
    printf("Gib Deine Kommazahlen ein (Abschlussmit Leerzeile)\n");
    fgets(eingabe, MAX, stdin);
    zahl.vorkomma = 0; // 0 setzten sonst gab es Fehler
    // Wiederholen bis \n
    while (eingabe[0] != '\n')
    {
        vorkomma = strtok(eingabe, teiler); // Vorkommazahl abschneiden
        strcat(kontrolle, vorkomma);
        strcat(kontrolle, ".");                      // , durch . austauschen
        zahl.vorkomma += strtol(vorkomma, NULL, 10); // Vorkomma aufaddieren
        nachkomma = strtok(NULL, teiler);            // Nachkommazahl abschneiden
        if (strtol(nachkomma, NULL, 10))             // Nachkomma nur rechnen wenn etwas Eingegeben wurde
        {
            strcat(kontrolle, nachkomma);                // Kontrollzahl komplett zusammensetzen
            for (int i = strlen(nachkomma); i >= 0; i--) // In Nachkomma alles um 2 stellen schieben
                nachkomma[i + 2] = nachkomma[i];
            nachkomma[0] = '0';                        // 0 und . einfügen
            nachkomma[1] = '.';                        // sodass wir es verarbeiten können
            zahl.nachkomma += strtof(nachkomma, NULL); // Nachkomma aufaddieren
            if (zahl.nachkomma >= 1)                   // Vorgehen bei Übertrag
            {
                zahl.nachkomma--;
                zahl.vorkomma++;
            }
        }
        zahl.kontrolle += strtof(kontrolle, NULL); // Kontrollzahl rechnen
        strcpy(kontrolle, "\0");
        fgets(eingabe, MAX, stdin); // Nächste Eingabe
    }
    printf("\n%d,", zahl.vorkomma);
    // Hinzufügen der führenden Nullen (Warum geht das mit der for-schleife nicht)
    if ((int)(zahl.nachkomma * (float)1000000.0) < 100000)
        printf("%d", 0);
    if ((int)(zahl.nachkomma * (float)1000000.0) < 10000)
        printf("%d", 0);
    if ((int)(zahl.nachkomma * (float)1000000.0) < 1000)
        printf("%d", 0);
    if ((int)(zahl.nachkomma * (float)1000000.0) < 100)
        printf("%d", 0);
    if ((int)(zahl.nachkomma * (float)1000000.0) < 10)
        printf("%d", 0);
    // Ausgeben nachdem die Nullen wieder da sind
    printf("%d\t......(Kontrollwert %f)", (int)(zahl.nachkomma * (float)1000000.0), zahl.kontrolle);
    return 0;
}
// int nullen = 100000;
// for (int i = 0; i < 5; i++)
// {
//     if (((int)(zahl.nachkomma * 1000000.0)) < nullen)
//         printf("%d",0);
//     nullen = nullen / 10;
// }