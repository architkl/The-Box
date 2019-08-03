#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
	return (y == 0) ? x : gcd(y, x % y);
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	long long int ans = 0;

	return 0;
}