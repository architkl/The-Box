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

int f(int n) {
	int cnt = 0;
	while (n) {
		cnt += n%2;
		n >>= 1;
	}

	return cnt;
}

int main() {
	int n;
	cin >> n;

	vector <int> v(n), idx;
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		if (f(v[i]) % 2 == 0) idx.pb(i);
	}

	int res = 0;
	for (auto i : idx) {
		// cout << i << " ";
		res += v[i];
	}

	cout << res << "\n";

	return 0;
}