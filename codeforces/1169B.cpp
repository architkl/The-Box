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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 3e5 + 5;

int main()
{
	int n, m;
	cin >> n >> m;

	vector <pii> a(m);
	int x, y, t;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		if (x > y)
		{
			t = x;
			x = y;
			y = t;
		}

		a[i] = mp(x, y);
	}

	x = a[0].first;
	y = a[0].second;

	vector <pii> arr1, arr2;

	// cout << "\n\n";
	for (int i = 1; i < m; i++)
	{
		if (a[i].first != x && a[i].second != x)
		{
			arr1.pb(a[i]);
			// cout << a[i].first << " " << a[i].second << "\n";
		}
	}

	// cout << "\n\n";
	for (int i = 1; i < m; i++)
	{
		if (a[i].first != y && a[i].second != y)
		{
			arr2.pb(a[i]);
			// cout << a[i].first << " " << a[i].second << "\n";
		}
	}
	
	if (arr1.size() == 0)
		cout << "YES\n";

	else
	{
		int u = arr1[0].first, v = arr1[0].second;
		bool f1 = 1, f2 = 1;

		for (int i = 0; i < arr1.size(); i++)
		{
			// cout << i << "\n";
			if (arr1[i].first != u && arr1[i].second != u)
				f1 = 0;

			if (arr1[i].first != v && arr1[i].second != v)
				f2 = 0;

			if (!f1 && !f2)
				break;
		}

		if (f1 || f2)
			cout << "YES\n";

		else if (arr2.size() == 0)
			cout << "YES\n";

		else
		{
			f1 = f2 = 1;
			u = arr2[0].first;
			v = arr2[0].second;

			for (int i = 0; i < arr2.size(); i++)
			{
				if (arr2[i].first != u && arr2[i].second != u)
				{
					// cout << u << "end\n";
					f1 = 0;
				}

				if (arr2[i].first != v && arr2[i].second != v)
				{
					// cout << v << "end\n";
					f2 = 0;
				}

				if (!f1 && !f2)
					break;
			}

			if (f1 || f2)
				cout << "YES\n";

			else
				cout << "NO\n";
		}
	}

	return 0;
}