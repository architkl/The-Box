/*
Author: architkl
Language: C++ 14


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
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, K;
	while (T--)
	{
		cin >> N >> K;

		vector <int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];

		multiset <int> MS;
		multiset <int>::iterator it;

		unordered_map <int, int> freq;

		int count = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				MS.insert(A[j]);
				freq[A[j]]++;

				it = MS.begin();
				int p = (K / ceil((double)K / (j-i+1))) - 1;

				while (p--)
					it++;

				if (freq[freq[*it]] >= 1)
					count++;
			}

			freq.clear();
			MS.clear();
		}

		cout << count << "\n";
	}

	return 0;
}

/*