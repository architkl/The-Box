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

int solve(vector <int> v, int pos, int n, int k, int sum) {
	if (sum == k) return 1;

	if (pos == n) return 0;

	int ans = solve(v, pos+1, n, k, sum+v[pos]);
	if (ans) {
		cout << v[pos] << " ";
		return 1;
	}

	ans = solve(v, pos+1, n, k, sum);
	return ans;
}

int main() {
	int n, k;
	cin >> n;

	vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	cin >> k;

	if (solve(v, 0, n, k, 0) == 0) cout << "null\n";

	cout << "\n";

	return 0;
}