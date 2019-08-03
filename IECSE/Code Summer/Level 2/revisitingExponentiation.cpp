#include <iostream>
#include <math.h>

using namespace std;

int bi_exp(int a, long long int b, int m)
{
	if (b == 1)
		return a % m;

	int ans = bi_exp(a, b / 2, m);
	ans *= ans;
	ans %= 10;

	if (b % 2)
	{
		ans *= a;
		ans %= 10;
	}

	return ans;
}

int main()
{
	string A;
	long long int b;

	cin >> A >> b;

	int a = A[A.length() - 1] - 48;

	cout << bi_exp(a, b, 10) << "\n";

	return 0;
}