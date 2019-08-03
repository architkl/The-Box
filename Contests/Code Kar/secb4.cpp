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

int find(int x, int b)
{
	int n = 0;

	while (x % b == 0)
	{
		n++;
		x /= b;
	}

	return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int count2 = 0, count5 = 0;
	for (int i = 2; i <= n; i++)
	{
		count2 += find(i, 2) * i;
		count5 += find(i, 5) * i;
	}

	cout << min(count2, count5) << "\n";

	return 0;
}