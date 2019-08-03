#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

long long int lcm(long long int a, long long int b)
{
	return (a*b) / gcd(a, b);
}

int main()
{
	int T;
	cin >> T;

	long long int a, b;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;

		cout << lcm(a, b) << "\n";
	}

	return 0;
}