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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int R, C, K;
	while (T--)
	{
		cin >> R >> C >> K;

		vector < vector <int> > V(R, vector <int> (C));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> V[i][j];

		for (int i = 0; i < R; i++)
		{
			for (int l = 0; l < C; l++)
			{
				int r = l;
				while (V[r]-V[l] <= K)
					r++;
		}
	}

	return 0;
}