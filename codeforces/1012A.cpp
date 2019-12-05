#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int A_MAX = 1e9 + 5;

int min_segdiff(vector <int> a)
{
	int n = a.size() / 2, diff = A_MAX;

	for (int i = 1; i <= n-1; i++)
	{
		if (a[i+n-1] - a[i] < diff)
			diff = a[i+n-1] - a[i];
	}

	return diff;
}

int main()
{
	int n;
	cin >> n;

	vector <int> a(2*n);
	for (int i = 0; i < 2*n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	long long int ar1, ar2;
	ar1 = (long long)(a[2*n-1] - a[0]) * min_segdiff(a);
	ar2 = (long long)(a[2*n-1] - a[n]) * (a[n-1] - a[0]);

	cout << min(ar1, ar2) << "\n";

	return 0;
}