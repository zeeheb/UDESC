#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	int i;
	ofstream out("crescente.txt");
  for (i = 0; i < 100000; i++){
    out << i << std::endl;
  }
	out.close();

	return 0;
}
