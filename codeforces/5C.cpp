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

	stack < pair <char, int> > S;
	vector <int> op_match(s.length(), -1), earliest_op(s.length(), -1);
	vector <int> cnt(s.length()+1);
	cnt[0] = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') S.push(mp(s[i], i));

		else if (!S.empty()) {
			op_match[i] = S.top().second;
			S.pop();

			if (op_match[i] > 0 && earliest_op[op_match[i]-1] != -1) earliest_op[i] = earliest_op[op_match[i]-1];
			else earliest_op[i] = op_match[i];

			cnt[i-earliest_op[i]+1]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= s.length(); i++) if (cnt[i] > 0) ans = i;

	cout << ans << " " << cnt[ans] << "\n";

	return 0;
}
/*
(()())()(())()()())())()((()(()(())()()())((()(())()(()()()()))()(())()(((()())()(()((())()(())(()))
*/