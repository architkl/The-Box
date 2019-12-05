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
	while (T--)
	{
		cin >> N >> M;

		vector <int> A, B;
		int sum_A = 0, sum_B = 0, t;

		for (int i = 0; i < N; i++)
		{
			cin >> t;

			if (t == 0)
				continue;

			A.pb(t);
			sum_A += t;
		}

		for (int i = 0; i < M; i++)
		{
			cin >> t;

			if (t == 0)
				continue;

			B.pb(t);
			sum_B += t;
		}

		if (sum_A + sum_B == 0)
		{
			cout << "Bob\n";
			continue;
		}

		if (A.size() == B.size())
		{
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());

			int flag = 0;
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i] != B[i])
				{
					flag = 1;
					break;
				}
			}

			flag ? cout << "Alice\n" : cout << "Bob\n";
		}

		else
			cout << "Alice\n";
	}

	return 0;
}