#include <stdio.h>
#include <stdlib.h>

struct structFila {
  int front;
  int rear;
  int capacidade;
  char * entrada;
};

typedef struct structFila fila;

//void prioridade(int corte, int n, fila *fc, int *ptVetor, fila *f);
fila * criaFila(int tamanho);
int cheia(fila *f);
int vazia(fila *f);
void insere(int x, fila *f);
char retira(fila *f);
void mostraFila(fila *f);


int main(void) {
  int i,j, temp, corte, aux=0;
  int s[100];
  
  fila *ptFila = criaFila(100);
  for(i=0;i<100;i++){
    scanf("%d", &s[i]);
      switch (s[i]) {
        case -1: i=99;
        default: break;
      }
    aux++;
  }
  scanf("%d", &corte);
  fila *ptFC = criaFila(corte);

// ORDENANDO

    for(i=0;i<aux;i++){
      for(j=0;j<aux;j++) {
        if(s[i] > s[j]) {
          temp = s[i];
          s[i] = s[j];
          s[j] = temp;
        }
      }
    }

    // TIRANDO OS MAIORES E BOTANDO FILA SEPARADA
    for(i=0;i<corte;i++) {
      insere(s[i], ptFC);
    }
    // RESTO DA FILA
    for(i=corte;i<aux;i++) {
      insere(s[i], ptFila);
    }


    mostraFila(ptFC);


  return 0;
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

  }
}

char retira(fila *f) {
  int retorno;

  if(vazia(f) == 1) {
    //printf ("\n Fila vazia \n");
    return '_';
  } else {
    retorno = f -> entrada[f->front];


    if ((f->front) == (f->rear)) {
      (f->front) = (f->rear) = -1;
    } else {
      f->front = ((f->front +1) % f->capacidade);
    }
    return retorno;
  }
}


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
