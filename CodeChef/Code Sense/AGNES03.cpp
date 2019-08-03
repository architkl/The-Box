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

	double a1, a2, a3, b1, b2, b3;
	while (T--)
	{
		cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

		if (a2 == 0 && b2 == 0)
		{
			if (a3 == b3)
				cout << -1 << "\n";

			else
				cout << 0 << "\n";
		}

		else if (a2 == 0 || b2 == 0)
			cout << 1 << "\n";

		else if (a1 / a2 == b1 / b2)
		{
			if (a3 / a2 == b3/ b2)
				cout << -1 << "\n";

			else
				cout << 0 << "\n";
		}

		else
			cout << 1 << "\n";
	}

	return 0;
}