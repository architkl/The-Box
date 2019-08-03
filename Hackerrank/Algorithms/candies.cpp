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

	int n;
	cin >> n;
	// n = 100000;

	vector <int> arr(n);
	for (int i = 0; i < n; i++)
		// arr[i] = i+1;
		cin >> arr[i];

	int cand[n+5] = {};
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i-1])
		{
			int d = 0, j = i;
			while (j < n && arr[j] < arr[j-1])
			{
				d++;
				j++;
			}

			cand[i-1] = d+1;
			for (int k = i; k <= j; k++)
				cand[k] = d--;
			
			i = j;
		}
	}

	// for (auto i : cand)
	// 	cout << i << " ";
	// cout << "\n";

	if (cand[0] == 0)
		cand[0] = 1;

	for (int i = 1; i < n; i++)
	{
		if (cand[i] != 0)
		{
			if (arr[i] > arr[i-1])
				cand[i] = max(cand[i], cand[i-1] + 1);
			
			continue;
		}

		if (arr[i] > arr[i-1])
			cand[i] = cand[i-1] + 1;

		else
			cand[i] = 1;
	}

	long long int sum = 0;
	for (auto i : cand)
	{
		// cout << i << " ";
		sum += i;
	}

	cout << sum << "\n";

	return 0;
}

/*
2  4  2  6  1  7  8  9  2  1
0  1 -1  1 -1  1  1  1 -1 -1
1  2  1  2  1  2  3  4  2  1

1 2 2
1 2 1
*/