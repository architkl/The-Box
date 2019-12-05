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

int main() {
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;

	int mx = 0, temp = n;
	if (k1 < k2) {
		mx += min(n / k1, a1);
		n = max(0, n - a1*k1);

		mx += min(n / k2, a2);
	}

	else {
		mx += min(n / k2, a2);
		n = max(0, n - a2*k2);
		mx += min(n / k1, a1);;
	}

	cout << max(0, temp - a1 * (k1-1) - a2 * (k2-1)) << " " << mx << "\n";

	return 0;
}