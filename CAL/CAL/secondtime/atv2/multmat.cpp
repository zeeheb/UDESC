#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

int m1[3][3] = { 1, 2, 3,
                 4, 5, 6,
                 7, 8 ,9 },
m2[3][3] = { 9, 8 ,7,
             6, 5, 4,
             3, 2, 1 };

int m3[3][3];
int i, j, k, sum = 0;

for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				sum += m1[i][k] * m2[k][j];
			}
			m3[i][j]=sum;
			sum=0;
		}
	}

cout << " Matriz 3: " << endl;
  	for(i=0; i<3; i++)
  	{
  		for(j=0; j<3; j++)
  		{
  			cout << m3[i][j] << " ";
  		}
  		cout << endl;
  	}


  return 0;
}
