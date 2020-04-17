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
	int t;
	cin >> t;

	int n, m;
	while (t--) {
		cin >> n >> m;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) cout << "B";
			cout << "\n";
		}

		for (int i = 1; i < m; i++) cout << "B";
		cout << "W\n";
	}

	return 0;
}