#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int topo;
  int tamMax;
  char * ptEntradas;
}tipoPilha;

char * leEntradaPilha(tipoPilha * p);
void inicializaPilha(tipoPilha * p);
void carregaPilha(char * ptVetor, tipoPilha * p);
void imprimePilha(tipoPilha * p);
void push(char x, tipoPilha * p);
void pop(char * x, tipoPilha * p);
void destroiPilha(tipoPilha * p);

int main (void){
  tipoPilha PILHA;
  tipoPilha *ptPilha;
  ptPilha = &PILHA;
  char * ptEntrada;

ptEntrada = leEntradaPilha(ptPilha);
inicializaPilha(ptPilha);

carregaPilha(ptEntrada, ptPilha);
imprimePilha(ptPilha);
destroiPilha(ptPilha);
return 1;

}

char * leEntradaPilha(tipoPilha * p){
  char vetor[] = "testeTeste";
  char *ptVetor;
  int tamVetor = (int)sizeof(vetor) ;
  printf ("\n QUANTIDADE DE OBJETOS:: %d", tamVetor -1);
  p->tamMax = tamVetor -1;
  ptVetor = &vetor[0];
  return(ptVetor);
}

void carregaPilha(char *ptVetor, tipoPilha * p){
  printf ("\n\n Carrega pilha (usando push): \n");
    for(int i=0;i<(p->tamMax);i++){
      push(*ptVetor, p);
      ptVetor++;
    }
    return; //????
}

void imprimePilha(tipoPilha * p){
  char x;
  printf("\n\n Mostra pilha (usando pop): \n");
    while(p->topo >= 0){
      pop(&x, p);
      printf ("Pilha[%d]: || %c ||", p->topo, x);
    }
    printf ("Acabou");
  return; //????
}
