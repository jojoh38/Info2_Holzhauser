/**********************************************************************\
* Kurzbeschreibung:
* queue.h - realisiert eine Queue (Warteschlange) als verkettete Liste
*
* Datum:     Autor:
* 25.11.2023 Johannes Holzhauser und Maximilian Schmidt
*
\**********************************************************************/
 
/*--- #includes ------------------------------------------------------*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
/*--- #defines -------------------------------------------------------*/
#define SPEICHER sizeof(List)
/*--- Datentypen (typedef) -------------------------------------------*/
/*--- Prototypen globaler Funktionen ---------------------------------*/
 
typedef struct liste {
	int nummer;
	struct liste *naechste;
}List;
 
static List *anfang = NULL;
static List *ende = NULL;
 
/*--------------------------------------------------------------------*\
* Einfuegen in Liste
* Parameter:
*    zahl  fügt die übergebene Zahl 'zahl' am Ende der Liste ein
* Return Wert:
*    TRUE  wenn noch genug Speicherplatz vorhanden
*    FALSE wenn kein Speicherplatz mehr allokiert werden konnte
* Hinweis:
* - dynamische Verwaltung von Speicher muss mit malloc() und free()
*   durchgeführt werden; dynamische Arrays sind nicht erlaubt !!!
*--------------------------------------------------------------------*/
Bool put(int zahl)
{
	List *neu;//Struct für die aktuelle Stelle anlegen
	neu = malloc(SPEICHER); // Speicher reservieren 
	if (neu == NULL)
		return FALSE;
	neu->nummer = zahl; // zahl in die Structure schreiben
	neu->naechste = NULL;// Zeiger auf die nächste Stuctur auf 0 setzen
 
	if (anfang == NULL)  // Erstellen des Anfangzeigers
		anfang = neu;
	else                // Ab dem zweiten Aufruf adresse von neu in ende schreiben 
		ende->naechste = neu;
	ende = neu;
 
	return TRUE;
}
 
 
/*--------------------------------------------------------------------*\
* Auslesen aus Liste
* Parameter:
*    keine
* Return Wert:
*    Zahl am Anfang der Liste oder aber QLEER, wenn Liste leer ist.
*--------------------------------------------------------------------*/
int get(void)
{
	if (isEmpty())
		return QLEER;
	int wert;
	List *zeiger;
	zeiger = anfang;     // zeiger zeigt auf Anfang von Array
	anfang = anfang->naechste; // Neuer Anfang des Arrays um eine Struct weiter schieben
	if (anfang == NULL)
		ende = NULL;
	wert = zeiger->nummer;   // hier wurde die erste Zahl des Arrays abgelegt (hier liegt die erste Struct)
	free(zeiger);            // Speicher der ersten Struct wieder freigeben
	return wert;
}
 
 
/*--------------------------------------------------------------------*\
* Pruefen der Liste
* Parameter:
*    keine
* Return Wert:
*    liefert TRUE, wenn Queue leer ist, sonst FALSE
*--------------------------------------------------------------------*/
Bool isEmpty(void)
{
	return (anfang == NULL && ende == NULL);
}