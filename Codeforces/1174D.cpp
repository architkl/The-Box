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

	int n, x;
	cin >> n >> x;

	bool vis[(1 << 18)] = {};
	int cap = pow(2, n);

	vector <int> pre;
	vis[x] = 1;
	for (int i = 1; i < cap; i++)
	{
		if (vis[i])
			continue;

		pre.pb(i);
		vis[i] = vis[i^x] = 1;
		// cout << i << " " << (i^x) << "\n";
	}

	vector <int> a;
	if (pre.size() > 0)
		a.pb(pre[0]);
	
	for (int i = 1; i < pre.size(); i++)
		a.pb(pre[i]^pre[i-1]);

	cout << a.size() << "\n";
	for (auto i : a)
		cout << i << " ";
	cout << "\n";

	return 0;
}