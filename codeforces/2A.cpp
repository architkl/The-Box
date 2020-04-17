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

	vector < pair <string, int> > order(n);
	string name;
	int points;
	map <string, int> score;
	for (int i = 0; i < n; i++) {
		cin >> name >> points;

		order[i] = mp(name, points);

		if (score.find(name) == score.end()) score.insert(mp(name, 0));
		
		score[name] += points;
	}

	int mx = INT_MIN;
	for (auto it : score) {
		mx = max(mx, it.second);
	}

	map <string, int> temp;
	for (int i = 0; i < n; i++) {
		name = order[i].first;
		points = order[i].second;

		if (temp.find(name) == temp.end()) temp.insert(mp(name, 0));
		
		temp[name] += points;

		if (temp[name] >= mx && score[name] == mx) {
			cout << name << "\n";
			break;
		}
	}

	return 0;
}