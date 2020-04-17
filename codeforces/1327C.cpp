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
	int n, m, k;
	cin >> n >> m >> k;

	vector <int> sx(k), sy(k), fx(k), fy(k);
	for (int i = 0; i < k; i++) cin >> sx[i] >> sy[i];

	for (int i = 0; i < k; i++) cin >> fx[i] >> fy[i];

	int cnt = 0;
	string s = "";
	for (int i = 1; i < n; i++) s += "U", cnt++;
	for (int i = 1; i < m; i++) s += "L", cnt++;

	for (int i = 1; i <= n; i++) {
		if (i % 2)	for (int j = 1; j < m; j++) s += "R", cnt++;
		else for (int j = 1; j < m; j++) s += "L", cnt++;

		if (i != n)	s += "D", cnt++;
	}

	cout << cnt << "\n" << s << "\n";

	return 0;
}