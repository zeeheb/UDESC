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
//void imprime(Pilha * p);
void push(char x, Pilha * p);
void pop(char * x, Pilha * p);
int bemFormada(char *ptChar, Pilha *p);


int main(void){
  Pilha Pilha1;
  Pilha *ptPilha;
  ptPilha = &Pilha1;
  inicializaPilha(ptPilha);
  char *ptChar;
  char s[N];
  scanf ("%s", s);
  ptChar = s;
  //carrega(ptChar, ptPilha);
  //imprime(ptPilha);
  if (bemFormada(ptChar, ptPilha)){
    printf ("BALANCEAMENTO OK\n");
  }
  else {
    printf ("DESBALANCEADO\n");
  }

return 0;
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

int bemFormada(char *ptChar, Pilha *p){
  int i;
    for(i=0; (*(ptChar+i) != '\0');i++){
      char x;
        switch (*(ptChar+i)) {
          case ')' :  if (vazia(p)) return 0;
                      pop(&x, p);
                      if (x !='(') return 0;
                      break;

          case ']' :  if (vazia(p)) return 0;
                      pop(&x, p);
                      if (x !='[') return 0;
                      break;

          case '[' : push(*(ptChar+i), p);
                     break;

          case '(' : push(*(ptChar+i), p);
                     break;

          default: break;
        }
    }
    return vazia(p);
}

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
