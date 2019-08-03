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
typedef unsigned long long ull;
typedef long long ll;

const int K = 1e9+7;

int mod_ex(ll a, ll b, int m)
{
	if (b == 0)
		return 1;

	long long int res = mod_ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int main()
{
	string s;
	cin >> s;

	vector <ll> dp(s.length()+2);
	dp[s.length()+1] = 0;

	for (int i = s.length(); i > 0; i--)
	{
		dp[i] = dp[i+1] + (s[i-1]-48) * ((mod_ex(10, s.length()-i+1, K) - 1ll + K) % K) * mod_ex(9, K-2, K);
		dp[i] %= K;
	}
	
	ll ans = 0;
	for (int i = 1; i <= s.length(); i++)
	{
		ans += dp[i];
		ans %= K;
	}

	cout << ans << "\n";

	return 0;
}