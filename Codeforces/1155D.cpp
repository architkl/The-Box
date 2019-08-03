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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	int mul = (x == 0) ? 1 : abs(x) / x;

	vector <int> arr(n), backup(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		backup[i] = arr[i]*mul;

		// cout << arr[i] << " ";
	}
	// cout << "\n";

	long long int mx = max(0, backup[0]);
	vector <long long int> dp(n);
	dp[0] = mx;
	for (int i = 1; i < n; i++)
	{
		dp[i] = max((long long)0, max((long long)backup[i], dp[i-1] + backup[i]));
		mx = max(dp[i], mx);
	}

	if (x == 0)
		cout << max((long long)0, dp.back()) << "\n";
	
	else
	{
		int l, r = n-2;
		while (r >= 0 && dp[r] == dp[n-1])
			r--;
		r++;

		if (r == 0)
			r--;

		l = r;
		while (l >= 0 && dp[l] != backup[l])
			l--;

		if (l < 0)
			l++;

		// cout << l << " " << r << "\n";

		for (int i = l; i <= r; i++)
			arr[i] *= x;

		// for (int i = 0; i < n; i++)
		// 	cout << arr[i] << " ";
		// cout << "\n";

		vector <long long int> dp2(n);

		mx = max(0, arr[0]);
		dp2[0] = mx;
		for (int i = 1; i < n; i++)
		{
			dp2[i] = max((long long)0, max((long long)arr[i], dp2[i-1] + arr[i]));
			mx = max(dp2[i], mx);
			// cout << dp2[i] << " ";
		}

		cout << dp2.back() << "\n";
	}

	return 0;
}