/*****************************************************************
 * Aufgabe 26.2 Rechnen mit Dualzahlen                27.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int eingabeueberpruefung(int stelle, char *argument[]);

int main(int argz, char *argp[])
{
    // Variablen anlegen
    int error = 0, zahl1 = 0, zahl2 = 0, ergebnis = 0, i = 0;
    int dual[33];
    if (argz < 4) // Überprüfen ob genug Argumente übergeben wurden 
    {
        printf("Richtiger Aufruf: dualrech <operand> <operator> <operand>\n\tErlaubte Operatoren sind: +, -, *, /, &, ^");
        return 0;
    }
    // Test ob die Argumente korrekt sind
    error = eingabeueberpruefung(1, argp);
    error = eingabeueberpruefung(2, argp);
    error = eingabeueberpruefung(3, argp);
    if (error != 0)//Programende bei Fehler
        return 0;
    //Umwandlung in Dezimal
    for (int i = 0; i < strlen(argp[1]); i++)
        zahl1 += ((int)argp[1][i] - 48) * pow(2, (strlen(argp[1]) - (i + 1)));
    for (int i = 0; i < strlen(argp[3]); i++)
        zahl2 += ((int)argp[3][i] - 48) * pow(2, (strlen(argp[3]) - (i + 1)));
    //Rechnen
    if (argp[2][0] == '+')
        ergebnis = zahl1 + zahl2;
    else if (argp[2][0] == '-')
        ergebnis = zahl1 - zahl2;
    else if (argp[2][0] == '*')
        ergebnis = zahl1 * zahl2;
    else if (argp[2][0] == '/')
        ergebnis = zahl1 / zahl2;
    else if (argp[2][0] == '&')
        ergebnis = zahl1 & zahl2;
    else if (argp[2][0] == '^')
        ergebnis = zahl1 ^ zahl2;
    //Ausgabe
    printf("%s %c %s =\n", argp[1], argp[2][0], argp[3]);
    dual[33] = ergebnis; //Zwischenspeichern
    //Vorgehen bei negativer Zahl
    if (ergebnis < 0)
    {
        ergebnis = (ergebnis - 1) - INT_MAX;
        printf("\n......1");
    }
    //Vorgehen bei positiver Zahl
    else if(ergebnis > 0)
        printf("\n......");
    //Falls Ergebnis genau 0
    else
        printf("\n......0");
    //Rückwandlung in Dual
    while (ergebnis > 0)
    {
        dual[i] = ergebnis % 2;
        ergebnis = ergebnis / 2;
        i++;
    }
    // Ausgabe
    for (int z = i - 1; z >= 0; z--)
        printf("%d", dual[z]);
    printf("\t(0x%x)", dual[33]);
    return 0;
}
int eingabeueberpruefung(int stelle, char *argument[])
{
    int error = 0;
    //Überprüfen auf korrekte Duallzahl
    if (stelle == 1 || stelle == 3)
    {
        for (int i = 0; i < (strlen(argument[stelle])); i++)
        {
            if (argument[stelle][i] != '1' && argument[stelle][i] != '0')
                error = 1;
        }
        if (error == 1)
            printf("\n.......%s ist keine erlaubte Dualzahl", argument[stelle]);
    }
    //Test auf richtigen Operator
    else if (argument[stelle][0] != '+' && argument[stelle][0] != '-' && argument[stelle][0] != '*' && argument[stelle][0] != '/' && argument[stelle][0] != '&' && argument[stelle][0] != '^')
    {
        printf("\n.......%s ist keine erlaubter Operator", argument[stelle]);
        error = 1;
    }
    return error;
}
// weiteres Beispiel:
//  .\dualrech.exe 110101 - 1110001111
//  Ergebnis:
//  1111 1111 1111 1111 1111 1100 1010 0110
//  F    F    F    F    F    C   A    6