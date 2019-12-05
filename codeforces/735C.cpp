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

const int MAXX = 105;
ull dp[MAXX] = {};

void pre()
{
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 3;

	for (int i = 3; i < MAXX; i++)
		dp[i] = dp[i-1] + dp[i-2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ull n;
	cin >> n;

	pre();

	int i = 1;
	while (1)
	{
		if (dp[i] > n)
		{
			i--;
			break;
		}

		i++;
	}

	cout << i << "\n";

	return 0;
}