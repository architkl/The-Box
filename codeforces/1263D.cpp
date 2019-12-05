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

const int N_MAX = 2e5+50;

vector <int> parent(N_MAX), unq(N_MAX);

void init()
{
	for (int i = 0; i < N_MAX; i++) {
		parent[i] = i;
		unq[i] = 0;
	}
}

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);

	return parent[x];
}

void dsu_union(int x, int y) {
	int px = find_parent(x), py = find_parent(y);

	if (unq[px] < unq[py]) parent[px] = py;
	else parent[py] = px;
}

int main() {
	init();

	int n;
	cin >> n;

	vector <string> str(n+26);
	for (int i = 26; i < n+26; i++) {
		cin >> str[i];

		set <int> u;
		for (int j = 0; j < str[i].length(); j++) u.insert(str[i][j]);
		unq[i] = u.size();

		for (int j = 0; j < str[i].length(); j++) {
			for (int k = 0; k < 26; k++) {
				if (str[i][j] == 'a'+k) {
					dsu_union(i, k);
					break;
				}
			}
		}
	}

	set <int> ans;	
	for (int i = 0; i < 26; i++) {
		// cout << i << " " << find_parent(i)-26 << "\n";
		if (find_parent(i) >= 26) ans.insert(find_parent(i));
	}

	cout << ans.size() << "\n";

	return 0;
}