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

void setZeroes(vector<vector<int> > &A) {
	vector <bool> row(A.size()), col(A[0].size());

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			if (A[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (int i = 0; i < A.size(); i++)
	{
		if (row[i])
		{
			for (int j = 0; j < A[i].size(); j++)
				A[i][j] = 0;
		}
	}

	for (int i = 0; i < A[0].size(); i++)
	{
		if (col[i])
		{
			for (int j = 0; j < A.size(); j++)
				A[j][i] = 0;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector < vector <int> > A(n, vector <int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	setZeroes(A);

	for (auto i : A)
	{
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}