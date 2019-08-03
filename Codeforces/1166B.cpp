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

	int k;
	cin >> k;

	if (k < 5)
		cout << -1 << "\n";

	else
	{
		int n, m = 5;
		while (1)
		{
			if (k % m == 0)
				break;
			m++;
		}

		n = k / m;

		if (n < 5)
			cout << -1 << "\n";

		else
		{
			string a = "aeiou";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					cout << a[(j+i) % 5];
			}

			cout << "\n";
		}
	}

	return 0;
}