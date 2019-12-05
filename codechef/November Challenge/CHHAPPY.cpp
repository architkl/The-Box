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

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> A(N+1);
		set <int> S;
		for (int j = 1; j <= N; j++)
		{
			cin >> A[j];
			S.insert(A[j]);
		}

		bool flag = 0;
		unordered_map <int, int> freq;
		for (auto j : S)
		{
			freq[A[j]]++;

			if (freq[A[j]] == 2)
			{
				flag = 1;
				break;
			}
		}

		flag ? cout << "Truly Happy\n" : cout << "Poor Chef\n";
	}

	return 0;
}