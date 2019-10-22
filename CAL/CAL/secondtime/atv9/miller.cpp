#include <bits/stdc++.h>
using namespace std;

int power(int x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result
	x = x % p; // Update x if it is more than or
				// equal to p
	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}


bool miillerTest(int d, int n)
{
	// Pics a random number in [2..n-2]
	// Corner cases mase sure that n > 4
	int a = 2 + rand() % (n - 4);

	// Compute a^d % n
	int x = power(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	// Return composite
	return false;
}

bool isPrime(int n, int s)
{

	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;


	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	for (int i = 0; i < s; i++)
		if (!miillerTest(d, n))
			return false;

	return true;
}

// Driver program
int main()
{
	int s = 10; // Number of iterations

  int primos[] = {5953, 5981, 5987, 6007, 6011, 6883, 7607, 7649, 7669, 7757, 7879, 7901, 7727, 6679, 5801, 5099, 4073, 3581, 7541, 4751};
  int nprimos[] = {1232, 3423, 2313, 5554, 7646, 3456, 9742, 4234, 3451, 5567, 4342, 7434, 6474, 4356, 1234, 5211, 2134, 6436, 6368, 7345};

  cout << "======= S = 10 ======" << endl;

  for (int i=0; i<20; i++) {
    if(isPrime(primos[i], s)) {
      cout << primos[i] << " eh primo" << endl;
    } else {
      cout << primos[i] << " n eh primo" << endl;
      }
  }


  for (int i=0; i<20; i++) {
    if(isPrime(nprimos[i], s)) {
      cout << nprimos[i] << " eh primo" << endl;
    } else {
      cout << nprimos[i] << " n eh primo" << endl;
      }
  }

  cout << "======= S = 5 ======" << endl;

  for (int i=0; i<20; i++) {
    if(isPrime(primos[i], 5)) {
      cout << primos[i] << " eh primo" << endl;
    } else {
      cout << primos[i] << " n eh primo" << endl;
      }
  }


  for (int i=0; i<20; i++) {
    if(isPrime(nprimos[i], 5)) {
      cout << nprimos[i] << " eh primo" << endl;
    } else {
      cout << nprimos[i] << " n eh primo" << endl;
      }
  }

  cout << "======= S = 20 ======" << endl;

  for (int i=0; i<20; i++) {
    if(isPrime(primos[i], 20)) {
      cout << primos[i] << " eh primo" << endl;
    } else {
      cout << primos[i] << " n eh primo" << endl;
      }
  }


  for (int i=0; i<20; i++) {
    if(isPrime(nprimos[i], 20)) {
      cout << nprimos[i] << " eh primo" << endl;
    } else {
      cout << nprimos[i] << " n eh primo" << endl;
      }
  }



	return 0;
}
