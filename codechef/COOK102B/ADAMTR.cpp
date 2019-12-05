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

const int N_MAX = 1024;

void swap(vector <vector <int>> &A, int N, int r)
{
	int temp;
	for (int i = 0; i < N; i++)
	{
		temp = A[r][i];
		A[r][i] = A[i][r];
		A[i][r] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;

	while (T--)
	{
		cin >> N;

		vector <vector <int>> A(N, vector <int> (N)), B(N, vector <int> (N));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> A[i][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> B[i][j];

		bool flag = 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (A[i][j] != B[i][j])
				{
					swap(A, N, j);

					if (A[i][j] != B[i][j])
					{
						flag = 0;
						break;
					}
				}
			}

			if (!flag)
				break;
		}

		if (flag)
			cout << "YES\n";

		else
			cout << "NO\n";
	}

	return 0;
}