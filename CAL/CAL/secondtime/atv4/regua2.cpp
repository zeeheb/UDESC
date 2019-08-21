#include <iostream>

using namespace std;

int calcregua(int inicio, int fim) {

  float centro = (fim - inicio)/4;
  //float centrointervalo = inicio + centro;
  cout << "Inicio: " << inicio << " Fim: " << fim << " centro: " << centrointervalo << endl;

  if (centro <= 0){
    cout << "FIM" << endl;
    return 1;
  }

 // CALCULA TODOS OS 4 SUB INTERVALOS
    calcregua(inicio, centro-1);
    calcregua(centro, (2*centro)-1 );
    calcregua(2*centro, (fim-centro)-1);
    calcregua(fim-centro, fim-1);

}

int main(int argc, char const *argv[]) {

 int n, termina;
 cin >> n;
 int inicio = 0, fim = n;
 termina = calcregua(inicio, fim);
 if (termina == 1) {
   return 0;
 }

}
