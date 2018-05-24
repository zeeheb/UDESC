#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "fila00.h"

fila *criaFila(int c) {
  fila *FILA = malloc(sizeof(struct structFila));
  FILA -> capacidade = c;
  FILA -> front = -1;
  FILA -> rear = -1;

  FILA -> entrada = malloc(FILA -> capacidade * sizeof(char));

  if(FILA -> entrada == NULL) {
    printf("\n Problema ao criar fila");
    exit(0);
  }

  return(FILA);
}

int vazia(fila *f) {
  if(f -> front < 0) return 1;
  else return 0;
}

int cheia(fila *f) {
  if((f -> rear +1) % (f -> capacidade) == (f -> front)) {
    return 1;
  } else return 0;
}

int tamanhoFila(fila *f) {
  if (vazia(f) == 1) return 0;
  if (cheia(f) == 1) return f -> capacidade;
  else {
    int tam = (f -> capacidade + (f -> rear - f -> front +1)) % f-> capacidade;
    return tam;
  }
}

void insere(char x, fila *f) {
  if(cheia(f) == 1) {
    printf ("\nFila cheia\n");
  }
  else {
    f -> rear = ((f -> rear)+1) % f -> capacidade;
    f -> entrada [f -> rear] = x;
      if(f -> front == -1){
        f -> front = f -> rear;
      }
    printf("\n FRONT: %c | POS: %d || REAR: %c | POS: %d", f->entrada[f->front], f->front, f->entrada[f->rear], f->rear);

  }
}

char retira(fila *f) {
  char retorno;

  if(vazia(f) == 1) {
    printf ("\n Fila vazia \n");
    return '_';
  } else {
    retorno = f -> entrada[f->front];

    printf("\n FRONT: %c : %d || REAR: %c : %d", f->entrada[f->front], f->front, f->entrada[f->rear], f->rear);

    if ((f->front) == (f->rear)) {
      (f->front) = (f->rear) = -1;
    } else {
      f->front = ((f->front +1) % f->capacidade);
    }
    return retorno;
  }
}

void destroiFila(fila *f) {
  if(f) {
    if(f->entrada){
      free(f->entrada);
      free(f);
    } else {
      printf("\n Fila n liberada. \n");
    }
    printf("\n Fila liberada\n");
  }
}

void mostraFila(fila *f) {
    int i;
    if(vazia(f) == 1) {
      printf ("\n Fila vazia");
    } else {
      printf("\n Fila se encontra assim : ");
      printf("\n Front: %d", f->front);
      printf("\n Rear: %d", f->rear);
      printf("\n Conteudo da fila: ");
      for(i=f->front; i != f->rear; i=(i+1) % f->capacidade) {
        printf("%c ", f->entrada[i]);
      }
      printf("%c ", f->entrada[i]);
    }
}
