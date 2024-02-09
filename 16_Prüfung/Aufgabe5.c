#include <stdio.h>
#include <string.h>
char *x[] = {"rrhhqd__ds",
             "tmddduwlma",
             "khvqhhhahh",
             "odycuermmf"};
int main(int argc, char *argv[])
{
    char **s, *t;
    t = *++argv;
    while (--argc)
    {
        while (*t)
        {
            s = x + 4;
            while (*s-- - *x)
                printf("%c", (*s)[*t - '0'] + 1);
            printf(" ");
            t++;
        }
        printf("\n");
        t = *++argv;
    }
    return 0;
}