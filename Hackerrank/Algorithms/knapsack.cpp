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

int main()
{
	int t;
	cin >> t;

	int n, k;
	while (t--)
	{
		cin >> n >> k;

		vector <int> arr(n+1);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		vector < vector <int> > dp(n+1, vector <int> (k+1));
		for (int i = 0; i <= n; i++)
			dp[i][0] = 0;
		
		for (int i = 0; i <= k; i++)
			dp[0][i] = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (j - arr[i] >= 0)
					dp[i][j] = max(dp[i][j-arr[i]] + arr[i], dp[i-1][j]);

				else
					dp[i][j] = dp[i-1][j];
			}
		}

		cout << dp[n][k] << "\n";
	}

	return 0;
}