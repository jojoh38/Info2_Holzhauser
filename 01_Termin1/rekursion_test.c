#include <stdio.h>
unsigned int fakultaet(unsigned int wert)
{
    int erg;
    printf("%d\n", wert);
    if (wert > 0)
        erg = wert * fakultaet(wert - 1);

    else
        erg = 1;
    return erg;
}
int main()
{
    printf("10! = %d\n", fakultaet(10));
    return 0;
}
