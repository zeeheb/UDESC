#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int topo;
  int tamMax;
  char * entradas;
}tipoPilha;

int cheia(tipoPilha * p);
int vazia(tipoPilha * p);

void aumentaPilha(tipoPilha * p){
  p->tamMax = (p->tamMax) * 2;
  p->entradas = (char*) realloc(p->entradas, (p->tamMax)* sizeof(char));
  printf("  **  ");
}

void push(char x, tipoPilha * p){
  if (cheia(p)){
    aumentaPilha(p);

    ++(p->topo);

    printf("\t || PUSH :: %c, TOPO:: %d", *(p->entradas + (p->topo)), p->topo);
  }
}

void pop(char *x, tipoPilha * p){
    if (vazia(p)) {
      printf("\n A pilha esta vazia");
    }

      x = (p->entradas + (p->topo));
      printf ("\t ||POP:: %c, TOPO:: %d", *(p->entradas + (p->topo)), p->topo);

    --(p->topo);
}

int cheia(tipoPilha * p){
    return(p->topo > (p->tamMax));
}

int vazia(tipoPilha * p){
  return (p->topo <= 0);
}

tipoPilha * inicializaPilha(void) {
    tipoPilha * p = (tipoPilha*) malloc(sizeof(tipoPilha *));
    if (p == NULL){
      printf("\n Erro! pilha nao criada..");
      exit(0);
    }

    p->topo = 0;
    p->tamMax = 1;
    p->entradas = (char*) malloc((p->tamMax)* sizeof(char));
      if (p->entradas == NULL) {
        printf ("\n Erro! Memoria nao alocada..");
        exit(0);
      }

  return(p);
}

void destroiPilha(tipoPilha * p){
  if (p) {
    if (p->entradas) {
      free(p->entradas);
        printf("\n pilha desalocada com sucesso\n");
    }
  }
  else printf("\npilha inexistente\n");
}
