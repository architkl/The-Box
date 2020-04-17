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

const int K = 1e9+7;

int main() {
	int N;
	cin >> N;

	map <ll, ll> p_x, p_y;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		p_x[x]++;
		p_y[y]++;
	}

	map <ll, ll>::iterator prev_it = p_x.begin(), it = p_x.begin();
	it++;
	for (; it != p_x.end(); it++, prev_it++) it->second += prev_it->second;

	prev_it = it = p_y.begin();
	it++;
	for (; it != p_y.end(); it++, prev_it++) it->second += prev_it->second;

	prev_it = it = p_x.begin();
	ll ans = 0ll - (N-it->second) * (it->first) * (it->second);
	ans %= K;
	it++;
	for (;it != p_x.end(); it++, prev_it++) {
		ans += (it->second - prev_it->second) * it->first * (prev_it->second - N + it->second);
		ans %= K;
	}

	prev_it = it = p_y.begin();
	ans -= (N-it->second) * (it->first) * (it->second);
	ans %= K;
	it++;
	for (;it != p_y.end(); it++, prev_it++) {
		ans += (it->second - prev_it->second) * it->first * (prev_it->second - N + it->second);
		ans %= K;
	}

	cout << ans << "\n";

	return 0;
}