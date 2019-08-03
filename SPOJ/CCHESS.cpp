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
typedef pair <int, pii> piii;
typedef unsigned long long ull;

const int size = 8;
const int INF = INT_MAX;

int wt[size][size][size][size];

bool vis[size][size];

void init()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				for (int l = 0; l < size; l++)
					wt[i][j][k][l] = i*k + j*l;

/*	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			vis[i][j] = false;*/
}

bool comp(piii a, piii b)
{
	return (a.first > b.first);
}

// int dijkstra(int sx, int sy, int dx, int dy)
// {
// 	vector <vector <int>> dist(size, vector <int> (size, INF));

// 	int movex[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// 	int movey[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	
// 	bool (*comp_pt)(piii, piii) = comp;
// 	set <piii, bool(*)(piii, piii)> q(comp_pt);

// 	q.insert(mp(0, mp(sx, sy)));
// 	dist[sx][sy] = 0;
// 	piii cur;
// 	int curx, cury, temp;

// 	while (!q.empty())
// 	{
// 		cur = *(q.begin());
// 		q.erase(q.begin());

// 		curx = cur.second.first;
// 		cury = cur.second.second;

// 		cout << "(" << curx << ", " << cury << ")" << ": ";

// 		for (int i = 0; i < 8; i++)
// 		{
// 			if (curx + movex[i] >= size || curx + movex[i] < 0)
// 				continue;

// 			if (cury + movey[i] >= size || cury + movey[i] < 0)
// 				continue;

// 			temp = cur.first + wt[curx][cury][curx+movex[i]][cury+movey[i]];
// 			if (temp < dist[curx+movex[i]][cury+movey[i]])
// 			{
// 				if (dist[curx+movex[i]][cury+movey[i]] != INF)
// 					q.erase(q.find(mp(dist[curx+movex[i]][cury+movey[i]], mp(curx+movex[i], cury+movey[i]))));

// 				cout << "(" << curx + movex[i] << ", " << cury + movey[i] << ") (" << temp << ") ";

// 				dist[curx+movex[i]][cury+movey[i]] = temp;
// 				q.insert(mp(dist[curx+movex[i]][cury+movey[i]], mp(curx+movex[i], cury+movey[i])));
// 			}
// 		}
// 		cout << "\n";
// 	}

// 	for (int i = 0; i < size; i++)
// 		for (int j = 0; j < size; j++)
// 			cout << "(" << i << ", " << j << ") " << dist[i][j] << "\n";

// 	return dist[dx][dy];
// }

int dijkstra(int sx, int sy, int dx, int dy)
{
	vector <vector <int>> dist(size, vector <int> (size, INF));

	int movex[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int movey[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	
	bool (*comp_pt)(piii, piii) = comp;
	priority_queue <piii, vector <piii>, bool(*)(piii, piii)> q(comp_pt);

	q.push(mp(0, mp(sx, sy)));
	dist[sx][sy] = 0;
	piii cur;
	int curx, cury, temp;

	while (!q.empty())
	{
		cur = q.top();
		q.pop();

		curx = cur.second.first;
		cury = cur.second.second;

		/*if (vis[curx][cury])
			continue;

		vis[curx][cury] = true;*/

		// cout << "(" << curx << ", " << cury << ")" << ": " << cur.first << "\n";

		if (curx == dx && cury == dy)
			return cur.first;

		for (int i = 0; i < 8; i++)
		{
			if (curx + movex[i] >= size || curx + movex[i] < 0)
				continue;

			if (cury + movey[i] >= size || cury + movey[i] < 0)
				continue;

			/*if (vis[curx+movex[i]][cury+movey[i]])
				continue;*/

			temp = cur.first + wt[curx][cury][curx+movex[i]][cury+movey[i]];
			if (temp < dist[curx+movex[i]][cury+movey[i]])
			{
				// cout << "(" << curx + movex[i] << ", " << cury + movey[i] << ") (" << temp << ") ";

				dist[curx+movex[i]][cury+movey[i]] = temp;
				q.push(mp(dist[curx+movex[i]][cury+movey[i]], mp(curx+movex[i], cury+movey[i])));
			}
		}
		// cout << "\n";
	}

	// for (int i = 0; i < size; i++)
	// 	for (int j = 0; j < size; j++)
	// 		cout << "(" << i << ", " << j << ") " << dist[i][j] << "\n";

	return -1;
}

int main()
{
	// freopen("file.txt", "r", stdin);
	// freopen("mysol.txt", "w", stdout);

	init();

	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) > 0)
	{
		// cin >> a >> b >> c >> d;

		cout << dijkstra(a, b, c, d) << "\n";
	}

/*	freopen("file.txt", "w", stdout);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
				for (int l = 0; l < 8; l++)
					cout << i << " " << j << " " << k << " " << l << "\n";
*/
	return 0;
}