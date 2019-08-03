/*
Author: architkl
Language: C++ 14
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

	int N, K;
	string num;

	while (T--)
	{
		cin >> N >> K;

		cin >> num;

		int prod = 1, max_p;
		for (int i = 0; i < K; i++)
			prod *= (num[i] - 48);

		max_p = prod;

		int i = 1, j = K;
		while (j < N)
		{
			if (num[i-1] == '0')
			{
				prod = 1;
				for (int k = i; k <= j; k++)
					prod *= (num[k] - 48);
			}

			else
			{
				prod /= (num[i-1] - 48);
				prod *= (num[j] - 48);
			}

			if (prod > max_p)
				max_p = prod;

			i++;
			j++;
		}

		cout << max_p << "\n";
	}

	return 0;
}