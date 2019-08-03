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

vector < vector <int> > dp(10, vector <int> (10, -1));

void init()
{
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
}

int solve(int i, int j)
{
	if (i < 0 || j < 0)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = solve(i-1, j) + solve(i, j-1);

	return dp[i][j];
}

int main()
{
	init();

	int T;
	cin >> T;

	int M, N;
	while (T--)
	{
		cin >> M >> N;

		cout << solve(M-1, N-1) << "\n";
	}

	return 0;
}