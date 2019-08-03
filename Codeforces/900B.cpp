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
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int pos = 1, q, rem = (a % b) * 10;
	while (pos <= b)
	{
		q = rem/b;
		if (q == c)
			break;

		rem %= b;
		rem *= 10;

		pos++;
	}

	if (pos > b)
		cout << -1 << "\n";

	else
		cout << pos << "\n";

	return 0;
}