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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector < map <int, int> > op(n, map <int, int> ());
	int temp, cnt;
	for (int i = 0; i < n; i++) {
		temp = a[i];
		cnt = 0;

		while (temp) {
			op[i][temp] = cnt++;;
			// cout << temp << ": " << op[i][temp] << " ";
			temp >>= 1;
		}

		op[i][temp] = cnt;
		// cout << temp << ": " << op[i][temp] << " ";
		// cout << "\n";
	}

	int mn = INT_MAX, target;
	for (int i = 0; i < n; i++) {
		for (auto j : op[i]) {
			target = j.first;
			// cout << target << "\n";
			temp = op[i][target];
			cnt = 1;

			for (int l = 0; l < n; l++) {
				if (l == i)
					continue;

				if (op[l].find(target) == op[l].end()) {
					continue;
				}

				// cout << l << " ";
				cnt++;
				temp += op[l][target];

				if (cnt == k)
					break;
			}

			// cout << ":" << cnt << " " << temp << "\n";

			if (cnt >= k)
				mn = min(mn, temp);
		}

		// cout << "\n";
	}

	cout << mn << "\n";

	return 0;
}