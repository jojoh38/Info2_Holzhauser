#include <stdio.h>

int main()
{
    int eins = 1, zwei = 2, *zeiger1, *z2;
    char c[6] = "Hello";

    zeiger1 = &zwei;
    *zeiger1 = 5;
    z2 = zeiger1;
    (*c)++;

    printf("*zeiger1 = %d\n", *zeiger1); /* *zeiger1 = _______________________*/
    printf("*z2 = %d\n", *z2); /* *z2 = _______________________*/
    printf("*c = %s\n", c); /* *z2 = _______________________*/

    z2 = &eins;
    eins = 18;

    printf("*zeiger1 = %d\n", *zeiger1); /* *zeiger1 = _______________________*/
    printf("*z2 = %d\n", *z2);           /* *z2 = _______________________*/

    *zeiger1 = 30;
    *z2 = 12;
    *zeiger1 /= *z2;
    z2 = zeiger1;
    *zeiger1 += *z2;

    printf("eins = %d\n", eins);     /*   eins = _______________________*/
    printf("zwei = %d\n", zwei);     /*   zwei = _______________________*/

    return 0;
}
