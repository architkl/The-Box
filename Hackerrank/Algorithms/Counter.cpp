#include <iostream>

using namespace std;

int no_of_bits(unsigned long long int x)
{
	int n = 0;
	while (x)
	{
		x >>= 1;
		//cout << x << " ";
		n++;
	}
	//cout << n;
	return n;
}

int main()
{
	int T;
	cin >> T;

	unsigned long long int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		//cout << no_of_bits(N) << "\n";
		int win = 1;
		while (N != 1)
		{
			if ((N & (N-1)) == 0)
				N /= 2;

			else
				N -= ((unsigned long long)1 << (no_of_bits(N) - 1));
			
			win *= -1;

			cout << N << "\n";
		}

		if (win == 1)
			cout << "Richard\n";

		else
			cout << "Louise\n";
	}

	return 0;
}