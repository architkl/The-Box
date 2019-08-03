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

const int N_MAX = 1e5 + 5;

int parent[N_MAX];
int dsu_rank[N_MAX];
int children[N_MAX];

int mx = 0;

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

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int maXOR(vector <int> set) 
{ 
	int n = set.size();

	int index = 0;
  
	for (int i = 31; i >= 0; i--)
	{
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			if ( (set[j] & (1 << i)) != 0 && set[j] > maxEle )
				maxEle = set[j], maxInd = j;
		}

		if (maxEle == INT_MIN)
		continue;

		swap(set[index], set[maxInd]);

		maxInd = index;

		for (int j = 0; j < n; j++)
		{
			if (j != maxInd && (set[j] & (1 << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}

		index++; 
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}

int main()
{
	int N, M;
	cin >> N >> M;

	make_set(N+5);

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		union_set(u, v);
	}

	set <int> size;
	for (int i = 1; i <= N; i++)
	{
		size.insert(children[find_set(i)] + 1);
	}

	vector <int> arr;
	for (auto it : size)
		arr.pb(it);

	cout << maXOR(arr) << "\n";

	return 0;
}