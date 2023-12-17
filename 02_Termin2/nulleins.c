/**********************************************************
 * Aufgabe 25.3.2 Folgen von Nullen und Einsen 18.10.2023 *
 * Johannes Holzhauser und Maximilian Schmidt             *
 **********************************************************/
//Biblitheken einfügen
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definieren der Konstanten
#define MAX 1000
#define WERTEBEREICH 2
 //Funktionen definieren 
void komprimieren(int eins[], int zwei[], int laenge);
int eingabe();
void arrayausgabe(int array[], int laenge);
 
int main()
{
    //Definieren von Variablen und Arrays
    int laenge = 0;
    int ursprung[MAX];
    int kompression[MAX / 2];
    //Zahlen von 0-1 generieren
    srand(time(0));
    //Aufruf der Eingabefunktion
    laenge = eingabe();
    for (int i = 0; i < (laenge); i++)
        ursprung[i] = (rand() % (WERTEBEREICH));
    //Aufruf der Ausgabefunktion
    arrayausgabe(ursprung, laenge);
    while (laenge > 1)
    {
        //Überprüfen , ob Zahlen gerade sind
        if (laenge % 2 != 0)
            laenge++;
        komprimieren(ursprung, kompression, laenge);
        laenge = laenge / 2;
        arrayausgabe(ursprung, laenge);
    }
}
void komprimieren(int eins[], int zwei[], int laenge)
{
    //Variabeln definieren
    int neu = 0;
    //Umsetzung der Aufgabe
    for (int i = 0; i <= laenge; i++)
    {
        if (eins[i] == eins[i + 1])
            zwei[neu] = 0;
        else if (eins[i] != eins[i + 1])
            zwei[neu] = 1;
        i++;
        neu++;
    }
    for (int a = 0; a < (laenge / 2); a++)
        eins[a] = zwei[a];
    for (int b = (laenge / 2); b < MAX; b++)
        eins[b] = 2;
}
int eingabe()
{
    //Eingabe inklusive Eingabeüberprüfung
    int eingabe = 0;
    printf("Laenge der 0/1-Folge (max. 1000):");
    while ((scanf("%d", &eingabe)) != 1 || eingabe < 0 || eingabe > MAX)
    {
        printf("\nFalsche Eingabe!\nKeine Buchstaben und keine negativen, nicht-ganzen Zahlen oder Zahlen groeser 1000!");
        fflush(stdin);
    }
    return eingabe;
}
void arrayausgabe(int array[], int laenge)
{
    //Ausgabe des Arrays
    for (int a = 0; a < laenge; a++)
        printf(" %d", array[a]);
    printf("\n");
}
