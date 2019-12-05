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

bool set_check(vector < vector <int> > A, int x, int y)
{
	int n = A.size(), m = A[0].size();

	for (int i = 0; i < 2; i++)
		if (x+i < 0 || x+i >= n || y+i < 0 || y+i >= m)
			return false;

	return (A[x][y] && A[x][y+1] && A[x+1][y] && A[x+1][y+1]);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector < vector <int> > A(n, vector <int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	vector <pii> moves;
	bool flag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] == 1)
			{
				if (set_check(A, i-1, j-1))
				{
					moves.pb(mp(i-1, j-1));
					continue;
				}

				else if (set_check(A, i-1, j))
				{
					moves.pb(mp(i-1, j));
					continue;
				}

				else if (set_check(A, i, j-1))
				{
					moves.pb(mp(i, j-1));
					continue;
				}

				else if (set_check(A, i, j))
				{
					moves.pb(mp(i, j));
					continue;
				}

				else
				{
					flag = 0;
					break;
				}
			}
		}

		if (flag == 0)
			break;
	}

	if (!flag)
		cout << -1 << "\n";

	else
	{
		cout << moves.size() << "\n";

		for (auto i : moves)
			cout << i.first+1 << " " << i.second+1 << "\n";
	}

	return 0;
}