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

bool works(vector <int> a, double x, int len) {
	if (a[0] - x > 0) return false;

	int n = a.size()-1;
	for (int i = 0; i < n; i++) if (a[i] + x < a[i+1] - x) return false;

	if (a[n] + x < len) return false;

	return true;
}
/*
int main() {
	int n, len;
	cin >> n >> len;

	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	double l = 0, h = 1000 * 1000 * 1000, mid;
	int q = 60;
	while (q--) {
		mid = (l + h) / 2.0;
		// cout << l << " " << mid << " " << h << "\n";

		if (works(a, mid, len)) h = mid;

		else l = mid;
	}

	cout << setprecision(10) << fixed << mid << "\n";

	return 0;
}*/

int main() {
	int n, len;
	cin >> n >> len;

	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	double interval = 0;
	for (int i = 1; i < n; i++) interval = max(interval, (double)(a[i]) - a[i-1]);
	interval = max(interval/2, (double)(max(a[0], len - a[n-1])));

	cout << setprecision(10) << fixed << interval << "\n";

	return 0;
}