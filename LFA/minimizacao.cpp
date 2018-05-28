#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

#define MARCADO 1
#define NAOMARCADO 0


using namespace std;

int main(int argc, char const *argv[]) {

  int nroEstados, tamAlfabeto, qtEF,  estInicial;
  cin >> nroEstados >> tamAlfabeto >> qtEF >> estInicial;

  vector<int> estMarcado;
  vector<int> estNaoMarcados;
  vector<int> estFinais;

  for(int i=0; i<qtEF; i++) { // adicionando estados finais em vector
    int aux;
    cin >> aux;
    estFinais.push_back(aux);
  }


  pair<char, pair<int,int> > tabelaTransicao[20]; // parear estados com alfabeto

  for(int i=0; i<nroEstados*tamAlfabeto; i++) {
    int aux, aux2;
    char auxchar;
    cin >> aux >> auxchar >> aux2;
      tabelaTransicao[i] = make_pair(auxchar, make_pair(aux, aux2));
  }


vector<int> estados;
  for(int i=0; i<nroEstados; i++) {
    estados.push_back(i);
  }


  pair<int, pair<int, int> > tabelaMini[20]; // tabela para minimizar, ex: par<MARCADO, (1, 0)>

  for(int i=0; i<nroEstados; i++) {
    for(int j=0;j<nroEstados; j++) {
      if(((i != j) || (i < j)) && (i < j) ) { //caso iguais ou parte de cima da matriz, break, para nao duplicar tabela
          cout << estados[i] << " e " << estados[j] << "\n ";
          vector<int>::iterator it;
           it = find(estFinais.begin(), estFinais.end(), estados[i]);
            if(it != estFinais.end()) { //encontrou o estado em estados finais
               vector<int>::iterator it2;
                it2 = find(estFinais.begin(), estFinais.end(), estados[j]);
                if( it2 == estFinais.end()) { //e nao achou o segundo estado como final
                  tabelaMini[i] = make_pair(MARCADO, make_pair(estados[i], estados[j]));
              } else {
                tabelaMini[i] = make_pair(NAOMARCADO, make_pair(estados[i], estados[j]));
              }
          } 
      }
    }
  }





// ======================== DEBUG ==============================
// =============================================================
  cout << "\nEstados: ";
    for(int i=0; i<nroEstados; i++){
      cout << estados[i] << " " ;
    }

  cout << "\n\nTransições: \n";
    for(int i=0; i<nroEstados*tamAlfabeto; i++) {
      cout << "Estado " << tabelaTransicao[i].second.first << " lendo " << tabelaTransicao[i].first
      << " = " << tabelaTransicao[i].second.second << endl;
    }

  cout << "Estados finais: ";
    for (int i=0; i<qtEF; i++) {
      cout << estFinais[i] << " ";
    }

  cout << "\n\nEstados com X: \n";
    for(int i=0; i<nroEstados*3; i++) {
      cout << tabelaMini[i].second.first << " com " << tabelaMini[i].second.second <<
      " = " << tabelaMini[i].first << endl;
    }

  cout << "\nEstado inicial: " << estInicial << endl << endl;
// ==============================================================
// ==============================================================

  return 0;
}
