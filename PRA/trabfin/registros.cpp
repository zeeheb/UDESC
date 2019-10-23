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
} senha;

int main(int argc, char const *argv[]) {

static const char *auxsocial[] = {"facebook", "twitter", "google", "github", "youtube", "reddit"};
senha pw;

// ====================== INICIO GRAVAÇAO DAS SENHAS EM ARQ BINARIO =====================

FILE *arqb;
//FILE *arqt;
arqb = fopen("saidasenha.bin", "wb");
//arqt = fopen("saidasenha.txt", "w+");

  for (int i=0; i<TAM; i++) {
    cin >> pw.hash;
    cin >> pw.cadeia;
    pw.rank = i;
    int auxrand = rand() % 6;
    strcpy(pw.social, auxsocial[auxrand]);
    fwrite(&pw, sizeof(pw), 1, arqb);
    //fwrite(&pw, sizeof(pw), 1, arqt);
  }

fclose(arqb);
//fclose(arqt);

// =========================================================================================

arqb = fopen("saidasenha.bin", "rb");

int indice;
while (fread(&pw, sizeof(pw), 1, arqb) != 0) {

  //cin >> indice;

  if(pw.rank == 44) {
    cout << "Rank: " << pw.rank << " // senha: " << pw.cadeia << " // social: " << pw.social << endl;
  }
}

fclose(arqb);




  return 0;
}
