/**********************************************************************\
* Kurzbeschreibung:
* "Funktionstest" - 2 komplexe Zahlen einlesen 
* und alle implementierten Funktionen aus complex.c zum Test aufrufen
* 
* Datum:     Autor:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS //VC++: keine scanf() Warnungen
#include <stdio.h>
#include "complex.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--- main -----------------------------------------------------------*/
int main(void) 
{
   Complex y, x, z;
   printf("1.Zahl eingeben\nRealteil:");
   while (scanf("%lf",&x.real) != 1)
   {
      printf("\nFalsche Eingabe!");
      fflush(stdin);
   }
   printf("Imaginaerteil:");
   while (scanf("%lf",&x.imag) != 1)
   {
      printf("\nFalsche Eingabe!");
      fflush(stdin);
   }
   printf("2.Zahl eingeben\nRealteil:");
   while (scanf("%lf",&y.real) != 1)
   {
      printf("\nFalsche Eingabe!");
      fflush(stdin);
   }
   printf("Imaginaerteil:");
   while (scanf("%lf",&y.imag) != 1)
   {
      printf("\nFalsche Eingabe!");
      fflush(stdin);
   }
   printf("\nx = ");
   printComplex(x);
   printf("y = ");
   printComplex(y);
   z = addComplex(x,y);
   printf("\nSumme:\t\tx + y = ");
   printComplex(z);
   z = subComplex(x,y);
   printf("Differenz:\tx - y = ");
   printComplex(z);
   z = mulComplex(x,y);
   printf("Produkt:\tx * y = ");
   printComplex(z);
   z = divComplex(x,y);
   printf("Quotient:\tx / y = ");
   printComplex(z);
   
   return 0;
}
