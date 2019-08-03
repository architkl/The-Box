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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, M, K, L;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M >> K >> L;

		vector <int> A(N);
		for (int j = 0; j < N; j++)
			cin >> A[j];

		sort(A.begin(), A.end());

		int min = INT_MAX, temp;

		for (int j = 0; j < N; j++)
		{
			if (A[i] > K)
			{
				temp = M - (K / L) + j;
				temp = (L - (K % L)) + temp * L;

				if (temp < min)
					min = temp;

				break;
			}

			temp = M - (A[j] / L) + j;
			temp = (L - (A[j] % L)) + temp * L;
			
			if (temp < min)
				min = temp;
		}

		if (A[N-1] < K)
		{
			temp = (M - (K / L)) + N;
			temp = (L - (K % L)) + temp * L;
			
			if (temp < min)
				min = temp;
		}
		
		cout << min << "\n";
	}

	return 0;
}