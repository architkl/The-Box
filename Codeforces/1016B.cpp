#include <iostream>

using namespace std;

int arr[1005] = {};

int main()
{
	int n, m, q;
	cin >> n >> m >> q;

	string s, t;
	cin >> s >> t;

	for (int i = 0; i < n-m+1; i++)
	{
		bool fl = true;
		for (int j = 0; j < m; j++)
		{
			if (s[i+j] != t[j])
			{
				fl = false;
				break;
			}
		}

		arr[i+1] = arr[i] + fl;
	}

	for (int i = max(0, n-m+1); i < n; i++)
		arr[i+1] = arr[i];

	int l, r;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;

		--l;
		r -= m-1;

		printf("%d\n", l <= r ? arr[r] - arr[l] : 0);
	}

	return 0;
}