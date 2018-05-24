#include <stdio.h>
#include <stdlib.h>
//#include <stdbool>
#include "fila00.h"

int main(void) {
  char vetor[] = "XYWZDSD";
  int tamanho = (int)sizeof(vetor) -1;
  int j;

  fila *ptFila = criaFila(tamanho);

  for(j=0; vetor[j] != '\0'; j++){
    insere(vetor[j], ptFila);
  }

  while(vazia(ptFila) != 1) {
    printf("\t => %c|%d", retira(ptFila), tamanhoFila(ptFila));
  }

  destroiFila(ptFila);
  return 0;
}
