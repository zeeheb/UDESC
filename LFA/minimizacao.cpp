#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>


using namespace std;

int main(int argc, char const *argv[]) {

  int nroEstados, tamAlfabeto, qtEF,  estInicial;
  cin >> nroEstados >> tamAlfabeto >> qtEF >> estInicial;

  vector<int> estMarcado;
  vector<int> estNaoMarcados;
  vector<int> estFinais;

  for(int i=0; i<qtEF; i++) {
    int aux;
    cin >> aux;
    estFinais.push_back(aux);
  }

  pair<char, pair<int,int> > tabela[20];

  for(int i=0; i<nroEstados*tamAlfabeto; i++) {
    int aux, aux2;
    char auxchar;
    cin >> aux >> auxchar >> aux2;
      tabela[i] = make_pair(auxchar, make_pair(aux, aux2));
  }

// ======================== DEBUG ==============================
// =============================================================
  cout << "Transições: \n";
    for(int i=0; i<nroEstados*tamAlfabeto; i++) {
      cout << "Estado " << tabela[i].second.first << " lendo " << tabela[i].first
      << " = " << tabela[i].second.second << endl;
    }

  cout << "Estados finais: ";
    for (int i=0; i<qtEF; i++) {
      cout << estFinais[i] << " ";
    }

  cout << "\nEstado inicial: " << estInicial << endl;
// ==============================================================
// ==============================================================

  return 0;
}
