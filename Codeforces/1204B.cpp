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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	ll mn = 0, mx = 0, num = 1;
	for (int i = 0; i < l; i++)
	{
		mn += num;
		mx += num;
		num <<= 1;
	}

	for (int i = l; i < r; i++)
	{
		mx += num;
		num <<= 1;
	}

	num >>= 1;

	mn += (n-l);
	mx += (n-r) * num;

	cout << mn << " " << mx << "\n";

	return 0;
}