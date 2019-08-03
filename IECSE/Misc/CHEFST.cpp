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

	int t;
	cin >> t;

	long long int n1, n2, m;
	while (t--)
	{
		cin >> n1 >> n2 >> m;

		long long int x = min(n1, n2), q = (m * (m+1)) / 2;

		if (x < m || x <= q)
			cout << max(n1-n2, n2-n1) << "\n";

		else
			cout << n1 + n2 - 2*q << "\n";
	}

	return 0;
}