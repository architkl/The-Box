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

int mod_ex(int a, int b, int m)
{
	if (b == 0)
		return 1;

	long long int res = mod_ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int G;
	while (T--)
	{
		cin >> G;

		// vector <int> s(G), e(G);
		// for (int i = 0; i < G; i++)
		// 	cin >> s[i];

		// for (int i = 0; i < G; i++)
		// 	cin >> e[i];

		vector <pii> V(2*G);
		int t;
		for (int i = 0; i < G; i++)
		{
			cin >> t;
			V[i] = mp(t, 1);
		}

		for (int i = G; i < 2*G; i++)
		{
			cin >> t;
			V[i] = mp(t, -1);
		}

		sort(V.begin(), V.end());
		// for (auto i:V)
		// 	cout << i.first << " " << i.second << "\n";
		// cout << "\n";

		int ans = 0, temp = 0;
		for (int i = 0; i < 2*G; i++)
		{
			if (V[i].first == V[i+1].first)
			{
				int j = i;
				// cout << V[j].second << "\n";
				temp += V[j].second;
				// cout << temp << " " << i << "\n";
				while (j < 2*G && V[j].first == V[j+1].first)
				{
					temp += V[j+1].second;
					// cout << temp << "  ";
					j++;
				}

				ans = max(ans, temp);
				// cout << ans << " ";
				i = j;
				continue;
			}

			temp += V[i].second;
			ans = max(ans, temp);
		}
		// cout << temp << "\n";;

		cout << ans << "\n";
	}

	return 0;
}