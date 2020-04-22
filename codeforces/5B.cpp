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

	vector <string> v;
	string s;
	while (getline(cin, s)) v.pb(s);

	int n = v.size(), mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, (int)v[i].length());

	vector <int> gap(n);
	bool f = 0;
	for (int i = 0; i < n; i++) {
		gap[i] = (mx-v[i].length()) / 2;
		// cout << mx << " " << v[i].length() << "\n";
		// cout << i << " " << gap[i] << "\n";

		if ((mx - v[i].length()) % 2) {	
			if (f) gap[i]++;
			f = !f;
		}
	}

	int len = mx+2;
	for (int i = 0; i < len; i++) cout << "*";
	cout << "\n";

	for (int i = 0; i < n; i++) {
		int t = 1;
		cout << "*";

		t += gap[i];
		for (int j = 0; j < gap[i]; j++) cout << " ";

		t += v[i].length();
		cout << v[i];

		while (t+1 != len) {
			t++;
			cout << " ";
		}

		cout << "*\n";
	}

	for (int i = 0; i < len; i++) cout << "*";
	cout << "\n";

	return 0;
}