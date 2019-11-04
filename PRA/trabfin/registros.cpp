#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// compile with g++ registros.cpp -o reg
// run with ./reg < senhas.txt para gerar o arquivo binario

#define TAM 10000

typedef struct {
  int rank;
  char hash[1];
  char cadeia[20], social[20];
  bool idle = false;
} senha;

int main(int argc, char const *argv[]) {

static const char *auxsocial[] = {"facebook", "twitter", "google", "github", "youtube", "reddit"};
senha pw;

// ====================== INICIO GRAVAÇAO DAS SENHAS EM ARQ BINARIO =====================

// FILE *arqb;
// //FILE *arqt;
// arqb = fopen("saidasenha.bin", "wb");
// //arqt = fopen("saidasenha.txt", "w+");
//
//   for (int i=0; i<TAM; i++) {
//     cin >> pw.hash;
//     cin >> pw.cadeia;
//     pw.rank = i;
//     int auxrand = rand() % 6;
//     strcpy(pw.social, auxsocial[auxrand]);
//     fwrite(&pw, sizeof(pw), 1, arqb);
//     //fwrite(&pw, sizeof(pw), 1, arqt);
//   }
//
// fclose(arqb);
//fclose(arqt);

// =========================================================================================
int choice;
FILE *arqb;

// int conttam = TAM;

while (choice != 0) {
cout << endl <<"Digite 1 para inserir, 2 para buscar, 3 para editar, 4 para remover, 0 para sair " << endl;
cin >> choice;
    switch (choice) {

    case 1:

        arqb = fopen("saidasenha.bin", "rb+");
        cout << "Digite a nova senha: " << endl;
        cin >> pw.cadeia;
        cout << "Digite o Rank: " << endl;
        cin >> pw.rank;
        cout << "Digite a rede social: " << endl;
        cin >> pw.social;

        fwrite(&pw, sizeof(pw), 1, arqb);
        break;
        fclose(arqb);

    case 2:

        arqb = fopen("saidasenha.bin", "rb");

        int RRN;
        cout << "Digite o RRN: " << endl;
        cin >> RRN;

        while (fread(&pw, sizeof(pw), 1, arqb) != 0) {


          if(pw.rank == RRN) {
            cout << "Rank: " << pw.rank << " // senha: " << pw.cadeia << " // social: " << pw.social << endl;
          }
        }

        fclose(arqb);
        break;

    default:  break;
    }
}


  return 0;
}
