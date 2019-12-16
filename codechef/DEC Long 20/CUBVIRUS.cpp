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

bool isValid(int x, int y, int z, int N) {
	if (x < 0 || x >= N || y < 0 || y >= N || z < 0 || z >= N) return false;
	return true;
}

int main() {
	int N;
	cin >> N;

	vector <string> cell(N*N);
	for (int i = 0; i < N*N; i++) {
		cin >> cell[i];
	}

	int cnt_infected = 0;
	vector <piii> inf_co;
	for (int z = 0; z < N; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (cell[z*N+y][x] == '1') {
					cnt_infected++;
					inf_co.pb(mp(x, mp(y, z)));
				}
			}
		}
	}

	vector <piii> hlth_co;
	int cnt_healthy = 0, x, y, z;
	vector < vector < vector <bool> > > vis(N, vector < vector <bool> > (N, vector <bool> (N)));
	// queue <piii> q;
	// q.push(mp(N-1, mp(N-1, N-1)));
	// piii cur;
	bool f = 0;

	for (int z = N-1; z >= 0; z--) {
		for (int y = N-1; y >= 0; y--) {
			for (int x = N-1; x >= 0; x--) {
				if (cell[z*N+y][x] == '0') {
					cnt_healthy++;
					hlth_co.pb(mp(x, mp(y, z)));
				}

				if (cnt_healthy == cnt_infected) {
					f = 1;
					break;
				}
			}

			if (f) break;
		}

		if (f) break;
	}

	/*while (!q.empty()) {
		cur = q.front();
		q.pop();
		x = cur.first;
		y = cur.second.first;
		z = cur.second.second;

		// cout << "(" << x << ", " << y << ", " << z << ")\n";

		if (cell[z*N+y][x] == '0') {
			cnt_healthy++;
			hlth_co.pb(cur);
		}

		if (cnt_healthy == cnt_infected) break;

		if (isValid(x-1, y, z, N) && !vis[x-1][y][z]) {
			q.push(mp(x-1, mp(y, z)));
			vis[x-1][y][z] = 1;
		}

		if (isValid(x, y-1, z, N) && !vis[x][y-1][z]) {
			q.push(mp(x, mp(y-1, z)));
			vis[x][y-1][z] = 1;
		}

		if (isValid(x, y, z-1, N) && !vis[x][y][z-1]) {
			q.push(mp(x, mp(y, z-1)));
			vis[x][y][z-1] = 1;
		}
	}*/

	vector <int> P(N, -1), Q(N, -1), R(N, -1);
	int from_x, from_y, from_z, to_x, to_y, to_z;
	for (int i = 0; i < cnt_infected; i++) {
		from_x = inf_co[i].first;
		from_y = inf_co[i].second.first;
		from_z = inf_co[i].second.second;

		to_x = hlth_co[i].first;
		to_y = hlth_co[i].second.first;
		to_z = hlth_co[i].second.second;

		if (P[from_x] != -1 || Q[from_y] != -1 || R[from_z] != -1 || P[to_x] != -1 || Q[to_y] != -1 || R[to_z] != -1) continue;

		P[from_x] = to_x;
		Q[from_y] = to_y;
		R[from_z] = to_z;
		P[to_x] = from_x;
		Q[to_y] = from_y;
		R[to_z] = from_z;
	}

	for (int i = 0; i < N; i++) {
		if (P[i] == -1) P[i] = i;
		if (Q[i] == -1) Q[i] = i;
		if (R[i] == -1) R[i] = i;
	}

	for (auto i : P) cout << i+1 << " ";
	cout << "\n";

	for (auto i : Q) cout << i+1 << " ";
	cout << "\n";

	for (auto i : R) cout << i+1 << " ";
	cout << "\n";

	return 0;
}