#include <iostream>

using namespace std;

const int K = 1e9 + 7;

int ex(long long int a, long long int b, int m)
{
	if (b == 0)
		return 1;

	long long int res = ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int main()
{
	int t;
	cin >> t;

	long long int n, ans;
	for (int i = 0; i < t; i++)
	{
		cin >> n;

		ans = ex(2, n, K) - 1;

		if (ans < 0)
			ans += K;

		cout << ans << "\n";
	}

	return 0;
}