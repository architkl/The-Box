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
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	vector <int> lamps(1001);
	int cur_t;
	bool onn;
	for (int i = 0; i < n; i++) {
		cur_t = 0;
		onn = s[i]-48;

		while (cur_t <= 1000)
		{
			if (cur_t >= b[i] && ((cur_t - b[i]) % a[i]) == 0)
				onn ^= 1;

			// if (onn) cout << i << " on at " << cur_t << "\n";
			lamps[cur_t] += onn;
			cur_t++;
		}
	}

	// int mx = 0, idx;
	// for (int i = 0; i <= 1000; i++) {
	// 	if (mx < lamps[i]) {
	// 		mx = lamps[i];
	// 		idx = i;
	// 	}
	// }

	// cout << idx << "\n";

	cout << *max_element(lamps.begin(), lamps.end()) << "\n";

	return 0;
}