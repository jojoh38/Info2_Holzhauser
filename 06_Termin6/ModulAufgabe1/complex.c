/**********************************************************************\
* Kurzbeschreibung: complex.c
* Bietet Funktionen zum Rechnen mit komplexen Zahlen
*
* Datum:20.11.2023     Autor:Johannes Holzhauser  Grund der Aenderung:
*                            Maximilian Schmidt   Abgabe
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <float.h>
#include <stdio.h>
#include "complex.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
* Addition komplexer Zahlen: x + y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex addComplex(Complex x, Complex y)
{
   Complex z;
   z.real = x.real + y.real;
   z.imag = x.imag + y.imag;
   return z;
}

/*--------------------------------------------------------------------*\
* Subtraktion komplexer Zahlen: x - y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex subComplex(Complex x, Complex y)
{
   Complex z;
   z.real = x.real - y.real;
   z.imag = x.imag - y.imag;
   return z;
}

/*--------------------------------------------------------------------*\
* Multiplikation komplexer Zahlen: x * y
* Rueckgabe: Ergebnis im Typ "Complex"
\*--------------------------------------------------------------------*/
Complex mulComplex(Complex y, Complex x)
{
   Complex z;
   z.real = ((x.real * y.real) - (x.imag * y.imag));
   z.imag = ((x.real * y.imag) + (x.imag * y.real));
   return z;
}

/*--------------------------------------------------------------------*\
* Division komplexer Zahlen: x / y
* Rueckgabe: Ergebnis im Typ "Complex"; im Fehlerfall 0. bzw. ERROR_C
\*--------------------------------------------------------------------*/
Complex divComplex(Complex x, Complex y)
{
   Complex z;
   Complex Error;
   Error.real = ERROR_C;
   Error.imag = ERROR_C;
   if (((y.real * y.real) + (y.imag * y.imag)) == 0)
   {
      return Error;
   }
   else
   {
      z.real = ((x.real * y.real) + (x.imag * y.imag)) / ((y.real * y.real) + (y.imag * y.imag));
      z.imag = ((x.real * y.imag) - (x.imag * y.real)) / ((y.real * y.real) + (y.imag * y.imag));
      return z;
   }
}

/*--------------------------------------------------------------------*\
* Lesbar formatierte Ausgabe einer komplexen Zahl
\*--------------------------------------------------------------------*/
int printComplex(Complex z)
{
   printf("(%.3lf + %.3lfi)\n", z.real, z.imag);
   return 0;
}
