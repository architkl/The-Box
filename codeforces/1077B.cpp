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

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 1; i < n-1; i++)
	{
		if (a[i] == 0 && a[i-1] && a[i+1])
		{
			int sgn = 1, j = i+1, seg = 2;
			while (j < n && a[j] == sgn)
			{
				seg++;
				j++;
				sgn = !sgn;
			}

			ans += (seg + seg % 2) / 4;
			i = j;
		}
	}

	cout << ans << "\n";

	return 0;
}