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
	int n;
	cin >> n;

	// vector <int> a(n);
	map <int, int> freq;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;

		freq[t]++;
	}

	int ans = 0;
	for (auto it = freq.begin(); it != freq.end(); it++) ans += (it->second / 2);

	cout << ans << "\n";

	return 0;
}