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
	int T;
	cin >> T;

	ll n, x;
	string s;
	while (T--) {
		cin >> n >> x >> s;

		vector <ll> val(n);
		ll cnt_0 = 0, cnt_1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') cnt_0++;
			else cnt_1++;

			val[i] = cnt_0 - cnt_1;
		}

		ll res = (x == 0) ? 1 : 0;
		if (val[n-1] == 0) {
			for (int i = 0; i < n; i++) {
				if (x == val[i]) {
					res = -1;
					break;
				}
			}
		}

		else for (int i = 0; i < n; i++) if ((x-val[i])*val[n-1] >= 0 && (x-val[i]) % val[n-1] == 0) res++;

		cout << res << "\n";
	}

	return 0;
}