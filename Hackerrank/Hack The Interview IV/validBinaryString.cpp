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

	string s;
	cin >> s;

	int d;
	cin >> d;

	int cnt = 0, i = 0, j = 0, ans = 0;
	while (j < d) {
		if (s[j] == '1') cnt++;

		j++;
	}

	if (cnt == 0) {
		ans++;
		s[j-1] = '1';
		cnt++;
	}

	while (j < (int)(s.length())) {
		if (s[i] == '1') cnt--;

		if (s[j] == '1') cnt++;

		if (cnt == 0) {
			ans++;
			s[j] = '1';
			cnt++;
		}
		
		i++;
		j++;
	}

	cout << ans << "\n";

	return 0;
}