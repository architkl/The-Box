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
	int t;
	cin >> t;

	int k;
	string s;
	while (t--) {
		cin >> k >> s;

		int cur = 0, nxt, mx = 0;
		while (s[cur] != 'A' && cur < s.length()) cur++;

		nxt = cur+1;
		while (nxt < s.length()) {
			while (s[nxt] != 'A' && nxt < s.length()) nxt++;

			mx = max(mx, nxt-cur-1);
			cur = nxt;
			nxt++;
		}

		cout << mx << "\n";
	}

	return 0;
}