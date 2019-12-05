#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int sum = 0, turn[n];
	for (int i = 0; i < n; i++)
	{
		sum += a[i];

		turn[i] = sum / m;

		sum -= turn[i] * m;

		cout << turn[i] << " ";
	}

	cout << "\n";

	return 0;
}