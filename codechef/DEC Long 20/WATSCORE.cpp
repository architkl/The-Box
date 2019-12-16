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
	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		int sub[12] = {}, p, s;
		for (int i = 0; i < N; i++) {
			cin >> p >> s;

			sub[p] = max(sub[p], s);
		}

		int ans = 0;
		for (int i = 1; i < 9; i++) ans += sub[i];

		cout << ans << "\n";
	}

	return 0;
}