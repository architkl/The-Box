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

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

map <int, char> hand
{
	{'d', 'l'},
	{'f', 'l'},
	{'j', 'r'},
	{'k', 'r'}
};

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

		string str[N];
		for (int j = 0; j < N; j++)
			cin >> str[j];

		map <string, int> time;
		int t, total = 0;
		char cur;
		for (int j = 0; j < N; j++)
		{
			t = 0;
			cur = 'n';

			if (time[str[j]])
			{
				total += time[str[j]] / 2;
				continue;
			}

			for (auto k : str[j])
			{
				hand[k] != cur ? t += 2 : t += 4;

				cur = hand[k];
			}

			time[str[j]] = t;
			total += t;
		}

		cout << total << "\n";
	}

	return 0;
}

/*
0.2 + 0.4 + 0.2 + 0.4 + 0.2 = 1.4
0.2 + 0.4 + 0.2 + 0.2 + 0.2 = 1.2
0.2 + 0.4 + 0.4 = 1
(0.2 + 0.4 + 0.2 + 0.4 + 0.2) / 2 = 0.7
0.2 + 0.4 + 0.4 + 0.4 + 0.4 = 1.8
*/