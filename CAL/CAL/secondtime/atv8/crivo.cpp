#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


void primos(int N)
{


	int limite = floor(sqrt(N));
	vector<int> vet(N);

	int tam, num;
	for(num = 2, tam = 0; num <= N; num++, tam++)
		vet[tam] = num;

	int removeu, i = 0;
	while(1)
	{
		removeu = 0;
		if(vet[i] != -1)
			num = vet[i];
		else
		{
			i++;
			continue;
		}
		int j;
		for(j = i + 1; j < tam; j++)
		{
			if(vet[j] % num == 0)
			{
				vet[j] = -1;
				removeu = 1;
			}
		}
		if(removeu == 0 || vet[i] == limite)
			break;
		i++;
	}

	for(i = 0; i < tam; i++)
	{
		if(vet[i] != -1)
		{
			cout << vet[i] << " ";
		}
	}
  cout << endl;
}

int main(int argc, char *argv[])
{
	primos(500);
	return 0;
}
