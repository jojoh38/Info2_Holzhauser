// #include <stdio.h>
// #define N 5
// void findMin(int arr[], int size, int** minPtr) {
//  int min = arr[0];
//  *minPtr = &arr[0];
//  for (int i = 1; i < size; i++) {
//  if (arr[i] < min) {
//  min = arr[i];
//  *minPtr = &arr[i];
//  } 
//  }
// }
// int main() {
//  int arr[N] = {5, 3, 8, 1, 9};
//  int* minPtr = 0;
//  findMin(arr, N, &minPtr);
//  printf("Der kleinste Element des Arrays ist %d und liegt an Adresse %p\n.", *minPtr, minPtr);
//  return 0;
// }
// #include <stdio.h>
// #define M 3
// int main() {
//  int arr[M][M] = {{1, 2, 3},
//  {4, 5, 6},
//  {7, 8, 9}};
//  int* elem = (int*)arr;
//  int (*row)[M] = &arr[0];
//  for(int i = 0; i < M; i++) {
//  printf("elem[%d] = %d\t*row[%d] = %d\n",
//  i, elem[i], i, *row[i]);
//  }
//  return 0;
// }

#include <stdio.h>
int main() {
 char *studiengaenge[3];
 studiengaenge[0] = "B-EI";
 studiengaenge[1] = "B-MED";
 studiengaenge[2] = "B-MEI";
 for (int i = 0; i < 3; i++) {
 printf("%s\n", studiengaenge[i]);
 }
 return 0;
}