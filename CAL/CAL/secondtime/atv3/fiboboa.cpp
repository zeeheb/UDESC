#include <iostream>

using namespace std;

int fib(int n)
{
  int f[n+1];
  int i;

  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main ()
{
  int aux;
  cout << "Digite um numero: " << endl;
  cin >> aux;

  int resul = fib(aux);
  cout << "Resultado: " << resul << endl;

}
