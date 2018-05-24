#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct {
  int topo;
  char elementos[N];
} Pilha;

char *inf2pos(char *ptInf, char *ptPosf, Pilha *p)
int cheia(Pilha *p);
int vazia(Pilha *p);
void inicializaPilha(Pilha * p);
//void carrega(char *ptChar, Pilha * p);
//void imprime(Pilha * p);
void push(char x, Pilha * p);
void pop(char * x, Pilha * p);


int main(void){
  Pilha Pilha1;
  Pilha *ptPilha;
  ptPilha = &Pilha1;
  inicializaPilha(ptPilha);
  char *ptInf, *ptPosf;
  char inf[N];
  scanf ("%s", inf);
  ptInf = inf;
  int n = strlen(inf);
  char *posf = malloc((n+1) * sizeof(char));
  ptPosf = posf;
  inf2pos(ptInf, ptPosf, ptPilha);
  int i;
  for(i=0;i<n+1;i++){
    printf ("%c", ptPosf[i]);
  }
  return 0;
  }



char *inf2pos(char *ptInf, char *ptPosf, Pilha *p){
  push(ptInf[0], p);
  int i, j = 0;
    for(i=1;(*(ptInf+i) != '\0');i++){
      switch (*(ptInf+i)) {
        char x;

        case '(' : push(*(ptInf+i), p);
                   break;

        case ')' : pop(&x, p);
                   while (x != '(') {
                     ptPosf[j++] = x;
                     pop(&x, p);
                   }
                   break;

        case '+':
        case '-': pop(&x, p);
                  while (x != '(') {
                    ptPosf[j++] = x;
                  }
                  push(x, p);
                  push(*(ptInf+i), p);
                  break;

        case '*':
        case '/': pop(&x, p);
                  while (x != '(' && x != '+' && x != '-'){
                    ptPosf[j++] = x;
                    pop(&x, p);
                  }
                  push(x, p);
                  push(*(ptInf+i), p);
                  break;

        default: ptPosf[j++] = *(ptInf+i);
      }
    }
    ptPosf[j] = '\0';
    return ptPosf;
}

/*void carrega(char *ptChar, Pilha * p){
  int i;
  for(i=0; (*(ptChar+i) != '\0');i++){
    push(*(ptChar+i), p);
  }
}*/

/*void imprime(Pilha * p){
    char x;
    printf("\n\nMostrando pilha:");
      while (p->topo > 0) {
        pop(&x, p);
        printf("\nPilha[%d]: || %c ||", p->topo, x);
      }
}*/

void inicializaPilha(Pilha * p){
  p -> topo = 0;
}

void push(char x, Pilha * p){
  if(cheia(p)){
    printf("A pilha está cheia\n");
    getchar();
  }

  ++(p->topo);
  p->elementos[p->topo] = x;
}

void pop(char * x, Pilha *p){
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
