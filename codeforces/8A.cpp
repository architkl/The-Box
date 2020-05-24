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

int match(string a, string b, int idx) {
	for (int i = idx; i < a.length(); i++) {
		if (a[i] == b[0]) {
			int j;
			for (j = 0; j < b.length(); j++) if (a[i+j] != b[j]) break;

			if (j == b.length()) return i;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, c;
	cin >> a >> b >> c;

	bool fw = 0, bw = 0;
	int idx = match(a, b, 0);
	if (idx >= 0) if (match(a, c, idx+b.length()) != -1) fw = 1;

	reverse(a.begin(), a.end());
	idx = match(a, b, 0);
	if (idx >= 0) if (match(a, c, idx+b.length()) != -1) bw = 1;

	if (fw) {
		if (bw) cout << "both\n";
		else cout << "forward\n";
	}

	else if (bw) cout << "backward\n";

	else cout << "fantasy\n";

	return 0;
}