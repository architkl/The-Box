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

const int N_MAX = 17;

vector < vector <int> > table(N_MAX, vector <int> (N_MAX));

int solve(int N, int i, int j)
{
	if (i == N)
		return 0;

	return table[i][j] + max(solve(N, i+1, j), solve(N, i+1, j+1));
}

int main()
{
	int  T;
	cin >> T;

	int N;
	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				cin >> table[i][j];

		cout << solve(N, 0, 0) << "\n";
	}

	return 0;
}