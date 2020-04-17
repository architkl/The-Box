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

bool comp(pii a, pii b) {
	return (a.second > b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, v;
	cin >> n >> v;

	vector <pii> kayak, catamaran;
	int t, p;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;

		if (t == 1)	kayak.pb(mp(i+1, p));
		else catamaran.pb(mp(i+1, p));
	}

	sort(kayak.begin(), kayak.end(), comp);
	sort(catamaran.begin(), catamaran.end(), comp);


	vector <ll> k_pre(kayak.size()+1), c_pre(catamaran.size()+1);
	for (int i = 0; i < kayak.size(); i++) k_pre[i+1] = k_pre[i] + kayak[i].second;
	for (int i = 0; i < catamaran.size(); i++) c_pre[i+1] = c_pre[i] + catamaran[i].second;

	ll cap = 0;
	int c = 0;
	for (int i = 0; i <= catamaran.size(); i++) {
		if (2*i > v) break;

		if (c_pre[i] + k_pre[min(v-2*i, (int)kayak.size())] > cap) {
			cap = c_pre[i] + k_pre[min(v-2*i, (int)kayak.size())];
			c = i;
		}
	}

	cout << cap << "\n";
	for (int i = 0; i < c; i++) cout << catamaran[i].first << " ";
	for (int i = 0; i < min(v-2*c, (int)kayak.size()); i++) cout << kayak[i].first << " ";
	cout << "\n";

	return 0;
}

/*
x + 2*y = v
*/