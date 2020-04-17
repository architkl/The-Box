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

	int n, k;
	while (t--) {
		cin >> n;

		vector < vector <int> > prince(n);
		for (int i = 0; i < n; i++) {
			cin >> k;

			prince[i].resize(k);
			for (int j = 0; j < k; j++) cin >> prince[i][j];
		}

		vector <bool> taken(n), chosen(n);
		for (int i = 0; i < n; i++) {
			int j = 0;
			while (j < prince[i].size() && taken[prince[i][j]]) j++;

			if (j != prince[i].size()) {
				// cout << "Princess " << i+1 << " marries Prince " << prince[i][j] << "\n";
				taken[prince[i][j]] = true;
				chosen[i] = true;
			}
		}

		int free_prince = 1;
		while (free_prince <= n && taken[free_prince]) free_prince++;
		if (free_prince == n+1) cout << "OPTIMAL\n";

		else {
			for (int i = 0; i < n; i++) {
				if (chosen[i]) continue;

				cout << "IMPROVE\n";
				cout << i+1 << " " << free_prince << "\n";
				break;
			}
		}
	}

	return 0;
}