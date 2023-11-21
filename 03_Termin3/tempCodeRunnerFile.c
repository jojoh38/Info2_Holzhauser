#include <stdio.h>

// #define MAX 13

// int auswahl(int wahl);
// void datumzutagesnr(int array[], int tage[][MAX], int reihen);
// void tagesnrzudatum(int array[], int tage[][MAX], int reihen);
// int schaltjahr(int jahr);

// int main()
// {
//     int gewaehlt = 0;
//     int datum[MAX];
//     int monat_tage[][MAX] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 31}};
    
//     gewaehlt = auswahl(gewaehlt);
//     while (gewaehlt != 0)
//     {
//         if (gewaehlt == 1)
//             tagesnrzudatum(datum, monat_tage, MAX);
//         else
//             datumzutagesnr(datum, monat_tage, MAX);
//         gewaehlt = auswahl(gewaehlt);
//     }
// }
// int auswahl(int wahl)
// {
//     printf("0\tEnde\n1\tTagesnummer zu einem Datum bestimmen\n2\tDatum zu einer Tagesnummer\n\nDein Wahl:");
//     while (scanf("%d", &wahl) != 1 || wahl > 2)
//     {
//         printf("Falsche Eingabe!");
//         fflush(stdin);
//     }
//     return wahl;
// }
// void datumzutagesnr(int array[], int tage[][MAX], int reihen)
// {
//     int schalt1 = 0, zahl = 0,i = 0;
//     printf("\n\nGib Tagesnummer und Jahr (nr,jahr) ein:");
//     while (scanf("%d,%4d", &array[0], &array[2]) < 2 || array[0] > 365)
//     {
//         printf("\nFalsche Eingabe!\n");
//         fflush(stdin);
//     }
//     schalt1 = schaltjahr(array[2]);
//     for (zahl = 0; zahl < array[0]; zahl += tage[schalt1][i])
//         i++;
//     printf(".... %3d. Tag im Jahr = %2d.%2d.%4d\n\n", array[0], (array[0] - zahl + tage[schalt1][i]), i, array[2]);
// }
// void tagesnrzudatum(int array[], int tage[][MAX], int reihen)
// {
//     int schalt2 = 0, zahl = 0;
//     printf("\n\nGib dein Datum (tt.mm.jjjj) ein:");
//     do
//     {
//         while (scanf("%02d.%02d.%4d", &array[0], &array[1], &array[2]) < 3 || array[1] > 12 || array[2] < 1)
//         {
//             printf("\nFalsche Eingabe!\n");
//             fflush(stdin);
//         }
//         schalt2 = schaltjahr(array[2]);
//         if (array[0] > tage[schalt2][array[1]])
//             printf("\nFalsche Eingabe!\n");
//     } while (array[0] > tage[schalt2][array[1]]);
//     for (int i = 1; i <= (array[1] - 1); i++)
//         zahl += tage[schalt2][i];
//     zahl += array[0];
//     printf("\n.... %02d.%02d.%4d = %d. Tag im Jahr\n\n", array[0], array[1], array[2], zahl);
// }
// int schaltjahr(int jahr)
// {
//     int ergebnis = 0;
//     if ((jahr % 400 == 0 && jahr % 100 > 0) || (jahr % 4 == 0))
//         ergebnis = 1;
//     else
//         ergebnis = 0;
//     return ergebnis;
// }
