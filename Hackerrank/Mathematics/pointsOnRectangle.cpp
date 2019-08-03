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
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	int n;
	while (q--)
	{
		cin >> n;

		vector <pii> point(n);
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			point[i] = mp(x, y);
		}

		int x_min, x_max, y_min, y_max;
		x_min = x_max = point[0].first;
		y_min = y_max = point[0].second;

		for (int i = 1; i < point.size(); i++)
		{
			if (point[i].first < x_min)
				x_min = point[i].first;

			else if (point[i].first > x_max)
				x_max = point[i].first;

			if (point[i].second < y_min)
				y_min = point[i].second;

			else if (point[i].second > y_max)
				y_max = point[i].second;
		}

		bool f;
		for (int i = 0; i < n; i++)
		{
			f = 0;
			
			if (point[i].first == x_min || point[i].first == x_max || point[i].second == y_min || point[i].second == y_max)
				f = 1;

			if (!f)
				break;
		}

		if (!f)
			cout << "NO\n";

		else
			cout << "YES\n";
	}

	return 0;
}