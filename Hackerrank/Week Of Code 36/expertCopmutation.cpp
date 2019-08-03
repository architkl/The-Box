#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

/* 
	h[i] = x[i] ^ G[i-1]
	c[i] = y[i] ^ G[i-1]
	l[i] = z[i] ^ G[i-1]

	F[i] = max(h[j] * c[i] - c[j] * h[i])
	0 <= j <= i - l[i]

	G[u] = for(i in 0 : u) F[i] % int(pow(10, 9) + 7)
*/

int main()
{
	int n;
	cin >> n;

	vector <int> x(n), y(n), z(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
	for (int i = 0; i < n; i++)
		cin >> z[i];

	vector <int> h(n), c(n), l(n);
	vector <long long int> G(n), F(n);
	h[0] = x[0];
	c[0] = y[0];
	l[0] = z[0];
	F[0] = 0;
	G[0] = 0;
	for (int i = 1; i < n; i++)
	{
		h[i] = x[i] ^ G[i-1];
		c[i] = y[i] ^ G[i-1];
		l[i] = z[i] ^ G[i-1];

		long long int temp;
		F[i] = h[0] * c[i] - c[0] * h[i];
		for (int j = 1; j <= min(i - l[i], i); j++)
		{
			temp = h[j] * c[i] - c[j] * h[i];

			if (temp > F[i])
				F[i] = temp;
		}

		for (int j = 0; j <= i; j++)
		{
			G[i] += F[j];
		}
		G[i] %= int(pow(10, 9) + 7);
	}

	cout << G[n-1] << "\n";

	return 0;
}