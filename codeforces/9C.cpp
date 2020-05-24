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

	string n;
	cin >> n;

	string s = "";
	for (int i = 0; i < n.length(); i++) {
		if (n[i] > '1') while (i++ < n.length()) s += "1";
		else if (n[i] == '1') s += "1";
		else s += "0";
	}

	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans <<= 1;
		ans += s[i]-'0';
	}

	cout << ans << "\n";

	return 0;
}

/*
1 10 11 100 101 110 111
*/