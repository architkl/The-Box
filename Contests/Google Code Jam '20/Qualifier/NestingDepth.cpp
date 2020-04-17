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
	int T;
	cin >> T;

	string S;
	for (int x = 1; x <= T; x++) {
		cin >> S;

		string ans = "";
		int depth = 0;
		for (int i = 0; i < S.length(); i++) {
			int digit = S[i]-48;
			int j = i+1;
			while (j < S.length() && S[j] == S[j-1]) j++;

			while (depth < digit) {
				ans += "(";
				depth++;
			}

			while (depth > digit) {
				ans += ")";
				depth--;
			}

			for (int k = i; k < j; k++) ans += to_string(digit);

			i = j-1;
		}

		while (depth > 0) {
			ans += ")";
			depth--;
		}

		cout << "Case #" << x << ": " << ans << "\n";
	}

	return 0;
}