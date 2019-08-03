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

	int t;
	cin >> t;

	ll n, k;
	while (t--)
	{
		cin >> n >> k;

		ll op = 0;
		while (n)
		{
			while (n % k == 0)
			{
				n /= k;
				op++;
			}

			op += n % k;
			n -= (n % k);
		}

		cout << op << "\n";
	}

	return 0;
}