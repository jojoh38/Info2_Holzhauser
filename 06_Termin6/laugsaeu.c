/*****************************************************************
 * Aufgabe 28_6_1 Mischtabelle aus der Chemie          20.11.2023*
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum saeuren //Aufruf der Struct mit enum, um Code lesbarer zu machen und Fehler zu vermeiden
{
    Salzsaeure,
    Schwefelsaeure,
    Salpetersaeure,
    Kohlensaeure,
    anzahl_saeuren
};
enum laugen
{
    Natronlauge,
    Kalilauge,
    Kalkwasser,
    anzahl_laugen
};

int main()
{
typedef const char angegeben; //Umbenennung mit Typedef, um Code lesbarer zu machen
angegeben *saeuren[anzahl_saeuren] = {"Salzsaere", "Schwefelsaeure", "Salpetersaeure", "Kohlensaeure"};
angegeben *laugen[anzahl_laugen] = {"Natronlauge", "Kalilauge", "Kalkwasser"};
angegeben *gemischt[][anzahl_saeuren] = {{"Natriumchlorid", "Natriumsulfat", "Natriumnitrat", "Natriumcarbonat"},{"Kaliumclorid", "Kaliumsulfat", "Kaliumnitrat", "Kaliumcarbonat"}, {"Calciumchlorid","Calciumsulfat", "Calciumnitrat", "Calciumcarbonat"}};
printf("\t   ||");
for (enum saeuren i = Salzsaeure; i < anzahl_saeuren; i++)
    printf("%16s|", saeuren[i]);
printf("\n-----------||----------------|----------------|----------------|----------------|\n");
for(enum laugen i = Natronlauge; i < anzahl_laugen; i++)
    {
        printf("%11s||",laugen[i]); 
        for (enum saeuren j = Salzsaeure;j < anzahl_saeuren; j++)
            printf("%16s|", gemischt[i][j]);
        printf("\n");
    }
}
