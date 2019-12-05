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

int cost(string s)
{
	// cout << s << "\n";
	int c = 0;

	c += min(abs(s[0] - 'A'), min(abs('Z' - s[0]) + 'A' - 64, abs(s[0] - 'A') + 'Z' - 'A' + 1));

	// cout << c << "\n";

	c += min(abs(s[1] - 'C'), min(abs('Z' - s[1]) + 'C' - 64, abs(s[1] - 'A') + 'Z' - 'C' + 1));

	// cout << c << "\n";

	c += min(abs(s[2] - 'T'), min(abs('Z' - s[2]) + 'T' - 64, abs(s[2] - 'A') + 'Z' - 'T' + 1));

	// cout << c << "\n";

	c += min(abs(s[3] - 'G'), min(abs('Z' - s[3]) + 'G' - 64, abs(s[3] - 'A') + 'Z' - 'G' + 1));

	// cout << c << "\n";

	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int res = 99999999;

	for (int i = 0; i <= n-4; i++)
	{
		res = min(res, cost(s.substr(i, 4)));
	}

	cout << res << "\n";

	return 0;
}