#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100005;

int main()
{
	int n, x;
	cin >> n >> x;

	vector <int> a(n), H(MAX, -3);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (H[a[i]] == -3)
			H[a[i]] = 0;

		H[a[i]]++;

		if (H[a[i]] == 2)
		{
			cout << 0 << "\n";
			return 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if ((a[i] & x) == a[i])
			continue;

		H[a[i] & x]++;

		if (H[a[i] & x] == 2)
		{
			cout << 1 << "\n";
			return 0;
		}

		if (H[a[i] & x] == -1)
		{
			ans = 2;
			H[a[i] & x]--;
		}
	}

	if (ans == 0)
		cout << -1 << "\n";

	else
		cout << 2 << "\n";

	return 0;
}