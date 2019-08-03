#include <iostream>
#include <vector>

using namespace std;
/*
int inside(int x, int a, int b)
{
	if (x >= a && x <= b)
	{
		cout << x << " in " << a << " - " << b << "\n";
		return 1;
	}

	return 0;
}*/

int main()
{
	int n, m;
	cin >> n >> m;

	vector <long long int> v(n+5);
	int a, b, k;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> k;

		v[a] += k;
		v[b+1] -= k;
	}

	long long int max = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += v[i];
		if (sum > max)
			max = sum;
	}

	cout << max;

	return 0;
}