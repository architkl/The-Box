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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> A(N), B(N);
		for (int j = 0; j < N; j++)
			cin >> A[j];

		for (int j = 0; j < N; j++)
			cin >> B[j];

		int d, f = 1;
		for (int j = 0; j < N-2; j++)
		{
			d = B[j] - A[j];
			if (d < 0)
			{
				f = 0;
				break;
			}

			if (d == 0)
				continue;

			//cout << j << " " << d << "\n";

			A[j] += d;
			A[j+1] += 2*d;
			A[j+2] += 3*d;

			//cout << A[j] << " " << A[j+1] << " " << A[j+2] << "\n";
		}

		//cout << A[N-2] << " " << B[N-2] << " " << A[N-1] << " " << B[N-1] << "\n";

		if (A[N-1] != B[N-1] || A[N-2] != B[N-2])
			f = 0;

		//cout << A[N-1] << " " << A[N-2] << "\n";

		f ? cout << "TAK\n" : cout << "NIE\n";
	}

	return 0;
}