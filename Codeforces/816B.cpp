#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200005;

int main()
{
	int n, k, q;
	cin >> n >> k >> q;

	vector <int> c(MAX);
	int a, b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		c[a]++;
		c[b+1]--;
	}

	for (int i = 1; i < MAX; i++)
		c[i] += c[i-1];
	
	if (c[0] >= k)
		c[0] = 1;
	
	else
		c[0] = 0;

	for (int i = 1; i < MAX; i++)
	{
		if (c[i] >= k)
			c[i] = 1;

		else
			c[i] = 0;

		c[i] += c[i-1];
	}

	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;

		cout << c[b] - c[a-1] << "\n";
	}

	return 0;
}