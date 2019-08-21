
#include <stdio.h>
#include <math.h>
#define TAM 1000000
int arr[TAM];


void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}


void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d \n", arr[i]);
   printf("\n");
}




int main()
{

  int aux;
  int n = TAM;
  for(int i=0; i<TAM; i++) {
    scanf("%d", &aux);
    arr[i] = aux;
  }


    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
