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
//#include <windows.h>

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

/*--- Funktionsdefinitionen ------------------------------------------*/

/*--- main -----------------------------------------------------------*/
int main(void) 
{
   int x = 0, y = 0, b = 0;
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
   //Sleep(2000);
   test2 = createMatrixRand(x,y);
   printMatrix(test2);
   ergebnis = createMatrix(x,y);
   ergebnis = addMatrix(test,test2);
   printMatrix(ergebnis);
   ergebnis = subMatrix(test,test2);
   printMatrix(ergebnis);
   printf("\nBis hier hat alles schon Funktoniert\n\n");
   deleteMatrix(test);
   deleteMatrix(test2);
   test = createMatrixZero(x,y);
   test2 = createMatrixZero(x,y);
   b = setEntryAt(&test,1,1,2.0);
   b = setEntryAt(&test2,1,1,3.0);
   printMatrix(test);
   printMatrix(test2);
   printf("\n%d",b);
   printf("\nBis hier hat alles schon Funktoniert 2\n\n");
   deleteMatrix(ergebnis);
   ergebnis = createMatrixZero(x,y);
   printMatrix(ergebnis);
   ergebnis = multMatrix(test,test2);
   printMatrix(ergebnis);
   test = createMatrixRand(x,y);
   test2 = createMatrixRand(x,y);
   ergebnis = multMatrix(test,test2);
   printMatrix(ergebnis);
   return 0;
}
