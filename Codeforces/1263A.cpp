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

int main() {
	int t;
	cin >> t;

	vector <int> c(3);
	while (t--) {
		cin >> c[0] >> c[1] >> c[2];

		sort(c.begin(), c.end());

		if (c[0] < c[2]-c[1]) {
			cout << c[0] + c[1] << "\n";
		}

		else {
			cout << c[2]-c[1] + ((c[0]-(c[2]-c[1])) / 2)*2 + (c[1] - ((c[0]-(c[2]-c[1])) / 2)) << "\n";
			// cout << ((c[0]-(c[2]-c[1])) / 2)*2 + (c[2] - ((c[0]-(c[2]-c[1])) / 2)) << "\n";
		}

		// cout << min(c[0], c[2]-c[1]) +  << "\n";
	}

	return 0;
}