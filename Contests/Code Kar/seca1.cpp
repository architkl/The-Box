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

const int sieve_max = 1e7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[m][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int count = 0;
	bool f;
	for (int i = 0; i < n; i++)
	{
		// if (i-1 < 0 || i+1 >= n)
		// 	continue;

		for (int j = 0; j < m; j++)
		{
			// if (j-1 < 0 || j + 1 >= n)
			// 	continue;

			f = 1;

			for (int k = -1; k < 2; k++)
			{
				for (int l = -1; l < 2; l++)
				{
					if (i+k < 0 || i+k >= n || j+l < 0 || j+l >= m)
						continue;

					if (k == 0 && l == 0)
						continue;

					if (arr[i+k][j+l] <= arr[i][j])
					{
						f = 0;
						break;
					}
				}

				if (!f)
				{
					// cout << arr[i][j] << "\n";
					break;
				}
			}

			if (f)
			{
				// cout << arr[i][j] << "\n";
				count++;
			}
		}
	}

	cout << count << "\n";

	return 0;
}