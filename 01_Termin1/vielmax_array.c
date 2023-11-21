#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZAHLEN 20
#define BEGRENZUNG 400

int vielmax (int zahl[]);

int main ()
{
    int max = 0;
    int zahlen[ZAHLEN];
    srand(time(0));
    for (int i = 0; i < (ZAHLEN); i++)
    {
       zahlen[i] = (rand() % BEGRENZUNG) + 1; 
    }
    printf("Das Maximum der Zahlen ");
    for (int a = 0; a < ZAHLEN; a++)
    {
        if(a < (ZAHLEN-1))
        printf("%d, ",zahlen[a]);
        else
        printf("%d ",zahlen[a]);
    }
    
    max = vielmax(zahlen);
    printf("ist: %d",max);
    return 0;

}

int vielmax (int zahl[])
{
    int maximum = 0;
    for (int j = 0; j < (ZAHLEN-1) ; j++)
    {
        if (zahl[j] >= maximum)
        {
            maximum = zahl[j];
        }
    }

    return maximum;
    
}