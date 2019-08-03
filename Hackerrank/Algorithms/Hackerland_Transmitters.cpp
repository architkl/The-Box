#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int X_MAX = 100000;

int min_trans(vector<int> v, int k)
{
	int start = 0, stop = X_MAX-1;
	
	while (v[start] == 0)
		start++;

	while (v[stop] == 0)
		stop--;

	int count = 0, trans_p = start + k, prev_trans = -1;
	while (trans_p <= stop)
	{
		if (v[trans_p] == 0)
		{
			while(v[trans_p] == 0 && trans_p != prev_trans)
				trans_p--;

			if (trans_p == prev_trans)
			{
				trans_p += 2*k + 1;
				while(v[trans_p] == 0)
					trans_p++;

				trans_p += k;

				continue;
			}
		}

		count++;
		prev_trans = trans_p;
		trans_p += 2*k + 1;
	}

	if (prev_trans + k < stop)
		count++;

	return count;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector <int> house(n);
	for (int i = 0; i < n; i++)
	{
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	int count = 0, i = 0, trans_p;

	while(i < n)
	{
		trans_p = house[i] + k;
		while ( (house[i] <= trans_p) && (i < n) )
			i++;

		trans_p = house[i-1] + k;
		while ( (house[i]  <= trans_p) && (i < n) )
			i++;

		count++;
	}

	cout << count << "\n";

	return 0;
}