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

	int a, b;
	cin >> a >> b;

	int n, l, h;
	cin >> n;
	while (n--) {
		cin >> l >> h;

		int ans = -1;
		for (int i = h; i >= l; i--) {
			if (a % i == 0 && b % i == 0) {
				ans = i;
				break;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}

/*
2 2 3 7
2 3 3 5
*/