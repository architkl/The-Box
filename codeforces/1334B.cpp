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

bool comp(double a, double b) {
	return (a > b);
}

int main() {
	int T;
	cin >> T;

	int n, x;
	while (T--) {
		cin >> n >> x;

		vector <double> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end(), comp);

		double sum = 0, num = 0;
		while (num < n) {
			sum += a[num];

			if (sum / (num+1) < x) break;

			num++;
		}

		cout << num << "\n";
	}

	return 0;
}