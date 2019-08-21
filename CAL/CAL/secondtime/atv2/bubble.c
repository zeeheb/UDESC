#include <stdio.h>
#include <stdlib.h>
#define TAM 100000
int arr[TAM];

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)


       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d \n", arr[i]);
    //printf("n");
}


int main()
{
    int aux;
    int n = TAM;
    for(int i=0; i<TAM; i++) {
      scanf("%d", &aux);
      arr[i] = aux;
    }



    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
