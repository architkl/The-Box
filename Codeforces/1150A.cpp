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

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	int r_ = r;

	vector <int> s(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(s.begin(), s.end());
	sort(b.begin(), b.end(), comp);

	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] < r)
		{
			cnt += r/s[i];
			r %= s[i];
		}

		if (r == 0)
			break;
	}

	cout << max(r_, cnt*b[0] + r) << "\n";

	return 0;
}