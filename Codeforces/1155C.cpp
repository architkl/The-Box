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

	int n, m;
	cin >> n >> m;

	vector <long long int> x(n), p(m), temp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		temp[i] = x[i] - x[0];
	}

	for (int i = 0; i < m; i++)
		cin >> p[i];

	long long int mn;

	if (n == 2)
		mn = x[1] - x[0];

	else
		mn = __gcd(temp[1], temp[2]);

	for (int i = 3; i < n; i++)
		mn = __gcd(mn, temp[i]);

	bool f = 0;
	for (int i = 0; i < m; i++)
	{
		if (mn % p[i] == 0)
		{
			cout << "YES\n" << x[0] << " " << i+1 << "\n";
			f = 1;
			break;
		}
	}

	if (!f)
		cout << "NO\n";

	return 0;
}