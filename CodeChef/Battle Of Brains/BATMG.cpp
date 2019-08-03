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
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 1e6 + 5;

int parent[N_MAX];
int dsu_rank[N_MAX];
int children[N_MAX];

void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		dsu_rank[i] = 0;
		children[i] = 0;
	}
}

int find_set(int x)
{
	if (parent[x] != x)
		parent[x] = find_set(parent[x]);

	return parent[x];
}

void union_set(int x, int y)
{
	int px = find_set(x), py = find_set(y);

	if (px == py)
		return;

	if (dsu_rank[px] > dsu_rank[py])
	{
		parent[py] = px;
		children[px] += children[py] + 1;
	}

	else
	{
		parent[px] = py;
		children[py] += children[px] + 1;
	}

	if (dsu_rank[px] == dsu_rank[py])
		dsu_rank[py]++;
}

int main()
{
	int T;
	cin >> T;

	while (T--){
		int N, M;
		cin >> N >> M;

		make_set(N*M+5);

		int mat[N][M];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (mat[i][j] == 0)
					continue;

				for (int k = -1; k <= 1; k++)
				{
					if (i+k < 0 || i+k >= N)
						continue;

					for (int l = -1; l <= 1; l++)
					{
						if (k == 0 && l == 0)
							continue;

						if (j+l < 0 || j+l >= M)
							continue;

						if (mat[i+k][j+l] == 1)
							union_set(i*M + j, (i+k)*M + (j+l));
					}
				}
			}
		}	

		int x, y;
		for (x = 0; x < N; x++)
			for (y = 0; y < M; y++)
				if (mat[x][y] == 1)
					break;

		int mx = children[find_set(x*M + y)], i = x*M + y + 1;

		if (x == N)
			mx = -1;

		else
		{
			while (i < N*M)
			{
				if (children[find_set(i)] > mx)
					mx = children[find_set(i)];

				i++;
			}
		}

		int N_C = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (mat[i][j] == 1 && parent[i*M + j] == (i*M) + j)
					N_C++;
			}
		}

		cout << N_C << " " << mx + 1 << "\n";
	}

	return 0;
}