/*****************************************************************
 * Aufgabe 26.2 Rechnen mit Dualzahlen                27.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                    *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int eingabeueberpruefung(int stelle, char *argument[]);

int main(int argz, char *argp[])
{
    int error = 0, zahl1 = 0, zahl2 = 0, ergebnis = 0, i = 0;
    int dual[33];
    if (argz < 4)
    {
        printf("Richtiger Aufruf: dualrech <operand> <operator> <operand>\n\tErlaubte Operatoren sind: +, -, *, /, &, ^");
        return 0;
    }
    error = eingabeueberpruefung(1, argp);
    error = eingabeueberpruefung(2, argp);
    error = eingabeueberpruefung(3, argp);
    if (error != 0)
        return 0;
    for (int i = 0; i < strlen(argp[1]); i++)
        zahl1 += ((int)argp[1][i] - 48) * pow(2, (strlen(argp[1]) - (i + 1)));
    for (int i = 0; i < strlen(argp[3]); i++)
        zahl2 += ((int)argp[3][i] - 48) * pow(2, (strlen(argp[3]) - (i + 1)));
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
    printf("%s %c %s =\n",argp[1],argp[2][0],argp[3]);
    if(ergebnis < 0)
    {
        ergebnis = -ergebnis;
        printf("\n......1");
    }
    else
        printf("\n......");
    dual[33] = ergebnis;
    while (ergebnis > 0)
    {
        dual[i] = ergebnis % 2;
        ergebnis = ergebnis / 2;
        i++;
    }
    for (int z = i - 1; z >= 0; z--)
        printf("%d", dual[z]);
    printf("\t(0x%x)",dual[33]);
    return 0;
}

int eingabeueberpruefung(int stelle, char *argument[])
{
    int error = 0;
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
    else if (argument[stelle][0] != '+' && argument[stelle][0] != '-' && argument[stelle][0] != '*' && argument[stelle][0] != '/' && argument[stelle][0] != '&' && argument[stelle][0] != '^')
    {
        printf("\n.......%s ist keine erlaubter Operator", argument[stelle]);
        error = 1;
    }
    return error;
}