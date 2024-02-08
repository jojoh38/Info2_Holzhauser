#ifndef NAMEARCHIVE141123_H
#define NAMEARCHIVE141123_H

// Maximale Namenslänge
#define MAX_NAME_LEN 10

// Maximale Anzahl an Namen
#define MAX_NAMES 100000

// Fügt einen Namen hinzu. Im Fehlerfall (Archiv ist voll) soll 0, ansonsten 1 zurückgegeben werden.
// Ist der angegebene Name länger als die zulässige Namenslänge, wird der Name abgeschnitten hinzugefügt. Rückgabe ist dann 1.
int addNameStatArr(const char *name);
// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSortedStatArr(const char *name);
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeNameStatArr(const char *name);
// Sortiert die Namen im Archiv aufsteigend.
void sortNamesStatArr();
// Gibt die Namen zeilenweise aus.
void printNamesStatArr();

#endif