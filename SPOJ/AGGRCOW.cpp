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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

bool isSafe(vector <int> x, int C, int val) {
	int cnt = 0, temp, j;
	for (int i = 0; i < x.size(); i++) {
		cnt++;
		temp = x[i] + val;
		j = i+1;
		while (j < x.size() && x[j] < temp) j++;
		j--;
		i = j;
	}

	return (cnt >= C);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int t;
	cin >> t;

	int N, C;
	while (t--) {
		cin >> N >> C;

		vector <int> x(N);
		for (int i = 0; i < N; i++) cin >> x[i];

		sort(x.begin(), x.end());

		int l = 1, h = 1000 * 1000 * 1000, mid;
		while (l <= h) {
			mid = (l + h) / 2;
			// cout << l << " " << mid << " " << h << "\n";

			if (isSafe(x, C, mid)) l = mid+1;

			else h = mid-1;
		}

		if (isSafe(x, C, l)) cout << l << "\n";
		else cout << h << "\n";
	}

	return 0;
}