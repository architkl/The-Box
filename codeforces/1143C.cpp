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
	int n;
	cin >> n;

	vector <int> p(n+1), c(n+1), del(n+1, 1);

	for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];

	for (int i = 1; i <= n; i++) if (c[i] == 0) del[p[i]] = del[i] = 0;

	bool f = 0;
	for (int i = 1; i <= n; i++) {
		if (del[i]) {
			f = 1;
			cout << i << " ";
		}
	}

	if (!f) cout << -1;
	
	cout << "\n";

	return 0;
}