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

const int N_MAX = 30;

bool vis[N_MAX][N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		for (int j = 0; j < N_MAX; j++)
			vis[i][j] = false;
}

bool isValid(int x, int y, int n)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;

	return true;
}

int bfs(int a, int b, int n)
{
	int mov_x[8] = {-a, -b, b, a, a, b, -b, -a};
	int mov_y[8] = {b, a, a, b, -b, -a, -a, -b};

	queue < pair <pii, int> > myQ;
	myQ.push(mp(mp(0, 0), 0));

	pair <pii, int> cur;
	while (!myQ.empty())
	{
		cur = myQ.front();
		myQ.pop();

		if (cur.first.first == n-1 && cur.first.second == n-1)
			return cur.second;

		int next_x, next_y;
		for (int i = 0; i < 8; i++)
		{
			next_x = cur.first.first + mov_x[i];
			next_y = cur.first.second + mov_y[i];

			if (isValid(next_x, next_y, n) && !vis[next_x][next_y])
			{
				myQ.push(mp(mp(next_x, next_y), cur.second + 1));
				vis[next_x][next_y] = true;
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			init();

			ans = bfs(i, j, n);

			if (!ans)
				cout << 1 << " ";

			else
				cout << ans << " ";
		}

		cout << "\n";
	}

	return 0;
}