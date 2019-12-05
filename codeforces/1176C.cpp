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

	int n;
	cin >> n;

	vector <int> a(n);
	vector < set <int> > idx(6, set <int> ());
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] == 4)
			idx[0].insert(i);

		else if (a[i] == 8)
			idx[1].insert(i);

		else if (a[i] == 15)
			idx[2].insert(i);

		else if (a[i] == 16)
			idx[3].insert(i);

		else if (a[i] == 23)
			idx[4].insert(i);

		else
			idx[5].insert(i);
	}

	bool mark[n+1] = {};
	set <int>::iterator it[5];
	for (auto i : idx[0])
	{
		it[0] = idx[1].lower_bound(i);
		if (it[0] == idx[1].end())
			break;

		it[1] = idx[2].lower_bound(*it[0]);
		if (it[1] == idx[2].end())
			break;

		it[2] = idx[3].lower_bound(*it[1]);
		if (it[2] == idx[3].end())
			break;

		it[3] = idx[4].lower_bound(*it[2]);
		if (it[3] == idx[4].end())
			break;

		it[4] = idx[5].lower_bound(*it[3]);
		if (it[4] == idx[5].end())
			break;

		mark[i] = 1;
		for (int j = 0; j < 5; j++)
		{
			mark[*it[j]] = 1;
			idx[j+1].erase(it[j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += !(mark[i]);

	cout << ans << "\n";

	return 0;
}