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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	string s;
	vector < vector <ll> > G(n+1, vector <ll> (n+1));
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= n; j++)
		{
			G[i][j] = s[j-1] - 48;

			if (G[i][j] == 0)
				G[i][j] = INT_MAX;
		}
	}

	int m;
	cin >> m;

	vector <int> p(m);
	for (int i = 0; i < m; i++)
		cin >> p[i];

	for (int k = 1; k <= n ; k++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (G[i][k] + G[k][j] < G[i][j])
					G[i][j] = G[i][k] + G[k][j];

	vector <int> ans;
	ans.pb(0);
	for (int i = 1; i < m; i++)
	{
		if (G[p[ans.back()]][p[i]] < i-ans.back() || p[ans.back()] == p[i])
			ans.pb(i-1);
	}

	ans.pb(m-1);

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++)
		cout << p[ans[i]] << " ";

	cout << "\n";

	return 0;
}