#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>



typedef struct{
  char nome[20], marca[20];
  long int ean;
  float valor;
  int rrn;
  int flag;
} registro;


int main(int argc, char const *argv[]) {


FILE *file;
registro reg;

file = fopen("registro.bin", "wb+");

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

        if (saida == 1) {

          reg.rrn = i+1;

          printf("Digite o nome do produto: \n");
          scanf("%s", reg.nome   );

          printf("Digite a marca do produto: \n");
          scanf("%s", reg.marca );

          printf("Digite o EAN do produto: \n");
          scanf("%ld", &reg.ean );

          printf("Digite o valor do produto: \n");
          scanf("%f", &reg.valor );

          reg.flag = 1;

          fwrite(&reg, sizeof(registro), 1 , file);

          printf("Para continuar digite 1, listar produtos 2, procurar por RRN 3, remover por RRN 4 e sair 0.\n");
          scanf("%d", &saida);

          i++;

        }



        if (saida == 2) { //LISTA TODOS
          int auxrrn;


          fclose(file);
          printf ("\nListando produtos: \n");
          file = fopen("registro.bin", "rb+");
          while (fread(&reg, sizeof(reg), 1, file) != 0) {
            if (reg.flag == 1) {
              printf("Nome: %s \n", reg.nome);
              printf("Marca: %s \n", reg.marca);
              printf("EAN: %ld\n", reg.ean);
              printf("Valor: %f\n", reg.valor);
              printf("Flag: %d\n", reg.flag);
            }

          }

          printf ("Cadastrar mais digite 1, Listar 2, sair: 0 \n");
          scanf ("%d", &saida);

        }

        if (saida == 3) { //LISTA POR RRN
          int auxrrn;
          long aki;
          printf (" Digite um RRN: \n");
          scanf ("%d", &auxrrn);

          fclose(file);
          printf ("\nListando produto: \n");
          file = fopen("registro.bin", "rb+");

          while (fread(&reg, sizeof(reg), 1, file) != 0) {
            if(reg.rrn == auxrrn && reg.flag == 1) {
              printf("Nome: %s \n", reg.nome);
              printf("Marca: %s \n", reg.marca);
              printf("EAN: %ld\n", reg.ean);
              printf("Valor: %f\n", reg.valor);
              aki = ftell(file);
              printf("BYTE AKI: %ld\n", aki);
            }

          }
          int saida3;
          printf ("Cadastrar mais digite 1, sair: 0 \n");
          scanf ("%d", &saida);

        }

        if (saida == 4) {
          long aki;
          int auxrrn2;
          printf("Digite o RRN\n");
          scanf("%d", &auxrrn2);

          fclose(file);

          file = fopen("registro.bin", "rb+");

          fseek(file, 0 , SEEK_SET);
          while (fread(&reg, sizeof(reg), 1, file) != 0) {
            if(reg.rrn == auxrrn2) {
              aki = ftell(file);
              printf("Aqui esta o byte: %ld\n", aki);
              //reg.flag = 0; // MARCANDO FLAG EM 0
              fclose(file);
            }

            file = fopen("registro.bin", "wb+");
            fseek(file, aki, SEEK_SET);
            fprintf(file, "%d", reg.flag-1 );
          }

          printf("Novo 1, Listar 2, sair 0\n");
          scanf("%d", &saida);

          }




        }
      fclose(file);


    }

    // Remoção física
    printf("remoçao fisica:\n");

    fwrite(&reg, sizeof(registro), 1 , file);

    file = fopen("registro.bin", "rb+");
    while (fread(&reg, sizeof(reg), 1, file) != 0) {
      if (reg.flag == 1) {
        printf("Nome: %s \n", reg.nome);
        printf("Marca: %s \n", reg.marca);
        printf("EAN: %ld\n", reg.ean);
        printf("Valor: %f\n", reg.valor);
        printf("Flag: %d\n", reg.flag);
      }

    }




  return 0;
}
