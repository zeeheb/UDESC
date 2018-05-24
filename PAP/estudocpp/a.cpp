#include <iostream>

using namespace std;

struct Pontos {
  double lat, longi;
  int carga;
};

template <typename T>
void swap(T *a, T *b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(int argc, char const *argv[]) {


Pontos ponto[3];
int cargaFinal = 0;
  for(int i=0;i<3;i++) {
    cin >> ponto[i].lat >> ponto[i].longi >> ponto[i].carga;
  }

  for(int i=0;i<3;i++) {
    cargaFinal = cargaFinal + ponto[i].carga;
    cout << "Parada " << i+1 << " \n Latitude: "<< ponto[i].lat << " \n Longitude: "<<
    ponto[i].longi << "\n Carga:"<<ponto[i].carga <<endl;

  }

  cout << "Carga final: " << cargaFinal << endl;
  cout << "\n\n\nEm ordem de Latitude: " << endl;

  for(int i=0;i<3;i++) {
    for(int j=2;j>i;j--) {
      if (ponto[j].lat < ponto[j-1].lat) {
        swap(&ponto[j].lat, &ponto[j-1].lat);
        }
      }
  }

  for(int i=0;i<3;i++) {
    cargaFinal = cargaFinal + ponto[i].carga;
    cout << "Parada " << i+1 << " \n Latitude: "<< ponto[i].lat << " \n Longitude: "<<
    ponto[i].longi << "\n Carga:"<<ponto[i].carga <<endl;
  }

  return 0;
}
