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

	vector <int> dp(n+1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i-1 >= 0) dp[i] += dp[i-1];
		if (i-2 >= 0) dp[i] += dp[i-2];
		if (i-3 >= 0) dp[i] += dp[i-3];
	}

	// for (int i = 0; i <= n; i++) cout << dp[i] << " ";
	// cout << "\n";

	cout << dp[n] << "\n";

	return 0;
}