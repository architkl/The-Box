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

		vector <int> p(n);
		map <int, int> freq;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			freq[p[i]]++;
		}

		map <int, int>::iterator it = freq.end();
		it--;

		int g = it->second, s = 0, b = 0, medals = n/2;
		it--;

		for (; it != freq.begin(); it--) {
			if (s <= g && (s+g+it->second <= medals)) {
				s += it->second;
			}

			else if (s+g+b+it->second <= medals) {
				b += it->second;
			}

			else break;
		}

		// cout << g << " " << s << " " << b << "\n";
		if (s <= g || b <= g) cout << "0 0 0\n";
		else cout << g << " " << s << " " << b << "\n";
	}

	return 0;
}