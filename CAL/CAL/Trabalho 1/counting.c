#include <stdio.h>
#include <stdlib.h>
#define TAM 1000000

int arr[TAM];

/* end is the last index + 1 */
void csort(int array[], const int end, const int max, const int min)
{
  int i;
  const int range = max-min+1;
  int count[range+1],
      scratch[end];

  for(i=0; i<range+1; i++)
    count[i] = 0;

  /* Set the value of count[i] to the number of
   * elements in array with value i+min-1. */
  for(i=0; i<end; i++) {
    int c = array[i]+1-min;
    count[c]++;
  }

  /* Update count[i] to be the number of
   * elements with value less than i+min. */
  for(i=1; i<range; i++)
    count[i] += count[i-1];

  /* Copy the elements of array into scratch in
   * stable sorted order. */
  for(i=(end-1); i>=0; i--) {
    int c = array[i]-min;
    int s = count[c];
    scratch[s] = array[i];
    /* Increment count so that the next element
     * with the same value as the current element
     * is placed into its own position in scratch. */
    count[c]++;
  }

  for(i=0; i<end; i++)
    array[i] = scratch[i];
}


void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d \n", arr[i]);
}


int main(int argc, char const *argv[]) {

  int aux;
  int n = TAM;
  for(int i=0; i<TAM; i++) {
    scanf("%d", &aux);
    arr[i] = aux;
  }

  csort(arr, n+1, n, 0);
  printArray(arr, n);

  return 0;
}
