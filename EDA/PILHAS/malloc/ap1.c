#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int topo;
  int tamMax;
  char * ptEntradas;
}tipoPilha;

int cheia(tipoPilha * p);
int vazia(tipoPilha * p);

void push(char x, tipoPilha * p){
  if (cheia(p)){
    printf ("Pilha cheia\n");
    getchar();
  }
  ++(p->topo);
  *(p->ptEntradas + (p->topo)) = x;

  printf ("\t || PUSH: %c, TOPO: %d", *(p->ptEntradas+(p->topo)), p->topo);
}

void pop(char *x, tipoPilha *p){
  if (vazia(p)){
    printf("Pilha vazia\n");
    getchar();
  }
    x = (p->ptEntradas + (p->topo));
      printf ("\t ||POP: %c, TOPO: %d", *(p->ptEntradas + (p->topo)), p->topo);
      --(p->topo);

}

int cheia(tipoPilha *p){
  return (p->topo >= (p->tamMax));
}

int vazia(tipoPilha *p){
  return (p->topo == 0);
}

void inicializaPilha(tipoPilha *p){
  p->topo = 0;
  p->ptEntradas = (char*) malloc((p->tamMax)* sizeof(char));
    if(p->ptEntradas == NULL){
      printf ("\n Erro! Memória nao alocada.\n");
      exit(0);
    }
}

void destroiPilha(tipoPilha *p){
  if(p) {
    if (p->ptEntradas){
      free(p->ptEntradas);
      printf ("\n Pilha desalocada com sucesso\n");
    }
    else {
      printf ("\n Pilha inexistente.\n");
    }
  }
}
