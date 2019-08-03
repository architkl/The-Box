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

	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;

	bool f = 0;
	while (1)
	{
		if (a == b)
		{
			f = 1;
			break;
		}

		if (a == x || b == y)
			break;

		a %= n;
		a += 1;

		b -= 1;
		if (b <= 0)
			b += n;
	}

	if (f)
		cout << "YES\n";

	else
		cout << "NO\n";

	return 0;
}