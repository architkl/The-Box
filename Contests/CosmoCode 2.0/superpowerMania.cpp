#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int find(vector <int> v, int x)
{
	for (int i = v.size()-1; i >= 0; i--)
	{
		if (v[i] <= x)
			return (i+1);
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int mn = *min_element(A.begin(), A.end());
	map <int, int> mymap;

	for (int i = 0; i < n; i++)
	{
		mymap[A[i]] = i+1;
	}

	int q, x;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x;

		if (x < mn)
			cout << -1 << "\n";

		else
		{
			while (mymap[x-1] > mymap[x] && mymap)
		}
	}

	return 0;
}