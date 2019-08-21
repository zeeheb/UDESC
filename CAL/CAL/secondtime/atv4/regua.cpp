#include <iostream>

using namespace std;

int calcregua(int inicio, int fim) {

  int centro = (fim - inicio)/2;
  cout << "Inicio: " << inicio << " Fim: " << fim << " centro: " << centro << endl;

  if (centro < 1){
    cout << "FIM" << endl;
    return 1;
  }

    calcregua(centro, fim);
    calcregua(inicio, centro);


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
