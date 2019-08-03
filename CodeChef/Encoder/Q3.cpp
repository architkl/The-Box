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

	int N, K;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		unordered_map <int, int> hash;

		vector <int> A(N);
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];
			A[j] -= K;

			if (A[j] < 0)
				A[j] = 0;
		}

		int distinct = 0, len = 0, start = 0;
		for (int p = 0; p < N; p++)
		{
			hash[A[p]]++;

			if (hash[A[p]] == 1)
				if (A[p] != 0)
					distinct += 2;

			while (distinct > 2)
			{
				hash[A[start]]--;

				if (hash[A[start]] == 0 && A[start] != 0)
					distinct -= 2;

				start++;
			}

			if (p - start > len)
				len = p - start;
		}

		cout << len+1 << "\n";
	}

	return 0;
}