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

int main() {
	int x, m;
	cin >> x >> m;

	x -= m;
	int n, p, f = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;

		if (x >= p) {
			cout << "YES\n";
			f = 1;
			break;
		}
	}

	if (!f) cout << "NO\n";

	return 0;
}