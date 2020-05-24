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

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		int p1 = 0, p2 = 0, ele = 2;
		for (int i = 1; i < n/2; i++) {
			p1 += ele;
			ele *= 2;
		}

		for (int i = n/2; i < n; i++) {
			p2 += ele;
			ele *= 2;
		}

		p1 += ele;

		cout << p1 - p2 << "\n";
	}

	return 0;
}

/*
2 * (2)
*/