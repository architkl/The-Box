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

	int N;
	cin >> N;

	int X, t;
	vector < stack <int> > S(N);
	vector < multiset <int> > bst(N);

	for (int i = 0; i < N; i++)
	{
		cin >> X;

		while (X--)
		{
			cin >> t;

			S[i].push(t);
			bst[i].insert(t);
		}
	}

	int Q;
	cin >> Q;

	int v, k, h;
	while (Q--)
	{
		cin >> v;

		if (v == 1)
		{
			cin >> k >> h;
			k--;

			S[k].push(h);
			bst[k].insert(h);
		}

		else if (v == 0)
		{
			cin >> k;
			k--;

			bst[k].erase(bst[k].find(S[k].top()));
			S[k].pop();
		}

		else
		{
			bool f = 1;
			multiset <int>::iterator it;

			int val = 0;
			for (int i = 0; i < N; i++)
			{
				if (bst[i].empty())
				{
					f = 0;
					break;
				}

				it = bst[i].upper_bound(val);

				if (it == bst[i].end())
				{
					f = 0;
					break;
				}

				val = *it;
			}

			f ? cout << "YES\n" : cout << "NO\n";
		}
	}

	return 0;
}