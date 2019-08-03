/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int dp[1005];

void init()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i < 1005; i++)
		dp[i] = min(dp[i-1], min(dp[i-2], dp[i-5])) + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int t;
	cin >> t;

	int n;

	while (t--)
	{
		cin >> n;

		vector <int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int mn = *min_element(arr.begin(), arr.end());
		for (int i = 0; i < n; i++)
			arr[i] -= mn;

		mn = INT_MAX;
		int temp;
		for (int i = 0; i < 3; i++)
		{
			temp = 0;
			for (int j = 0; j < n; j++)
			{
				// if (arr[j] - i < 0)
				// {
				// 	temp = INT_MAX;
				// 	break;
				// }

				temp += dp[arr[j] + i];
			}

			if (temp < mn)
				mn = temp;
		}

		cout << mn << "\n";
	}

	return 0;
}