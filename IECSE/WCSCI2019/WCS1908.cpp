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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

bool vis[9][9];

void init() {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) vis[i][j] = false;
}

int bfs_rook(int x1, int y1, int x2, int y2) {
	queue <piii> q;
	q.push(mp(0, mp(x1, y1)));

	piii cur;
	int x, y;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.second == mp(x2, y2)) return cur.first;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i*j != 0 || (i == 0 && j == 0)) continue;

				x = cur.second.first;
				y = cur.second.second;

				x += i;
				y += j;
				while (x > 0 && y > 0 && x < 9 && y < 9) {
					if (vis[x][y]) {
						x += i;
						y += j;
						continue;
					}

					q.push(mp(cur.first+1, mp(x, y)));
					vis[x][y] = true;
				}
			}
		}
	}

	return 0;
}

int bfs_bishop(int x1, int y1, int x2, int y2) {
	queue <piii> q;
	q.push(mp(0, mp(x1, y1)));

	piii cur;
	int x, y;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.second == mp(x2, y2)) return cur.first;

		x = cur.second.first;
		y = cur.second.second;

		for (int i = -1; i <= 1; i++) {
			if (i == 0) continue;
			for (int j = -1; j <= 1; j++) {
				if (j == 0) continue;

				x = cur.second.first;
				y = cur.second.second;

				x += i;
				y += j;
				while (x > 0 && y > 0 && x < 9 && y < 9) {
					if (vis[x][y]) {
						x += i;
						y += j;
						continue;
					}

					q.push(mp(cur.first+1, mp(x, y)));
					vis[x][y] = true;

					x += i;
					y += j;
				}
			}
		}
	}

	return 0;
}

int bfs_king(int x1, int y1, int x2, int y2) {
	queue <piii> q;
	q.push(mp(0, mp(x1, y1)));

	piii cur;
	int x, y;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.second == mp(x2, y2)) return cur.first;

		x = cur.second.first;
		y = cur.second.second;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;

				x = cur.second.first;
				y = cur.second.second;

				x += i;
				y += j;
				if (x > 0 && y > 0 && x < 9 && y < 9) {
					if (vis[x][y]) continue;

					q.push(mp(cur.first+1, mp(x, y)));
					vis[x][y] = true;
				}
			}
		}
	}

	return 0;
}

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	init();
	cout << bfs_rook(x1, y1, x2, y2) << " ";

	init();
	cout << bfs_bishop(x1, y1, x2, y2) << " ";

	init();
	cout << bfs_king(x1, y1, x2, y2) << "\n";

	return 0;
}