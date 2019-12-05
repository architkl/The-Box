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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, M;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		vector <int> H(N), C(N);
		for (int j = 0; j < N; j++)
			cin >> H[j];

		for (int j = 0; j < N; j++)
			cin >> C[j];

		int g_mx = 0;
		for (int j = 0; j < N; j++)
			if (H[j] > H[g_mx])
				g_mx = j;
		
		unordered_map <int, int> mymap;
		mymap[C[g_mx]] = 1;
		int t_mx = g_mx + 1;
		for (int j = g_mx+1; j < N; j++)
		{
			if (H[j])
		}
	}

	return 0;
}