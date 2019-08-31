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
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int res = 0;
		set <int> S;
		S.insert(a[n-1] * (-1));
		for (int i = n-2; i >= 0; i--) {
			S.insert(a[i] * (-1));

			if (S.upper_bound(a[i] * (-1)) != S.end())
				res++;
		}

		cout << res << "\n";
	}

	return 0;
}