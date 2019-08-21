#include <iostream>

using namespace std;

int calcregua(int inicio, int fim) {

  float centro = (fim - inicio)/2;
  float centrointervalo = inicio + centro;
  cout << "Inicio: " << inicio << " Fim: " << fim << " centro: " << centrointervalo << endl;

  if (centro <= 0){
    cout << "FIM" << endl;
    return 1;
  }

    calcregua(centrointervalo, fim-1);
    calcregua(inicio, centrointervalo-1);

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
