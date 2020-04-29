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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector <int> a(n);
	map <int, pair < vector <int>, int> > op;
	int temp, cnt;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (op.find(a[i]) == op.end()) {
			op[a[i]].first.pb(0);
			push_heap(op[a[i]].first.begin(), op[a[i]].first.end());
			op[a[i]].second = 0;
		}

		else {
			if (op[a[i]].first.size() < k) {
				op[a[i]].first.pb(0);
				push_heap(op[a[i]].first.begin(), op[a[i]].first.end());
			}

			else {
				op[a[i]].second -= op[a[i]].first[0];
				pop_heap(op[a[i]].first.begin(), op[a[i]].first.end());
				op[a[i]].first.pop_back();
				op[a[i]].first.pb(0);
			}
		}

		temp = a[i];
		cnt = 0;
		while (temp) {
			temp /= 2;
			cnt++;

			if (op.find(temp) == op.end()) {
				op[temp].first.pb(cnt);
				push_heap(op[temp].first.begin(), op[temp].first.end());
				op[temp].second = cnt;
			}

			else {
				if (op[temp].first.size() < k) {
					op[temp].first.pb(cnt);
					push_heap(op[temp].first.begin(), op[temp].first.end());
					op[temp].second += cnt;
				}

				else if (op[temp].first[0] > cnt) {
					op[temp].second -= op[temp].first[0];
					pop_heap(op[temp].first.begin(), op[temp].first.end());
					op[temp].first.pop_back();
					op[temp].first.pb(cnt);
					op[temp].second += cnt;
				}
			}
		}
	}

	int mn = INT_MAX;
	for (auto it : op) {
		if (it.second.first.size() >= k && it.second.second < mn)
			mn = it.second.second;
	}

	cout << mn << "\n";

	return 0;
}