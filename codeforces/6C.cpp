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

	int n;
	cin >> n;

	vector <int> t(n);
	for (int i = 0; i < n; i++) cin >> t[i];

	int a = 0, b = n-1, t_a = 0, t_b = 0;
	while (a < b) {
		if (t_a < t_b) t_a += t[a++];

		else if (t_b < t_a) t_b += t[b--];

		else {
			t_a += t[a++];
			t_b += t[b--];
		}
	}

	if (a == b) {
		if (t_a <= t_b) a++;
		else b--;
	}

	cout << a << " " << n-b-1 << "\n";

	return 0;
}