/************************************************************************
 * Aufgabe 30.1.2 Ausgeben einer Datei mit Zeilennumerierung 27.11.2023 *
 * Johannes Holzhauser und Maximilian Schmidt                           *
 ************************************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int zeilennummer = 1;
    char zeile[256];
    if (argc != 2) // Test auf korrekte Übergabe
    {
        printf("Verwendung: nummerausg.c <Dateiname>\n");
        return 0;
    }
    FILE *datei = fopen(argv[1], "r"); //Datei öffnen
    if (datei == NULL) 
    {
        printf("Fehler beim Öffnen der Datei");
        return 0;
    }
    while (fgets(zeile, sizeof(zeile), datei) != NULL)
    {
        printf("%d: %s", zeilennummer, zeile);
        zeilennummer++;
    }

    fclose(datei);

    return 0;
}
