#include <iostream>
#include <vector>


int main(int argc, char const *argv[]) {

int a, b;

std::cin >> a >> b;

int i, count = 1;
for (i=0; i<b; i++) {
  count = count * a;
}

std::cout << " Total: " << count << std::endl;

  return 0;
}
