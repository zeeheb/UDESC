#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{

	ofstream out("entrada.txt");
  for(int i=0; i<500000; i++) {
    out << i << endl;
  }
	out.close();

	return 0;
}
