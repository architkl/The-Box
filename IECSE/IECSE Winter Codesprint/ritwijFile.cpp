#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> hd(n);
	for (int i = 0; i < n; i++)
		cin >> hd[i];

	sort(hd.begin(), hd.end());

	int count = 0;
	for (int i = n-1; i >= 0; i--)
	{
		m -= hd[i];
		count++;

		if (m <= 0)
			break;
	}

	cout << count;

	return 0;
}