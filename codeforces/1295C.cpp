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
	int T;
	cin >> T;

	string s, t;
	while (T--) {
		cin >> s >> t;

		map <char, set <int>> pos;
		for (int i = 0; i < s.length(); i++) pos[s[i]].insert(i);

		int j = 0, ans = 0, prev;
		set <int>::iterator it;
		bool f;
		while (j < t.length()) {
			f = 0;
			prev = INT_MIN;

			// map <char, int> cnt;
			// for (char i = 'a'; i <= 'z'; i++) cnt[i] = 0;

			while (j < t.length()) {
				// cout << "HERE\n";
				// cout << t_itr << " " << t[t_itr] << " " << cnt[t[t_itr]-'a'] << " < " << pos[t[t_itr]-'a'].size() << " " << pos[t[t_itr]-'a'][cnt[t[t_itr]-'a']] << " < " << prev << "\n";

				it = pos[t[j]].upper_bound(prev);

				if (it == pos[t[j]].end()) break;

				prev = *it;
				// cnt[t[t_itr]-'a']++;
				j++;
				// for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
				// 	cout << "\n";
				// cout << cnt[t[t_itr]-'a'] << "\n";
				f = 1;
			}

			if (f == 0) {
				ans = -1;
				break;
			}

			ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}