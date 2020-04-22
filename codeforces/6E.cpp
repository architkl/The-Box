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

	int n, k;
	cin >> n >> k;

	vector <int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	multiset <int> ms;
	set <int> idx;
	ms.insert(h[0]);
	idx.insert(0);
	int i = 0, j = 1, mn, mx, temp_a = 1, a = 1, b = 1;
	while (1) {
		mx = *(ms.rbegin());
		mn = *(ms.begin());

		if (!ms.empty() && mx - mn > k) {
			ms.erase(ms.find(h[i++]));
			temp_a--;
		}

		else if (j < n) {
			ms.insert(h[j++]);
			temp_a++;
		}

		else break;

		mx = *(ms.rbegin());
		mn = *(ms.begin());

		if (mx - mn <= k) {
			if (temp_a == a) {
				b++;
				idx.insert(i);
			}

			else if (temp_a > a) {
				a = temp_a;
				b = 1;

				idx.clear();
				idx.insert(i);
			}
		}
	}

	cout << a << " " << b << "\n";
	for (auto it : idx) cout << it+1 << " " << it+a << "\n";

	return 0;
}