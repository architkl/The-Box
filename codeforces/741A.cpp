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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

const int N_MAX = 105;

vector <bool> vis(N_MAX);
vector <int> crush(N_MAX);

int dfs(int start)
{
	int cur = start, steps = 0;

	while (!vis[cur])
	{
		vis[cur] = true;
		steps++;
		cur = crush[cur];
	}

	if (cur != start)
		return -1;

	return steps;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> crush[i];

	vector <int> joon;
	bool f = 1;
	int temp;

	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;

		temp = dfs(i);

		if (temp == -1)
		{
			f = 0;
			break;
		}

		joon.pb(temp);
	}

	if (f)
	{
		for (auto &i : joon)
		{
			if (i % 2 == 0)
				i /= 2;
		}

		int ans = joon[0];
		for (int i = 1; i < joon.size(); i++)
			ans = (ans*joon[i]) / __gcd(ans, joon[i]);
		
		cout << ans << "\n";
	}

	else
		cout << -1 << "\n";

	return 0;
}