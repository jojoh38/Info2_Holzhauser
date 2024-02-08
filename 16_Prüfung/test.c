/*****************************************************************
 * Aufgabe Probeklausur                               07.02.2024 *
 * Johannes Holzhauser                                           *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

// int main()
// {
//     // int zahl2;
//     // int *ptr,*ptr2, zahl;
//     // ptr2 = &zahl2;
//     // zahl2 = 12;
//     // ptr = &zahl;
//     // zahl = 15;
//     // printf("%d, %d\n",*ptr2,ptr2);
//     // printf("%d, %d, %d\n",*ptr, zahl, ptr);
//     // *ptr = 25;
//     // printf("%d, %d\n",*ptr, zahl);
//     // *ptr++;
//     // printf("%d, %d, %d\n",*ptr, zahl, ptr);
//     char *arrayp[] = {"Test","Hallo"};
//     char **ptr;
//     ptr = arrayp;
//     //Ausgeben der ersten Zeile
//     printf("\n%s",*ptr);
//     //Ausgeben der zweiten Zeile
//     printf("\n%s",*(ptr+1));
//     //Ausgeben des ersten Elements aus der ersten Zeile
//     printf("\n%c",**ptr);
//     //Ausgeben des 3 Elements aus der ersten Zeile
//     printf("\n%c",*(*ptr+2));
//     //Ausgeben des 4 Elements aus der zweiten Zeile
//     printf("\n%c",*(*(ptr+1)+3));
//     return 0;
// }
// int main ()
// {
//     int *arry[20];
//     int *(*arrptr)[20];
//     arrptr = &arry;
// }

// int main ()
// {
//     int **ptr[20];
//     int *arr[20];
//     *ptr = arr;
// }
// static int x = 20;
// void foo(int z) {
// static int x = 0, y = 1;
// x += z;
// y *= x;
// printf("x = %d\n", x);
// printf("y = %d\n", y);
// }
// int main(void){
// int y = 0;
// x++;
// printf("x = %d\n", x); /* x = _____________ */
// printf("y = %d\n", y); /* y = _____________ */
// {
// int x = 100;
// printf("x = %d\n", x); /* x = _____________ */
// printf("y = %d\n", y); /* y = _____________ */
// }
// foo(17); /* x = _____________ y = _____________ */
// foo(35); /* x = _____________ y = _____________ */
// printf("x = %d\n", x); /* x = _____________ */
// printf("y = %d\n", y); /* y = _____________ */
// return 0;
// }

// void fkt1(int *ptr) { printf("1: %d\n", sizeof(ptr)+2); } void fkt2(int arr[]) { printf("2: %d\n", sizeof(arr)+5); } void fkt3(int arr[200]) { printf("3: %d\n", sizeof(arr)+3); } void fkt4(int (*mat)[50]) { printf("4: %d\n", sizeof(*mat)+6); } void fkt5(int mat[100][50]) { printf("5: %d\n", sizeof(mat)+2); } int main(void) { int *ptr, a[200], z[100][50]; fkt1(ptr); /* __________________ */ fkt2(a); /* __________________ */ fkt3(a); /* __________________ */ fkt4(z); /* __________________ */ fkt5(z); /* __________________ */ return 0; }
// int main()
// {
//     char *d, dest[10] = {0};
//     char *s = "Text";
//     while (*s)
//         *d++ = *s++;
//     *d = 0;
// }
// int main()
// {
//     char array[100];
//     strcpy(array, "Hans");
//     free(array + 5);
// }
// int quadsum(int n)
// {
//     if (n>1)
//     {
//         printf("%d + ",n*n);
//         return n*n + quadsum(n - 1);
//     }
//     else if(n>0)
//     {
//         printf("%d = ",n*n);
//         return n*n + quadsum(n-1);
//     }
//     else
//         return 0;
// }
// int main(void)
// {
//     int n;
//     printf("Gib eine Zahl ein: ");
//     scanf("%d", &n);
//     printf("%d\n", quadsum(n));
//     return 0;
// }

// Rekursion

// void echo()
// {
//     char zeichen = getchar();
//     printf("%c", zeichen);
//     if (zeichen != '\n')
//         echo();
// }
// int main()
// {
//     printf("Eingabe: ");
//     echo();
//     return 0;
// }
// int main()
// {
//     char zeichen;
//     zeichen = getchar();
//     printf("%c", zeichen);
//     zeichen = getchar();
//     printf("%c", zeichen);
//     return 0;
// }

// void echo()
// {
//     char zeichen = getchar();
//     if (zeichen != '\n')
//         echo();
//     printf("%c", zeichen);
// }
// int main()
// {
//     printf("Eingabe: ");
//     echo();
//     return 0;
// }

// void fkt1(int *ptr) { printf("1: %d\n", (int)sizeof(ptr) + 2); }
// void fkt2(int arr[]) { printf("2: %d\n", (int)sizeof(arr) + 5); }
// void fkt3(int arr[200]) { printf("3: %d\n", (int)sizeof(arr) + 3); }
// void fkt4(int (*mat)[50]) { printf("4: %d\n", (int)sizeof(*mat) + 6); }
// void fkt5(int mat[100][50]) { printf("5: %d\n", (int)sizeof(mat) + 2); }

// int main()
// {
//     int zahlen[] = {4, 23, 213, -1, 23, -123, 3};
//     printf("Laenge %d\n", (int)(sizeof(zahlen) / (int)sizeof(zahlen[0])));
//     printf("Groese %d\n", (int)(sizeof(zahlen)));
//     int array[50];
//     for (int i = 0; i < 50; i++)
//     {
//         array[i] = i;
//     }
//     printf("Groese %d\n", (int)sizeof(array));
//     int *ptr, a[200], z[100][50];
//     fkt1(ptr); 
//     fkt2(a);   
//     fkt3(a);   
//     fkt4(z);   
//     fkt5(z); 
//     printf("Groese %d",(int)sizeof(a));

//     return 0;
// }