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
#include <iomanip>
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

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> fwd(n), bwd(n);
	for (int i = 1; i < n; i++)
	{
		if (bwd[i-1] > bwd[])
	}

	int p = 0, q = n-1, cnt = 1, prev;
	string moves = "";
	if (a[p] < a[q])
	{
		moves += 'L';
		prev = a[p++];
	}

	else
	{
		moves += 'R';
		prev = a[q--];
	}

	while (p <= q)
	{
		if (a[p] < a[q])
		{
			if (a[p] < prev)
			{
				if (a[q] < prev)
					break;

				moves += 'R';
				prev = a[q--];
			}

			else
			{
				moves += 'L';
				prev = a[p++];
			}
		}

		else if (a[q] < a[p])
		{
			if (a[q] < prev)
			{
				if (a[p] < prev)
					break;

				moves += 'L';
				prev = a[p++];
			}

			else
			{
				moves += 'R';
				prev = a[q--];
			}
		}

		else
		{

		}

		cnt++;
	}

	cout << cnt << "\n" << moves << "\n";

	return 0;
}