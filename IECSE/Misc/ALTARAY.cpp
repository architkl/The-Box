/*
Author: architkl
Language: C++ 14
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	while (t--)
	{
		cin >> n;

		vector <int> A(n);
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];

			A[i] = abs(A[i]) / A[i];
		}

		int dp[n];
		dp[n-1] = 1;
		for (int i = n-2; i >= 0; i--)
		{
			if (A[i] + A[i+1] == 0)
				dp[i] = dp[i+1] + 1;

			else
				dp[i] = 1;
		}

		for (int i = 0; i < n; i++)
			cout << dp[i] << " ";

		cout << "\n";
	}

	return 0;
}