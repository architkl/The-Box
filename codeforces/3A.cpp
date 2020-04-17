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

	string s, t;
	cin >> s >> t;

	int moves = 0;
	string ans = "";
	while (s[0] < t[0] && s[1] < t[1]) {
		ans += "RU\n";

		moves++;
		s[0]++;
		s[1]++;
	}

	while (s[0] > t[0] && s[1] < t[1]) {
		ans += "LU\n";

		moves++;
		s[0]--;
		s[1]++;
	}

	while (s[0] < t[0] && s[1] > t[1]) {
		ans += "RD\n";

		moves++;
		s[0]++;
		s[1]--;
	}

	while (s[0] > t[0] && s[1] > t[1]) {
		ans += "LD\n";

		moves++;
		s[0]--;
		s[1]--;
	}

	while (s[0] < t[0]) {
		ans += "R\n";

		moves++;
		s[0]++;
	}

	while (s[0] > t[0]) {
		ans += "L\n";

		moves++;
		s[0]--;
	}

	while (s[1] < t[1]) {
		ans += "U\n";

		moves++;
		s[1]++;
	}

	while (s[1] > t[1]) {
		ans += "D\n";

		moves++;
		s[1]--;
	}

	cout << moves << "\n" << ans << "\n";

	return 0;
}