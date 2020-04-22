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

	vector <int> a(4);
	for (int i = 0; i < 4; i++) cin >> a[i];

	sort(a.begin(), a.end());

	if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) cout << "TRIANGLE\n";

	else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) cout << "SEGMENT\n";

	else cout << "IMPOSSIBLE\n";

	return 0;
}