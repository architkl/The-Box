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

long long int gcd(long long int a, long long int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	long long int N, t, x, y, z;
	long long int m, n, temp;
	while (T--)
	{
		cin >> N >> t >> x >> y >> z;

		n = 2*N + 1;

		if (z < x)
		{
			x += z;
			z = x - z;
			x -= z;
		}

		if (x == z)
		{
			if (t == 1)
				m = x;

			else if (t == 2 || t == 4)
				m = 0;

			else
				m = x;
		}

		else
		{
			if (t == 1)
				m = 2*N - y;

			else if (t == 2 || t == 4)
				m = 2*N + 1 - 2*y;

			else
				m = 2*N + 1 - x;
		}
		
		temp = __gcd(m, n);
		m /= temp;
		n /= temp;

		cout << m << " " << n << "\n";
	}

	return 0;
}