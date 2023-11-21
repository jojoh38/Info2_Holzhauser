/***********************************************************
 * Aufgabe 28_5_2 Addition von zwei Zeiten      16.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt              *
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
// Aufrufen der Funktionen
struct zeit eingabe(int i);
unsigned long zeit_in_sek(struct zeit z);
struct zeit sek_in_zeit(unsigned long sek);

struct zeit //Initialisierung der Struktur
{
    int tag; int std; int min; int sek;
};
 
int main ()
{
    struct zeit zeit1;
    struct zeit zeit2;
    unsigned int gesamtsek = 0;
    zeit1 = eingabe(1); 
    zeit2 = eingabe(2); 
    gesamtsek = zeit_in_sek(zeit1) + zeit_in_sek(zeit2); // Addieren der Sekunden
    zeit2 = sek_in_zeit(gesamtsek); //Speichern der Zeit in Zeit2
    printf("\n....... = %d Tage, %d:%d.%d;\t%d Gesamtsekunden",zeit2.tag, zeit2.std, zeit2.min, zeit2.sek,gesamtsek); 
}
 
struct zeit eingabe(int i)
{
    struct zeit z;
    printf("Gib %d. Zeit ein: (tt.hh.mm.ss):",i); 
    while (scanf("%d.%d.%d.%d", &z.tag, &z.std, &z.min, &z.sek) < 4 || z.std > 23 || z.min > 59 || z.sek > 59) //Ueberpruefung der Eingabe 
    {
        printf("Falsche Eingabe!\n");
        fflush(stdin); 
    }
    return z;
}
unsigned long zeit_in_sek(struct zeit z) //Funktion Umrechnung Zeit in Sekunden
{
    unsigned long sekunden = 0;
    sekunden += z.tag * 86400;
    sekunden += z.std * 3600;
    sekunden += z.min * 60;
    sekunden += z.sek;
    return sekunden;
}
struct zeit sek_in_zeit(unsigned long sek) //Funktion Umrechnung Sekunden in Zeit
{
    struct zeit z;
    z.tag = sek / 86400;
    z.std = (sek % 86400) / 3600;
    z.min = (sek % 3600) / 60;
    z.sek = sek % 60;
    return z;
}
