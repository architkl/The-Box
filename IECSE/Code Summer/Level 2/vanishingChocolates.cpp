#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

const long long int K = pow(10, 9) + 7;

long long int bi_exp(int a, long long int b, long long int m)
{
	if (b == 1)
		return a % m;

	long long int ans = bi_exp(a, b / 2, m);
	ans *= ans;
	ans %= m;

	if (b % 2)
	{
		ans *= a;
		ans %= m;
	}

	return ans;
}

int main()
{
	long long int x, k;

	cin >> x >> k;

	x %= K;

	if (k == 0)
	{
		cout << (x * 2) % K << "\n";
		exit(0);
	}
	
	long long int a = x * bi_exp(2, k+1, K), n = bi_exp(2, k, K);
	a %= K;
	n %= K;
	cout << a << " " << n << "\n";

	long long int S = a;
	S -= (n-1);

	if (S < 0)
		S += K;

	cout << S << "\n";

	return 0;
}