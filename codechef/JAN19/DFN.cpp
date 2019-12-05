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

int grid_pre[55][55];
int grid_test[55][55];

bool check(int i, int j, int N, int M)
{
	if (i < 0 || i >= N || j < 0 || j >= M)
		return 0;

	return 1;
}

void gen(int grid[55][55], int N, int M)
{
	int k;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			set <int> temp;
			if (check(i-1, j, N, M))
			{
				int curx = i-1, cury = j;

				if (check(curx-1, cury, N, M))
					temp.insert(grid[curx-1][cury]);

				if (check(curx, cury-1, N, M))
					temp.insert(grid[curx][cury-1]);

				if (check(curx, cury+1, N, M))
					temp.insert(grid[curx][cury+1]);
			}

			if (check(i, j-1, N, M))
			{
				int curx = i, cury = j-1;

				if (check(curx-1, cury, N, M))
					temp.insert(grid[curx-1][cury]);

				if (check(curx, cury-1, N, M))
					temp.insert(grid[curx][cury-1]);
			}

			int k = 1;
			for (auto itr : temp)
			{
				if (k != itr)
					break;

				k++;
			}

			grid[i][j] = k;
		}
	}

	int maxK = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (grid[i][j] > maxK)
				maxK = grid[i][j];

	cout << maxK << "\n";
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	//int T;
	//cin >> T;
	//T = 2500;

	gen(grid_pre, 50, 50);

	int N, M;
	bool trans;
	for(int I=1;I<=50;I++){
		for(int J=1;J<=50;J++){
		
		N = I;
		M = J;

		if (!(N >= 3 && M >= 3))
		{
			if (M > N)
			{
				int temp = M;
				M = N;
				N = temp;
			}

			gen(grid_test, N, M);

			// int grid2[M][N];
			// for (int i = 0; i < N; i++)
			// 	for (int j = 0; j < M; j++)
			// 		grid2[j][i] = grid_test[i][j];

			// for (int i = 0; i < M; i++)
			// {
			// 	for (int j = 0; j < N; j++)
			// 		cout << grid2[i][j] << " ";

			// 	cout << "\n";
			// }
		}

		else
		{
			// for (int i = 0; i < N; i++)
			// {
			// 	for (int j = 0; j < M; j++)
			// 		cout << grid_pre[i][j] << " ";
			// 	cout << "\n";
			// }
		}
	}
}

	return 0;
}
/*
1 1
1

1 2
1 1

1 3
1 1 2

1 4
1 1 2 2

1 5
1 1 2 2 1

1 10
1 1 2 2 1 1 2 2 1 1

2 2
1 1
2 2

2 3
1 1 2
2 3 3

2 4
1 1 2 2
2 3 3 1

2 5
1 1 2 2 1
2 3 3 4 1

3 3
1 1 2
2 3 3
2 4 1

3 4
1 1 2 2
2 3 3 1
2 4 4 1

3 5
1 1 2 2 1
2 3 3 4 1
4 4 1 1 2

3 6
1 1 2 2 1 1
2 3 3 4 4 2
2 4 1 1 3 3

1 1 2 2
2 3 3 1
2 4 4 1
1 1 2 2

(i,j) - (i-2,j), (i+2,j), (i,j-2), (i,j+2), (i+1, j+1), (i+1, j-1), (i-1, j+1), (i-1, j-1)
*/