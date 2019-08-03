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
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	vector <int> h0(n), h1(n);
	for (int i = 0; i < n; i++)
		cin >> h0[i];

	for (int i = 0; i < n; i++)
		cin >> h1[i];

	vector < vector <ll> > dp(n+1, vector <ll> (2));
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + h0[i-1]);
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + h1[i-1]);
	}

	cout << max(dp[n][0], dp[n][1]) << "\n";

	return 0;
}