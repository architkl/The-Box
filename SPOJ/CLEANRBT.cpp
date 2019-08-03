/*
Author: architkl
Language: C++ 11
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

const int N_MAX = 10;
const int INF = INT_MAX;

int dp[1<<N_MAX][N_MAX];

void init()
{
	for (int i = 0; i < (1<<N_MAX); i++)
		for (int j = 0; j < N_MAX; j++)
			dp[i][j] = INF;
}

int bfs(vector <string> M, pii s, pii d)
{
	bool vis[M.size()][M[0].length()];
	for (int i = 0; i < M.size(); i++)
		for (int j = 0; j < M[0].length(); j++)
			vis[i][j] = false;

	queue <pair <pii, int>> q;
	q.push(mp(s, 0));
	vis[s.first][s.second] = true;
	pair <pii, int> cur;

	// cout << M.size() << " " << M[0].length() << "\n";

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		// cout << cur.first.first << " " << cur.first.second << "\n";

		if (cur.first == d)
			return cur.second;

		if (cur.first.first+1 < M.size() && !vis[cur.first.first+1][cur.first.second] && M[cur.first.first+1][cur.first.second] != 'x')
		{
			vis[cur.first.first+1][cur.first.second] = true;
			q.push(mp(mp(cur.first.first+1, cur.first.second), cur.second+1));
			// cout << q.back().first.first << " " << q.back().first.second << "\n";
			// cout << "10" << "\n";
		}

		if (cur.first.first-1 >= 0 && !vis[cur.first.first-1][cur.first.second] && M[cur.first.first-1][cur.first.second] != 'x')
		{
			vis[cur.first.first-1][cur.first.second] = true;
			q.push(mp(mp(cur.first.first-1, cur.first.second), cur.second+1));
			// cout << q.back().first.first << " " << q.back().first.second << "\n";
			// cout << "-10" << "\n";
		}

		if (cur.first.second+1 < M[0].length() && !vis[cur.first.first][cur.first.second+1] && M[cur.first.first][cur.first.second+1] != 'x')
		{
			vis[cur.first.first][cur.first.second+1] = true;
			q.push(mp(mp(cur.first.first, cur.first.second+1), cur.second+1));
			// cout << q.back().first.first << " " << q.back().first.second << "\n";
			// cout << "01" << "\n";
		}

		if (cur.first.second-1 >= 0 && !vis[cur.first.first][cur.first.second-1] && M[cur.first.first][cur.first.second-1] != 'x')
		{
			vis[cur.first.first][cur.first.second-1] = true;
			q.push(mp(mp(cur.first.first, cur.first.second-1), cur.second+1));
			// cout << q.back().first.first << " " << q.back().first.second << "\n";
			// cout << "0-1" << "\n";
		}
	}

	return INF;
}

int solve(vector <string> M, pii s, vector <pii> dirty)
{
	for (int i = 0; i < dirty.size(); i++)
	{
		dp[(int)pow(2,i)][i] = bfs(M, s, dirty[i]);

		if (dp[(int)pow(2,i)][i] == INF)
			return -1;

		// cout << "to " << i << " " << dp[(int)pow(2,i)][i] << "\n";
	}

	// cout << "REACHABLE\n";

	for (int mask = 1; mask < (1<<dirty.size()); mask++)
	{
		// cout << mask << "\n";
		for (int i = 0; i < dirty.size(); i++)
		{
			if (!(mask & (1 << i)))
			{
				for (int j = 0; j < dirty.size(); j++)
				{
					if (mask & (1 << j))
					{
						dp[mask + (int)pow(2, i)][i] = min(dp[mask + (int)pow(2, i)][i], dp[mask][j] + bfs(M, dirty[i], dirty[j]));
					}
				}
			}
		}
	}

	int mn = dp[(1<<dirty.size())-1][0];
	for (int i = 1; i < dirty.size(); i++)
		mn = min(mn, dp[(1<<dirty.size())-1][i]);

	return mn;
}

int main()
{
	int w, h;
	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		init();

		vector <string> M(h);
		vector <pii> dirty;
		pii bot;
		for (int i = 0; i < h; i++)
		{
			cin >> M[i];

			for (int j = 0; j < w; j++)
			{
				if (M[i][j] == 'o')
					bot = mp(i, j);

				if (M[i][j] == '*')
					dirty.pb(mp(i, j));
			}
		}

		// for (int i = 0; i < h; i++)
		// 	cout << M[i] << "\n";

		cout << solve(M, bot, dirty) << "\n";
	}

	return 0;
}