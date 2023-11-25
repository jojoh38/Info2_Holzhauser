/**********************************************************************\
* Kurzbeschreibung:
* queue.c - realisiert eine Queue (Warteschlange)
*
* Datum:     Autor:
*
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/
static int liste[100];
static int anzahl = 0;
/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
 * Einfuegen in Liste
 * Parameter:
 *    zahl  fügt die übergebene Zahl 'zahl' am Ende der Liste ein
 * Return Wert:
 *    TRUE  wenn noch genug Speicherplatz vorhanden
 *    FALSE wenn kein Speicherplatz mehr allokiert werden konnte
 *--------------------------------------------------------------------*/
Bool put(int zahl)
{
   if (anzahl < INT_MAX)
   {
      anzahl++;
      liste[anzahl] = zahl;
      return TRUE;
   }
   else
      return FALSE;
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
   int wert;
   if (!isEmpty())
   {
      wert = liste[1];
      for (int i = 1; i < anzahl; i++)
      {
         liste[i] = liste[i + 1];
      }
      anzahl--;
      return wert;
   }
   else
      return QLEER;
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
   if(anzahl == 0)
      return TRUE;
   else
      return FALSE ;
}
