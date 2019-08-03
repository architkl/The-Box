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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int T;
	cin >> T;

	string a, b;
	while (T--)
	{
		cin >> a >> b;

		if (a.length() != b.length())
		{
			cout << "-1\n";
			continue;
		}

		for (int i = 0; i < a.length(); i++)
		{
			a[i] = toupper(a[i]);
			b[i] = toupper(b[i]);
		}

		// cout << a << " " << b << "\n"; 

		int d = a[0] - b[0], f = 1;

		for (int i = 1; i < a.length(); i++)
		{
			if (a[i] - b[i] != d && a[i] -26 - b[i] != d && a[i] + 26 - b[i] != d)
			{
				f = 0;
				break;
			}
		}

		if (f)
			cout << abs(d) << "\n";

		else
			cout << -1 << "\n";
	}

	return 0;
}