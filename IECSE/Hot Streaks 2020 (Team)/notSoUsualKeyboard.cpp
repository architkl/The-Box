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

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	map <char, bool> alph;
	char c;
	for (int i = 0; i < k; i++) {
		cin >> c;

		alph.insert(mp(c, 1));
	}

	vector <pii> intervals;
	for (int i = 0; i < n; i++) {
		if (alph.find(s[i]) != alph.end()) {
			int j = i+1;
			while (j < n && alph.find(s[j]) != alph.end()) j++;

			intervals.pb(mp(i, j-i));
			i = j;
		}
	}

	int ans = 0;
	for (int i = 0; i < intervals.size(); i++) {
		int start = intervals[i].first, len = intervals[i].second;
		cout << start << " " << start+len << "\n";
		string temp;

		for (int j = start; j < start+len; j++) {
			for (int k = 1; k <= len-j+start; k++) {
				// temp = s.substr(j, k);
				// ans.insert(temp);
				// cout << temp << "\n";
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}