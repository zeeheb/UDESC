#include <iostream>
using namespace std;

int regua(int l, int r, int h) {
  int m;
  m = (l+r) / 2;
  cout << "i: " << l << " m: " << h << " fim: " << h << endl;
  if (h>1) {
    regua(l, m, h-1);
    regua(m, r , h-1);
  }
}

int main(int argc, char const *argv[]) {

  int alt;
  cin >> alt;

  regua(0, alt, alt);

  return 0;
}
