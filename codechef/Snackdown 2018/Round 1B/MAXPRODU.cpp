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

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, K;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		if (K > N)
		{
			cout << -1 << "\n";
			continue;
		}

		if (((K+1)*(K+2))/2 - 1 <= N)
		{
			vector <int> P(K);
			for (int j = 0; j < K; j++)
				P[j] = j+2;

			int leftover = N - ((K+1) * (K+2)) / 2 + 1;

			for (int j = 0; j < K; j++)
				P[j] += leftover / K;

			leftover %= K;

			for (int j = K-1; j >= 0; j--)
			{
				if (leftover == 0)
					break;

				P[j] += 1;
				leftover--;
			}

			ull prod = 1;
			for (int j = 0; j < K; j++)
			{
				prod *= P[j];
				prod %= MOD;
				prod *= P[j]-1;
				prod %= MOD;
			}

			cout << prod << "\n";
		}

		else
		{
			if ((K*(K+1))/2 <= N)
				cout << 0 << "\n";

			else
				cout << -1 << "\n";
		}
	}

	return 0;
}