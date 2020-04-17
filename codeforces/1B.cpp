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

	int n;
	cin >> n;

	string s, ans;
	while (n--) {
		cin >> s;

		bool type = 0;
		if (s[0] == 'R' && isdigit(s[1])) for (int i = 2; i < s.length(); i++) if (s[i] == 'C') type = 1;

		if (type) {
			int pos = 1;
			string row = "";

			while (s[pos] != 'C') row += s[pos++];
			pos++;

			string col = "";
			while (pos < s.length()) col += s[pos++];

			int temp = stoi(col), rem;
			col = "";
			while (temp) {
				rem = temp % 26;
				temp /= 26;

				if (rem == 0) {
					rem = 26;
					temp--;
				}

				col += char(64 + rem);
			}

			reverse(col.begin(), col.end());

			cout << col << row << "\n";
		}

		else {
			int col = 0, pos = 0;
			while (isalpha(s[pos])) {
				col *= 26;
				col += (s[pos++]-64);
			}

			cout << "R" << s.substr(pos) << "C" << col << "\n";
		}
	}

	return 0;
}

/*26 - Z
27 - AA
52 - AZ
53 - BA*/