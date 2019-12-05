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

	int a, m;
	cin >> a >> m;

	unordered_map <int, bool> vis;
	bool f = 1;
	while (a % m != 0)
	{
		if (vis[a%m])
		{
			f = 0;
			break;
		}

		vis[a%m] = 1;
		a += a%m;
	}

	if (f)
		cout << "Yes\n";

	else
		cout << "No\n";

	return 0;
}