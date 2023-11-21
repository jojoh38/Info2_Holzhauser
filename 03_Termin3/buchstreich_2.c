#include <stdio.h>
#include <string.h>
#define MAX 1000

void input(char *eingabe, char *zeichen, int *length);

int main()
{
    // Initiallisieren der Variablen
    int length = 0;
    char zeichen = '0';
    char eingabe[MAX];

    input(eingabe, &zeichen, &length); // Eingabe der Zeichenkette und des Charakters
    char *result = strchr(eingabe, zeichen); // Feststellen ob das Zeichen verfügbar wäre

    if (result != 0)
    {
        for (int i = 0; i <= length + 1; i++)
        {
            if (eingabe[i] == zeichen) // Überprüfen ob das Zeichen gleich dem eingeben ist
            {
                for (int k = i; k < strlen(eingabe) + 1; k++) // Shiften der Zeichen rechts davon um 1
                {

                    eingabe[k] = eingabe[k + 1];
                }
            }
        }
        printf("......Die neue Zeichenkette ist dann:\n %s", eingabe); // Ausgabe
    }
    else
        printf("Es gibt dieses Zeichen nicht in der Zeichenkette.");
    return 0;
}
void input(char *eingabe, char *zeichen, int *length)
{
    printf("Bitte geben Sie eine Zeichenkette (max.1000 Zeichen ein): ");
    if (fgets(eingabe, MAX + 1, stdin) != 0)
    {
        *length = strlen(eingabe);
        if (eingabe[*length - 1] == '\n')
        {
            eingabe[*length - 1] = '\0'; // oder eingabe[strcspn(eingabe, "\n")] = '\0' Sucht das \n und ersetzt es durch \0
        }
    }
    *length = strlen(eingabe);
    // while (getchar() != '\n'); //Wenn man mehr als 1000 eingibt dann passiert was? // while ((c = getchar()) != '\n' && c != EOF);
    printf("Geben Sie das zu loeschende Zeichen ein: "); // Eingabe des Charakters
    scanf("%1c", &*zeichen);
    getchar();
}