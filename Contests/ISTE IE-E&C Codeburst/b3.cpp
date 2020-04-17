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

bool check(vector <int> x) {
	for (int i = 0; i < x.size(); i++) {
		for (int j = i+1; j < x.size(); j++) {
			if (x[i] == x[j]) return 1;
		}
	}

	return 0;
}

int main() {
	int n;
	cin >> n;

	vector <int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];

	int t = 0;
	while (1) {
		if (check(x)) {
			cout << t << "\n";
			break;
		}

		t++;

		for (int i = 0; i < n; i++) x[i] += (i+1);
	}

	return 0;
}