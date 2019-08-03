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

const int N_MAX = 10;

bool vis[N_MAX][N_MAX];
int dist[N_MAX][N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		for (int j = 0; j < N_MAX; j++)
		{
			vis[i][j] = false;
			dist[i][j] = -1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	// cin >> T;

	int R, C, K;
	while (T--)
	{
		cin >> K >> R >> C;

		init();

		queue <pii> myQ;
		pii cur;
		myQ.push(mp(R, C));
		vis[R][C] = true;
		dist[R][C] = 0;

		while (!myQ.empty())
		{
			cur = myQ.front();

			myQ.pop();

			// cout << "(" << cur.first << ", " << cur.second << ")" << "\n";

			if (dist[cur.first][cur.second] > K)
				break;

			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if ((cur.first + i > 0 && cur.first + i < 9) && (cur.second + j > 0 && cur.second + j < 9))
					{
						if (vis[cur.first+i][cur.second+j])
							continue;

						vis[cur.first+i][cur.second+j] = true;
						dist[cur.first+i][cur.second+j] = dist[cur.first][cur.second] + 1;
						myQ.push(mp(cur.first+i, cur.second+j));
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (vis[i][j] && dist[i][j] <= K)
				{
					// cout << 1 << " ";
					ans++;
				}

				// else
				// 	cout << 0 << " ";
			}
			// cout << "\n";
		}

		cout << ans - 1 << "\n";
	}

	return 0;
}