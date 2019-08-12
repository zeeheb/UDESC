#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

// PAREI AJEITANDO VETOR DE STRUCT


typedef struct{
  char nome[20], marca[20];
  long int ean;
  float valor;
  int rrn;
} registro;


int main(int argc, char const *argv[]) {

/*char nome[20], marca[20];
long int ean;
float valor;
*/

FILE *file;
registro reg[100];

file = fopen("registro.bin", "w");

if (!file) {
  printf("Erro de abertura de arquivo \n");
  perror("> Resultado da abertura ");
  printf("> Erro: %d\n", errno);
  } else {
    printf("Arquivo aberto com sucesso \n");

    printf("Faça o registro do produto. \n");

    int saida = 1;
    int i = 0;

      while (saida != 0) {
        reg[i].rrn = i;

        printf("Digite o nome do produto: \n");
        scanf("%s", reg[i].nome   );
        fwrite(&reg[i].nome, sizeof(reg[i].nome), 1, file);

        printf("Digite a marca do produto: \n");
        scanf("%s", reg[i].marca );
        fwrite(&reg[i].marca, sizeof(reg[i].marca), 1, file);

        printf("Digite o EAN do produto: \n");
        scanf("%ld", &reg[i].ean );
        fwrite(&reg[i].ean, sizeof(reg[i].ean), 1, file);

        printf("Digite o valor do produto: \n");
        scanf("%f", &reg[i].valor );
        fwrite(&reg[i].valor, sizeof(reg[i].valor), 1, file);

        printf("Para continuar digite 1 e sair 0.\n");
        scanf("%d", &saida);

        i++;

      }

      fclose(file);


    }



  return 0;
}
