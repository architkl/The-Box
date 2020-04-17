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

int main() {
	int n, k;
	cin >> n;

	vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	cin >> k;

	int mx = 0, a, b;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i] + v[j] < k && v[i]+v[j] > mx) {
				mx = v[i]+v[j];
				a = i;
				b = j;
			}
		}
	}

	cout << v[a] << " " << v[b] << "\n";

	return 0;
}