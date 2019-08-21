#include <iostream>

int fib (int n) {
  if ( n == 0 || n == 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

using namespace std;

int main(int argc, char const *argv[]) {

int aux;
cout << "Digite um número: " << endl;
cin >> aux;
int resul;

resul = fib(aux);
cout << "Resultado: " << resul << endl;


  return 0;
}
