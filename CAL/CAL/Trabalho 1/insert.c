// C program for insertion sort
#include <stdio.h>
#include <math.h>
#define TAM 1000000
int arr[TAM];

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d \n", arr[i]);
   printf("\n");
}



/* Driver program to test insertion sort */
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
