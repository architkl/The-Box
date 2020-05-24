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

	int n, vb, vs;
	cin >> n >> vb >> vs;

	vector <double> stop(n);
	for (int i = 0; i < n; i++) cin >> stop[i];

	int xu, yu;
	cin >> xu >> yu;

	vector < pair <double, int> > dist(n);
	for (int i = 1; i < n; i++) {
		dist[i] = mp((sqrt(pow(stop[i]-xu, 2) + pow(yu, 2))) / vs, i);
		stop[i] /= vb;
	}

	sort(dist.begin()+1, dist.end());

	double ans = INT_MAX;
	int idx;
	for (int i = 1; i < n; i++) {
		if (dist[i].first + stop[dist[i].second] < ans) {
			ans = dist[i].first + stop[dist[i].second];
			idx = dist[i].second;
		}
	}

	cout << idx+1 << "\n";

	return 0;
}