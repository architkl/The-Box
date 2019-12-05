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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	bool f = 0;
	int x = 1, y = 0;
	while (1)
	{
		while (7*x + 4*y < n)
			x++;

		if (7*x + 4*y == n)
		{
			f = 1;
			break;
		}

		x = 0;
		y++;

		if (7*x + 4*y > n)
			break;
	}

	if (f)
	{
		for (int i = 0; i < y; i++)
			cout << 4;

		for (int i = 0; i < x; i++)
			cout << 7;

		cout << "\n";
	}

	else
		cout << "-1\n";

	return 0;
}