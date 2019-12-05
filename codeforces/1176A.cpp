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

	int q;
	cin >> q;

	ll n;

	while  (q--)
	{
		cin >> n;

		int cnt_2 = 0, cnt_3 = 0, cnt_5 = 0;
		ll temp = n;

		while (!(temp % 2))
		{
			cnt_2++;
			temp /= 2;
		}

		while (!(temp % 3))
		{
			cnt_3++;
			temp /= 3;
		}

		while (!(temp % 5))
		{
			cnt_5++;
			temp /= 5;
		}

		if (temp != 1)
			cout << -1 << "\n";

		else
			cout << cnt_2 + 2*cnt_3 + 3*cnt_5 << "\n";
	}

	return 0;
}