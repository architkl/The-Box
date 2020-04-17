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

bool comp(int a, int b) {
	return (a > b);
}

int main() {
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		bool f = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (j-a[j] == i-a[i]) {
					f = 1;
					break;
				}
			}
		}

		if (f) sort(a.begin(), a.end(), comp);

		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << "\n";
	}

	return 0;
}