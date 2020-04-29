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

	string s;
	while (t--) {
		cin >> s;

		bool f = 1;
		char c = s[0];
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != c) {
				f = 0;
				break;
			}
		}

		if (f) cout << s << "\n";

		else {
			string ans = "";
			ans += s[0];
			for (int i = 1; i < s.length(); i++) {
				if (s[i] == s[i-1]) {
					if (s[i] == '0') ans += '1';
					else ans += '0';
				}

				ans += s[i];
			}

			cout << ans << "\n";
		}
	}

	return 0;
}