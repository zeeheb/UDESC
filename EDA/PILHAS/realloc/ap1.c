#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int topo;
  int tamMax;
  char * entradas;
}tipoPilha;

void carregaPilha(char * ptVetor, tipoPilha * p);
tipoPilha * inicializaPilha(void);
void imprimePilha(tipoPilha * p);
int cheia(tipoPilha * p);
void push(char x, tipoPilha * p);
void pop(char *x, tipoPilha * p);
void destroiPilha(tipoPilha * p);

int main(void){
  printf ("Digite uma entrada: ");

  char entrada[50] = "aXXXXyz";
  tipoPilha * ptPilha = inicializaPilha();
    carregaPilha(&entrada[0], ptPilha);
  imprimePilha(ptPilha);
  destroiPilha(ptPilha);

  return 0;
}

void carregaPilha(char * ptVetor, tipoPilha * p){
  printf ("\n Leitura da entrada ==> %s \n", ptVetor);
  printf ("\n\n carrega pilha (usando push):\n");

    for( ; *ptVetor != '\0';ptVetor++){
      push(*ptVetor, p);
    }
}

void imprimePilha(tipoPilha * p){
  char x;
  printf("\n\n mostra pilha (usando pop): \n");
    while(p->topo >= 0) {
      pop(&x, p);
      printf("Pilha[%d]: %c", p->topo, x);
    }
    printf("\n acabou .. \n");
}
