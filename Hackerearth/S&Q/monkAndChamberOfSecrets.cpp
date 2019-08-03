/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	cin >> N >> X;

	queue <pii> A;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		A.push(mp(t, i+1));
	}

	pii temp;
	queue <pii> also_temp;
	for (int i = 0; i < X; i++)
	{
		temp = A.front();

		for (int j = 0; j < X; j++)
		{
			if (A.empty())
				break;

			also_temp.push(A.front());
			A.pop();

			if (temp.first < also_temp.back().first)
				temp = also_temp.back();
		}

		for (int j = 0; j < X; j++)
		{
			if (also_temp.empty())
				break;

			if (also_temp.front() == temp)
			{
				also_temp.pop();
				continue;
			}

			if (also_temp.front().first == 0)
				A.push(mp(0, also_temp.front().second));

			else
				A.push(mp(also_temp.front().first-1, also_temp.front().second));

			also_temp.pop();
		}

		cout << temp.second << " ";
	}

	cout << "\n";

	return 0;
}