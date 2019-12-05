/*
Author: architkl
Language: C++ 11
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
#include <iomanip>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

double b_search(int d)
{
	double low = 0, high = d, mid, a, b;

	while (low < high)
	{
		mid = (low + high) / 2;

		a = mid;
		b = d-mid;

		if (a*b == d)
			return a;

		if (mid == low || mid == high)
			return -1;

		else if (a*b > d)
			high = mid;

		else
			low = mid;
	}

	if (2*high == high*high)
		return high;

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int d;
	while (t--)
	{
		cin >> d;

		double ans = b_search(d);

		if (ans == -1)
			cout << "N\n";

		else
			cout << setprecision(9) << fixed << "Y " << ans << " " << d - ans << "\n";
	}

	return 0;
}