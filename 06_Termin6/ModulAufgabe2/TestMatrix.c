/**********************************************************************\
* Kurzbeschreibung:
* "Funktionstest" - Matrizen mit Werten erzeugen
* und alle implementierten Funktionen aus matrixOp.c zum Test aufrufen
* 
* Datum:     Autor:
* 
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS //VC++: keine scanf() Warnungen
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrixOp.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--- main -----------------------------------------------------------*/
int main(void) 
{
   int x = 0, y = 0;
   Matrix test;
   Matrix test2;
   Matrix ergebnis;
   printf("Test verschiedener Funktionen der Bibliothek\nGewuenschte Matrizen-Groesse eingeben\nZeilen, Spalten(>0; z.B. : 3,4)");
   while(scanf("%d,%d", &x, &y) != 2 || x <= 0 || y <= 0) 
   {
      printf("\nFalsche EIngabe!");
      while(getchar() != '\n')
         getchar();
   }
   test = createMatrixZero(x,y);
   printMatrix(test);
   deleteMatrix(test);
   test = createMatrixRand(x,y);
   printMatrix(test);
   test2 = createMatrixRand(x,y);
   printMatrix(test2);
   ergebnis = createMatrix(x,y);
   ergebnis = addMatrix(test,test2);
   printMatrix(ergebnis);
   ergebnis = subMatrix(test,test2);
   printMatrix(ergebnis);

   return 0;
}
