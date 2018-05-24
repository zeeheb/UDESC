#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define N 100

typedef struct {
  int topo;
  char elementos[N];
} Pilha;

int cheia(Pilha *p);
int vazia(Pilha *p);
void inicializaPilha(Pilha * p);
//void carrega(char *ptChar, Pilha * p);
void imprime(Pilha * p);
void push(int x, Pilha * p);
void pop(int * x, Pilha * p);
void maquina(int *ptEntr, Pilha *p, int n);


int main(void){
  Pilha Pilha1;
  Pilha *ptPilha;
  ptPilha = &Pilha1;
  inicializaPilha(ptPilha);
  int *ptEntr;
  int s[N];
  int i, aux=0;
    for(i=0;i<N;i++){
      scanf("%d", &s[i]);
        switch (s[i]) {
          case -1: i=99;
          default: break;
        }
      aux++;
    }
  ptEntr = s;
  maquina(ptEntr, ptPilha, aux);
  //carrega(ptChar, ptPilha);
  imprime(ptPilha);

return 0;
}

/*void carrega(char *ptChar, Pilha * p){
  int i;
  for(i=0; (*(ptChar+i) != '\0');i++){
    push(*(ptChar+i), p);
  }
}*/

void imprime(Pilha * p){
    int x;
    //printf("\n\nMostrando pilha:");
      while (p->topo > 0) {
        pop(&x, p);
        printf("%d ", x);
      //  printf("\nPilha[%d]: || %c ||", p->topo, x);
      }
}

void maquina(int *ptEntr, Pilha *p, int n){
  int i, count=0;
    for(i=0;i<n;i++) {
      switch (ptEntr[i]) {
        case -1: break;
        default:  count = count + (ptEntr[i]);
                  push(count, p);
      }
    }



}

void inicializaPilha(Pilha * p){
  p -> topo = 0;
}

void push(int x, Pilha * p){
  if(cheia(p)){
    printf("A pilha está cheia\n");
    getchar();
  }

  ++(p->topo);
  p->elementos[p->topo] = x;
}

void pop(int * x, Pilha *p){
  if (vazia(p)){
    printf ("Pilha Vazia. \n");
    getchar();
  }

  *x = p->elementos[p->topo];

  --(p -> topo);
}

int vazia(Pilha *p){
  return (p->topo <= 0);
}

int cheia(Pilha *p){
    return (p->topo >= N-1);
}
