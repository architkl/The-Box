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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	bool f = 1;
	int x = 102, y = 102, dist = 0;
	vector < vector <int> > distance(205, vector <int> (205, -1));
	distance[x][y] = 0;
	vector <pii> points;
	for (int i = 0; i < s.length(); i++) {
		dist++;

		if (s[i] == 'L') x--;
		else if (s[i] == 'R') x++;
		else if (s[i] == 'U') y++;
		else y--;

		if (distance[x][y] != -1) f = 0;

		distance[x][y] = dist;
		points.pb(mp(x, y));
	}

	for (int k = points.size()-1; k >= 0; k--) {
		x = points[k].first;
		y = points[k].second;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == j || i+j == 0) continue;

				if (distance[x+i][y+j] == -1) continue;

				if (distance[x+i][y+j] < distance[x][y]-1) {
					f = 0;
					break;
				}
			}

			if (!f) break;
		}

		if (!f) break;
	}

	if (f) cout << "OK\n";
	else cout << "BUG\n";

	return 0;
}