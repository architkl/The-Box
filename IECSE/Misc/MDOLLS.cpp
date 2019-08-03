/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

bool mycomp(pii a, pii b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int m;
	while (t--)
	{
		cin >> m;

		vector <pii> dim(m);
		int w, h;
		for (int i = 0; i < m; i++)
		{
			cin >> w >> h;

			dim[i] = mp(w, h);
		}

		sort(dim.begin(), dim.end(), mycomp);

		vector <pii> lis;
		lis.pb(dim[0]);
		int l, r, mid;
		for (int i = 1; i < m; i++)
		{
			l = 0;
			r = lis.size()-1;

			while (l <= r)
			{
				mid = (l+r) / 2;

				if (lis[mid].second > dim[i].second)
					r = mid - 1;

				else
					l = mid + 1;
			}

			if (l == lis.size())
				lis.pb(dim[i]);

			else
				lis[l] = dim[i];
		}

		cout << lis.size() << "\n";
	}

	return 0;
}

/*
10 10 20 30 39 51 40 50

10 10
20 30
18 50
40 50
37 5
039 51

10 10
18 50
20 30
37 50
39 51
40 50
*/