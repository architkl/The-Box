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

	int n;
	while (t--) {
		cin >> n;

		vector <string> str(n);
		map <string, int> freq;
		map <string, vector <string> > mp;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			freq[str[i]]++;
		}

		int ans = 0;
		for (auto i : freq) {
			// cout << i.first << " " << i.second << "\n";
			if (i.second > 1) {
				int temp1 = i.second;
				string nstr;
				// char temp2;
				bool f = 0;

				while (temp1 != 1) {
					for (int dgt = 0; dgt < 4; dgt++) {
						nstr = i.first;
						// temp2 = nstr[dgt];
						for (char j = '0'; j <= '9'; j++) {
							nstr[dgt] = j;
							if (freq[nstr] == 0) {
								f = 1;
								break;
							}
						}

						if (f) break;
					}

					freq[nstr]++;
					mp[i.first].pb(nstr);
					ans++;

					temp1--;
				}
			}
		}

		cout << ans << "\n";
		
		for (int i = 0; i < n; i++) {
			if (mp[str[i]].size() == 0) cout << str[i] << "\n";

			else {
				cout << mp[str[i]].back() << "\n";
				mp[str[i]].pop_back();
			}
		}
	}

	return 0;
}