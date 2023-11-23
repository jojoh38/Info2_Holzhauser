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
   srand(time(NULL));
   double det = 0.0, element = 0.0;
   Matrix a, b, c;
   printf("Test verschiedener Funktionen der Bibliothek\nGewuenschte Matrizen-Groesse eingeben\nZeilen, Spalten(>0; z.B. : 3,4)");
   while(scanf("%d,%d", &x, &y) != 2 || x <= 0 || y <= 0) 
   {
      printf("\nFalsche EIngabe!");
      while(getchar() != '\n')
         getchar();
   }
   printf("Matrix Elemente eingeben (für den Test nur 1.Elem.,\n weitere werden mir +1 erzeugt)\n Element in [1,1] (z.B.: 4.5):");
   while(scanf("%f",&element) != 1) 
   {
      printf("\nFalsche EIngabe!");
      while(getchar() != '\n')
         getchar();
   }
   printf("\nTest Create Zero und Rand:\nCreate Matrix Zero: a[%d,%d] =",x,y);
   a = createMatrixZero(x,y);
   printMatrix(a);
   destroyMatrix(&a);
   a = createMatrixRand(x,y);
   printMatrix(a);

   return 0;
}

// test = createMatrixZero(x,y);
//    printMatrix(test);
//    deleteMatrix(test);
//    test = createMatrixRand(x,y);
//    printMatrix(test);
//    test2 = createMatrixRand(x,y);
//    printMatrix(test2);
//    ergebnis = createMatrix(x,y);
//    ergebnis = addMatrix(test,test2);
//    printMatrix(ergebnis);
//    ergebnis = subMatrix(test,test2);
//    printMatrix(ergebnis);
//    printf("\nBis hier hat alles schon Funktoniert\n\n");
//    deleteMatrix(test);
//    deleteMatrix(test2);
//    test = createMatrixZero(x,y);
//    test2 = createMatrixZero(x,y);
//    b = setEntryAt(&test,1,1,2.0);
//    b = setEntryAt(&test2,1,1,3.0);
//    printMatrix(test);
//    printMatrix(test2);
//    printf("\n%d",b);
//    printf("\nBis hier hat alles schon Funktoniert 2\n\n");
//    deleteMatrix(ergebnis);
//    ergebnis = createMatrixZero(x,y);
//    printMatrix(ergebnis);
//    ergebnis = multMatrix(test,test2);
//    printMatrix(ergebnis);
//    for (int i =0 ; i < test.zeilen*test.spalten; i++) 
//       test.mElement[i] = i;
//    for (int i =0 ; i < test.zeilen*test.spalten; i++) 
//       test2.mElement[i] = i;
//    printMatrix(test);
//    printMatrix(test2);
//    ergebnis = multMatrix(test,test2);
//    printMatrix(ergebnis);
//    printf("\nBis hier hat alles schon Funktoniert 3\n\n");
//    deleteMatrix(ergebnis);
//    ergebnis = transposeMatrix(test); 
//    printMatrix(ergebnis);
//    det = determMatrix(test);
//    printf("\n%lf\n",det);
