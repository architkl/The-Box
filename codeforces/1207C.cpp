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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int T;
	cin >> T;

	ll n, a, b;
	string s;
	while (T--)
	{
		cin >> n >> a >> b >> s;

		s += s.back();

		vector < vector <ll> > dp(2, vector <ll> (n+1, 1e15));
		
		dp[0][0] = b;

		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '0')
			{
				if (s[i-1] == '1')
					dp[1][i] = dp[1][i-1] + a + 2*b;

				else
				{
					dp[0][i] = min(dp[0][i-1] + a + b, dp[1][i-1] + 2*a + b);
					dp[1][i] = min(dp[0][i-1] + 2*a + 2*b, dp[1][i-1] + a + 2*b);
				}
			}

			else
			{
				dp[1][i] = min(dp[0][i-1] + 2*a + 2*b, dp[1][i-1] + a + 2*b);
			}
		}

		// for (int i = 0; i <= n; i++)
		// 	cout << i << ": " << dp[0][i] << " " << dp[1][i] << "\n";

		cout << dp[0][n] << "\n";
	}

	return 0;
}