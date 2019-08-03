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

	int n, q;
	cin >> n >> q;

	string wou;
	cin >> wou;

	vector <int> r[3];
	set <int> idx[26];

	for (int i = 0; i < n; i++)
		idx[wou[i]-97].insert(i+1);

	string query;
	for (int i = 0; i < q; i++)
	{
		getline(cin, query);

		if (query[0] == '+')
		{
			auto it = idx[query[4]-97].upper_bound(r[query[2]].back());

			if (it == idx[query[4]-97].end())
			{
				cout << "NO\n";
			}

			else
			{
				r[query[2]-48].pb(*it);
				cout << "YES\n";
			}
		}

		else
		{
			
		}
	}

	return 0;
}