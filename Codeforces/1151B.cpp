/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int t;
	vector < vector<int> > d(n);
	vector < vector<int> > idx(n);
	unordered_map <int, int> freq;
	for (int i = 0; i < n; i++)
	{
		freq.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> t;

			if (freq[t])
				continue;

			freq[t]++;
			d[i].pb(t);
			idx[i].pb(j+1);

			// cout << d[i].back() << " ";
		}
		// cout << "\n";
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans ^= d[i][0];

	if (ans)
	{
		cout << "TAK\n";
		for (int i = 0; i < n; i++)
			cout << 1 << " ";
	}

	else
	{
		int f = 0;
		for (int i = 0; i < n; i++)
		{
			if (d[i].size() > 1)
			{
				f = 1;
				break;
			}
		}

		if (f)
		{
			cout << "TAK\n";

			bool taken = false;

			for (int i = 0; i < n; i++)
			{
				if (d[i].size() > 1 && !taken)
				{
					taken = true;
					cout << idx[i][1] << " ";
				}

				else
					cout << 1 << " ";
			}
		}

		else
			cout << "NIE\n";
	}

	cout << "\n";

	return 0;
}