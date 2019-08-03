#include <iostream>
#include <math.h>

using namespace std;

bool prime[750020];

void sieve()
{
	prime[0] = prime[1] = 0;

	for (int i = 2; i < 750020; i++)
		prime[i] = 1;
	
	for (int i = 2; i < 750020; i++)
	{
		if (!prime[i])
			continue;

		for (int j = 2*i; j < 750020; j += i)
		{
			prime[j] = 0;
		}
	}
}

int main()
{
	int L, R;
	cin >> L >> R;

	sieve();

	long long int ans = 1, mod;
	for (mod = R+1; prime[mod] == 0; mod++);

	for (int i = L; i <= R; i++)
	{
		if (prime[i])
		{
			ans *= i;
			ans %= mod;
		}
	}

	cout << ans;

	return 0;
}