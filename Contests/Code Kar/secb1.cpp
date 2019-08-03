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

	int n;
	cin >> n;

	int a = 2, res = 3 * (n / 2) + (n % 2);

	cout << res << "\n";

	while (a <= n)
	{
		cout << a << " ";
		a += 2;
	}

	a = 1;
	while (a <= n)
	{
		cout << a << " ";
		a += 2;
	}

	a = 2;
	while (a <= n)
	{
		cout << a << " ";
		a += 2;
	}

	cout << "\n";

	return 0;
}