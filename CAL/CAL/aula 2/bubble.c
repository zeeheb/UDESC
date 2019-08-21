#include "stdio.h"


int main(int argc, char const *argv[]) {

  int n, *v;
  scanf("%d", &n);
  v = malloc(sizeof(int)*n);

  return 0;
}

void bubble(int *v, int n) {
  int i, j, aux;

  for(i=n-1; i>0; i--) {
    for(j=0;j<i;j++) {
      if(v[j] > v[j+1]) {
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}
