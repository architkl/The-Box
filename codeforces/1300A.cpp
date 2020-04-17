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

		vector <int> a(n);
		int cnt = 0, ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];

			sum += a[i];

			if (a[i] == 0) {
				cnt++;
				a[i]++;
				sum++;
			}
		}

		ans = cnt;
		
		if (sum == 0) ans++;

		cout << ans << "\n";
	}

	return 0;
}