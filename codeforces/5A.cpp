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
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	string s;
	int ans = 0, n = 0;

	while (getline(cin, s)) {
		if (s[0] == '+') n++;

		else if (s[0] == '-') n--;

		else {
			int pos = 0;
			while (s[pos] != ':') pos++;

			ans += n * (s.length() - pos - 1);
		}
	}

	cout << ans << "\n";

	return 0;
}