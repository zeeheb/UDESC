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


FILE *file;
registro reg;

file = fopen("registro.bin", "wb");

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

        if (saida == 3) { //LISTA POR RRN
          int auxrrn;
          printf (" Digite um RRN: \n");
          scanf ("%d", &auxrrn);

          fclose(file);
          printf ("\nListando produto: \n");
          file = fopen("registro.bin", "rb");

          while (fread(&reg, sizeof(reg), 1, file) != 0) {
            if(reg.rrn == auxrrn) {
              printf("Nome: %s \n", reg.nome);
              printf("Marca: %s \n", reg.marca);
              printf("EAN: %ld\n", reg.ean);
              printf("Valor: %f\n", reg.valor);
            }

          }
          int saida3;
          printf ("Cadastrar mais digite 1, sair: 0 \n");
          scanf ("%d", &saida3);

          if(saida3 == 0) break;
        }

        if (saida == 2) { //LISTA TODOS
          int auxrrn;


          fclose(file);
          printf ("\nListando produtos: \n");
          file = fopen("registro.bin", "rb");
          while (fread(&reg, sizeof(reg), 1, file) != 0) {

              printf("Nome: %s \n", reg.nome);
              printf("Marca: %s \n", reg.marca);
              printf("EAN: %ld\n", reg.ean);
              printf("Valor: %f\n", reg.valor);


          }
          int saida2;
          printf ("Cadastrar mais digite 1, sair: 0 \n");
          scanf ("%d", &saida2);

          if(saida2 == 0) break;
        }


        reg.rrn = i+1;

        printf("Digite o nome do produto: \n");
        scanf("%s", reg.nome   );

        printf("Digite a marca do produto: \n");
        scanf("%s", reg.marca );

        printf("Digite o EAN do produto: \n");
        scanf("%ld", &reg.ean );

        printf("Digite o valor do produto: \n");
        scanf("%f", &reg.valor );

        fwrite(&reg, sizeof(registro), 1 , file);

        printf("Para continuar digite 1, listar produtos 2, procurar por RRN 3 e sair 0.\n");
        scanf("%d", &saida);

        i++;

      }

      fclose(file);


    }



  return 0;
}
