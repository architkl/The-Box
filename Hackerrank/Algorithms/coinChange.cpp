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
	int n, m;
	cin >> n >> m;

	vector <int> c(m+1);
	for (int i = 1; i <= m; i++)
		cin >> c[i];

	vector < vector <ll> > table(m+1, vector <ll> (n+5));
	for (int i = 0; i <= m; i++)
		table[i][0] = 1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j-c[i] >= 0)
				table[i][j] = table[i][j-c[i]] + table[i-1][j];
			
			else
				table[i][j] = table[i-1][j];
		}
	}

	cout << table[m][n] << "\n";

	return 0;
}
/*
	0	1	2	3	4
0	1	0	0	0	0
2	1	0	1	0	1
4	1	0	0	0	2*/