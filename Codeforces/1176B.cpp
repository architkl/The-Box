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

	int n;

	while (t--)
	{
		cin >> n;

		vector <int> a(n);
		int ans = 0, mod_1 = 0, mod_2 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];

			if (!(a[i] % 3))
				ans++;

			else if (a[i] % 3 == 1)
				mod_1++;

			else
				mod_2++;
		}

		if (mod_1 < mod_2)
		{
			ans += mod_1;
			mod_2 -= mod_1;

			ans += mod_2 / 3;
		}

		else
		{
			ans += mod_2;
			mod_1 -= mod_2;

			ans += mod_1 / 3;
		}

		cout << ans << "\n";
	}

	return 0;
}