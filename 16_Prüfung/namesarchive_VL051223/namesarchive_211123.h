#ifndef NAMEARCHIVE211123_H
#define NAMEARCHIVE211123_H

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
int addNameDynArr(const char *name);
// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSortedDynArr(const char *name);
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeNameDynArr(const char *name);
// Sortiert die Namen im Archiv aufsteigend.
void sortNamesDynArr();
// Gibt die Namen zeilenweise aus.
void printNamesDynArr();
// Leert das Archiv
void clearArchiveDynArr();

#endif