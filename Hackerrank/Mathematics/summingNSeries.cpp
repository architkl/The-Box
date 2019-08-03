#include <iostream>
#include <math.h>

using namespace std;

const int K = pow(10, 9) + 7;

int main()
{
	int T;
	cin >> T;

	long long int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		cout << ((n % K) * (n % K)) % K << "\n";
	}

	return 0;
}