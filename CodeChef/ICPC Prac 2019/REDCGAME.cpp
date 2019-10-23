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

bool comp(int i, int j) {
	return (i > j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  T;
	cin >> T;

	int n, k;
	while (T--) {
		cin >> n >> k;
		map <int, int> mymap;
		int t;

		for (int i = 0; i < n; i++) {
			cin >> t;
			mymap[t]++;
		}

		int t1, t2;
		while (1) {
			t1 = (mymap.begin())->first;
			mymap[t1]--;
			if (mymap[t1] == 0) mymap.erase(t1);

			t2 = (mymap.end()-1)->first;
			mymap[t2]--;
			if (mymap[t2] == 0)	mymap.erase(t2);

			t2 -= (t1-k);
			// t1--;
			// t2--;
			t1 = k;
			mymap[t1]++;
			mymap[t2]++;
		}

		ll sum = 0;
		for (auto itr : mymap) {
			// cout << itr.first << " ";
			sum += (itr.first * itr.second);
		}

		cout << sum << "\n";
	}

	return 0;
}