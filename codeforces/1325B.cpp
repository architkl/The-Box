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

	int n;
	while (t--) {
		cin >> n;

		set <int> a;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;

			a.insert(x);
		}

		cout << a.size() << "\n";
	}

	return 0;
}