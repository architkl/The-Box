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

string rotate(string a) {
	string s = a;

	reverse(s.begin(), s.end());
	s.erase(s.length()-1);
	reverse(s.begin(), s.end());

	s += a[0];

	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	int mx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (a[j] == b[j]) j++;

		if (j > mx) {
			mx = j;
			ans = i;
		}

		b = rotate(b);
	}

	cout << ans << "\n";

	return 0;
}