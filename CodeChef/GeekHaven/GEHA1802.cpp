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

		vector <int> freq(N+5);
		int t;
		for (int j = 0; j < M; j++)
		{
			cin >> t;
			freq[t]++;
		}

		
	}

	return 0;
}