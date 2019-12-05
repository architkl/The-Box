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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string t;
	cin >> t;

	int n = t.length();

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (t[i] == 'a')
			cnt++;

	int s_dash = (n - cnt) / 2;
	string s_ = t.substr(n-s_dash);

	int i = 0, j = 0;
	bool f = 1;
	for (; i < n-s_dash; i++)
	{
		if (t[i] == 'a')
			continue;

		if (t[i] != s_[j])
		{
			f = 0;
			break;
		}

		j++;
	}

	if (f)
	{
		j = 0;
		while (j < i)
		{
			cout << t[j];
			j++;
		}
	}

	else
		cout << ":(";

	cout << "\n";

	return 0;
}