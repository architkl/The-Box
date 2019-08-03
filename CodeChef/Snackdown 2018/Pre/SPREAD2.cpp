/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
#define make_pair mp

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 1e5+5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, t, left, days;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> presum(N_MAX);
		left = N-1;

		for (int j = 1; j <= N; j++)
		{
			cin >> t;
			presum[j] = presum[j-1] + t;
		}

		int j = 1, sum = 1;
		for (int k = 1; k <= N; k++)
		{
			sum += presum[j];
			j += presum[j];

			if (sum >= N)
			{
				cout << k << "\n";
				break;
			}
		}
	}

	return 0;
}