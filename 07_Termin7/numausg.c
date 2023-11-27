#include <stdio.h>

int main(int argc, char *argv[]) {
    // Überprüfen, ob der Dateiname übergeben wurde
    if (argc != 2) {
        printf("Verwendung: %s <Dateiname>\n", argv[0]);
        return 1;  // Rückgabewert 1 für Fehler
    }

    // Datei öffnen
    FILE *datei = fopen(argv[1], "r");

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (datei == NULL) {
        perror("Fehler beim Öffnen der Datei");
        return 1;  // Rückgabewert 1 für Fehler
    }

    // Zeilennummer und Puffer für die Zeile
    int zeilennummer = 1;
    char zeile[256];  // Annahme: Eine Zeile hat maximal 255 Zeichen

    // Datei zeilenweise ausgeben
    while (fgets(zeile, sizeof(zeile), datei) != NULL) {
        // Ausgabe mit Zeilennummer
        printf("%d: %s", zeilennummer, zeile);
        zeilennummer++;
    }

    // Datei schließen
    fclose(datei);

    return 0;  // Erfolgreicher Programmabschluss
}
