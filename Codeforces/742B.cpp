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

	vector <int> a(n);
	map <int, int> freq;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}

	ll res = 0;
	for (auto i : freq)
		x == 0 ? res += (ll)i.second * (i.second-1) : res += (ll)i.second * (freq[i.first ^ x]);

	/*for (int i = 0; i < n; i++)
		(x == 0) ? res += freq[a[i]]-1 : res += freq[a[i]^x];*/
	
	cout << res/2 << "\n";

	return 0;
}