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

bool check(string s) {
	for (int i = 1; i < s.length(); i++) if (s[i] == s[i-1]) return 0;

	return 1;
}

int main() {
	int t;
	cin >> t;

	string s;
	while (t--) {
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '?') {
				if (i-1 >= 0 && i+1 < s.length()) {
					if (s[i-1] == 'a' && s[i+1] != 'b') s[i] = 'b';
					else if (s[i-1] == 'a' && s[i+1] != 'c') s[i] = 'c';
					else if (s[i-1] == 'b' && s[i+1] != 'a') s[i] = 'a';
					else if (s[i-1] == 'b' && s[i+1] != 'c') s[i] = 'c';
					else if (s[i-1] == 'c' && s[i+1] != 'a') s[i] = 'a';
					else if (s[i-1] == 'c' && s[i+1] != 'b') s[i] = 'b';
				}

				else if (i-1 >= 0) {
					if (s[i-1] == 'a') s[i] = 'b';
					else if (s[i-1] == 'b') s[i] = 'c';
					else if (s[i-1] == 'c') s[i] = 'a';
				}

				else {
					if (s[i+1] == 'a') s[i] = 'b';
					else if (s[i+1] == 'b') s[i] = 'c';
					else s[i] = 'a';
				}
			}
		}

		// cout << s << "\n\n";
		if (check(s)) cout << s << "\n";
		else cout << -1 << "\n";
	}

	return 0;
}