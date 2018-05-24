struct structFila {
  int front;
  int rear;
  int capacidade;
  char * entrada;
};

typedef struct structFila fila;

fila * criaFila(int capacidade);
int cheia(fila *f);
int vazia(fila *f);
int tamanhoFila(fila *f);
void insere(char x, fila *f);
char retira(fila *f);
void destroiFila(fila *f);
void mostraFila(fila *f);
