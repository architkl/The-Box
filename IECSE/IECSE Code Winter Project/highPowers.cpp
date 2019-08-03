#include <iostream>

using namespace std;

long long int ex(long long int a, long long int b, int m)
{
	if (b == 1)
		return a % m;

	long long int ans = ex(a, b/2, m);
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
	long long int a, b;
	int m;

	cin >> a >> b >> m;

	cout << ex(a%m, b, m);

	return 0;
}