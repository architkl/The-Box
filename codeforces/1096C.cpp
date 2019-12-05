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

	double ang, n, k;
	while (T--)
	{
		cin >> ang;

		n = 3;
		k = 1;
		
		while (1)
		{
			if ((180 * k / n > ang) || (k > n - 2))
			{
				k = 1;
				n++;
				continue;
			}

			if (180 * k / n == ang)
				break;

			k++;
		}

		cout << n << "\n";
	}

	return 0;
}