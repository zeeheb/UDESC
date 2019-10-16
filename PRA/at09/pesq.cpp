#include <iostream>


using namespace std;

int buscaseq(int n, int vet[]);
int buscabin(int n, int vet[]);
int busca200(int vet[]);

int main(int argc, char const *argv[]) {

  // sequencial
  int v[500000];

  for(int i=0; i<500000; i++) {
    v[i] = i;
  }

  busca200(v);
  //buscaseq(1, v);
  //buscabin(1, v);
  //buscabin(400000, v);
  //buscabin(250000, v);


  return 0;
}


int busca200(int vet[]) {
  int aux[200];
  for(int i=0; i<200; i++) {
    aux[i] = rand() % 500000;
  }

  for(int i=0;i<200;i++) {
    buscabin(aux[i], vet);
  }


}


int buscaseq(int n, int vet[]) {

  for(int i=1;i<=500000;i++) {
    if (vet[i] == n) {
      cout << "Achou" << endl;
      return 1;
    }
  }
  cout << "N achou! " << endl;
  return 0;
}

int buscabin(int n, int vet[]) {

	int i = 0;
  int f = 500000 - 1;
	int meio;
	while (i<=500000) {
		meio = (i+f)/2;
		if (vet[meio]==n) {
      cout << "Achouu" << endl;
      return meio;
		} else {
			if (n>vet[meio])
				i=meio+1;
			else
				f=meio-1;
		}
	}
	return -1;
}
