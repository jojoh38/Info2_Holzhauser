#include <stdio.h>
#include <stdarg.h>

int vielmax(int zahl, ...); // Funktion um das Maximum zu finden 

int main()
{
    int max = 0; // Variable anlegen 
    
    printf("Das Maximum der Zahlen "); 
    max = vielmax(6, 34, 17, 9, 6, 67, 8); // Übergabe der Werte an die Funktion
    printf("ist: %d\n", max);

    printf("Das Maximum der Zahlen ");
    max = vielmax(4, 15, 23, 2, 84); // Übergabe der Werte an die Funktion
    printf("ist: %d\n", max);

    return 0;
}

int vielmax(int zahl, ...)
{
    int maximum = 0;
    va_list stackPtr; // Anlegen des Zeigers

    va_start(stackPtr, zahl); //Startpunkt festlegen

    for (int j = 0; j < zahl; j++)
    {
        int aktuell = va_arg(stackPtr, int); //Wert in extra Variable speichern um fehler zu verhindern
        if (aktuell >= maximum) //Vergleich mit dem aktuellen Maximum
        {
            maximum = aktuell;//Neues Maximum
        }
        if(j < (zahl-1)) //Unterscheidung wann Komma und wann nicht
            printf("%d, ", aktuell);
        else
            printf("%d ", aktuell);
    }

    va_end(stackPtr);//Endpunkt

    return maximum;
}






