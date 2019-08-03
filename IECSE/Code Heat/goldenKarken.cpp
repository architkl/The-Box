#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, k, p;
	cin >> n >> k >> p;

	int a;
	long long int PRE[n+1] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		PRE[i+1] = (PRE[i] + a) % p;
	}

	long long int mn = 1000000000000;
	set <long long int> S;
	set <long long int>::iterator it;
	S.insert(0);

	for (int i = 1; i <= n; i++)
	{
		if (PRE[i] >= k)
			mn = min(mn, PRE[i]);

		it = S.lower_bound(PRE[i] - k);

		if (it != S.end())
			if (PRE[i] - *it >= k)
				mn = min(mn, PRE[i] - *it + p);

		S.insert(PRE[i]);
	}

	cout << mn << "\n";

	return 0;
}