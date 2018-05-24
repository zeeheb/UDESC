#include <stdio.h>
#include <stdlib.h>
//#include <stdbool>
//#include "fila00.h"

struct structFila {
  int front;
  int rear;
  int capacidade;
  char * entrada;
};

typedef struct structFila fila;

void inverte(int tam, int *ptVetor, fila *f);
fila * criaFila(int tamanho);
int cheia(fila *f);
int vazia(fila *f);
int tamanhoFila(fila *f);
void insere(int x, fila *f);
char retira(fila *f);
//void destroiFila(fila *f);
void mostraFila(fila *f);


int main(void) {
  int i, tamanho, elementos;
  scanf("%d", &tamanho);
  scanf("%d", &elementos);
  fila *ptFila = criaFila(tamanho);
  int vetor[elementos];
  int *ptVetor = vetor;
  for(i=0;i<elementos;i++){
    scanf("%d", ptVetor+i);
  }

  inverte(elementos, ptVetor, ptFila);
  mostraFila(ptFila);


  return 0;
}

void inverte(int tam, int *ptVetor, fila *f) {
  int i;
  for(i=tam-1;i>-1;i--) {
    insere(ptVetor[i], f);
  }
}

fila *criaFila(int c) {
  fila *FILA = malloc(sizeof(struct structFila));
  FILA -> capacidade = c;
  FILA -> front = -1;
  FILA -> rear = -1;

  FILA -> entrada = malloc(FILA -> capacidade * sizeof(int));

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

/*int tamanhoFila(fila *f) {
  if (vazia(f) == 1) return 0;
  if (cheia(f) == 1) return f -> capacidade;
  else {
    int tam = (f -> capacidade + (f -> rear - f -> front +1)) % f-> capacidade;
    return tam;
  }
}*/

void insere(int x, fila *f) {
  if(cheia(f) == 1) {
    //printf ("\nFila cheia\n");
  }
  else {
    f -> rear = ((f -> rear)+1) % f -> capacidade;
    f -> entrada [f -> rear] = x;
      if(f -> front == -1){
        f -> front = f -> rear;
      }
    //printf("\n FRONT: %c | POS: %d || REAR: %c | POS: %d", f->entrada[f->front], f->front, f->entrada[f->rear], f->rear);

  }
}

char retira(fila *f) {
  int retorno;

  if(vazia(f) == 1) {
    //printf ("\n Fila vazia \n");
    return '_';
  } else {
    retorno = f -> entrada[f->front];

    //printf("\n FRONT: %c : %d || REAR: %c : %d", f->entrada[f->front], f->front, f->entrada[f->rear], f->rear);

    if ((f->front) == (f->rear)) {
      (f->front) = (f->rear) = -1;
    } else {
      f->front = ((f->front +1) % f->capacidade);
    }
    return retorno;
  }
}

/*void destroiFila(fila *f) {
  if(f) {
    if(f->entrada){
      free(f->entrada);
      free(f);
    } else {
      printf("\n Fila n liberada. \n");
    }
    printf("\n Fila liberada\n");
  }
}*/

void mostraFila(fila *f) {
    int i;
    if(vazia(f) == 1) {
      //printf ("\n Fila vazia");
    } else {
      //printf("\n Fila se encontra assim : ");
      //printf("\n Front: %d", f->front);
      //printf("\n Rear: %d", f->rear);
      //printf("\n Conteudo da fila: ");
      for(i=f->front; i != f->rear; i=(i+1) % f->capacidade) {
        printf("%d ", f->entrada[i]);
      }
      printf("%d \n", f->entrada[i]);
    }
}
