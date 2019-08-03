/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
#define make_pair mp

typedef pair <int, int> pii;

int main()
{
	int n, h;
	cin >> n >> h;

	vector <int> reward(n+1), pen(n+1);
	reward[0] = 0;
	pen[0] = 0;

	int x1, x2, prev = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> x2;

		reward[i+1] += reward[i] + x2 - x1;

		if (i == 0)
			prev = x1 - 1;

		pen[i+1] = pen[i] + x1 - prev;

		prev = x2;
	}

	vector <int>::iterator it_r, it_p;
	int ans = 0, cur_h;
	for (int i = 1; i <= n; i++)
	{
		it_p = upper_bound(pen.begin()+i, pen.end(), h + pen[i]-1);

		it_p--;

		it_r = reward.begin() + (it_p - pen.begin());

		ans = max(ans, *it_r - reward[i-1] + h);

		if (it_p + 1 == pen.end())
			break;
	}

	cout << ans << "\n";

	return 0;
}