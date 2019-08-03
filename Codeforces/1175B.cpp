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

const ll cap = pow(2, 32) - 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
	cin >> l;

	string s;
	ll temp, cnt = 0;
	bool f = 0;
	int n;
	stack <ll> for_n, count;
	while (l--)
	{
		cin >> s;

		if (s[0] == 'f')
		{
			count.push(cnt);

			cin >> n;
			cnt = 0;
			for_n.push(n);
		}

		else if (s[0] == 'a')
			cnt++;

		else
		{
			temp = count.top() + for_n.top() * cnt;
			count.pop();
			count.push(temp);
			for_n.pop();
			cnt = count.top();
			count.pop();

			if (temp > cap)
				f = 1;
		}
	}

	if (f || cnt > cap)
		cout << "OVERFLOW!!!\n";

	else
		cout << cnt << "\n";

	return 0;
}