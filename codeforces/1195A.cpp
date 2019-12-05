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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;

	unordered_map <int, int> freq;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		freq[t]++;
	}

	int stock = ceil(n/2.0), ans = 0;

	for (auto i : freq)
	{
		if (i.second % 2 == 0)
		{
			stock -= i.second/2;
			ans += i.second;
		}
	}
	
	for (auto i : freq)
	{
		if (stock == 0)
			break;

		if (i.second % 2)
		{
			stock -= i.second/2;
			ans += i.second-1;
		}
	}

	cout << ans+stock << "\n";

	return 0;
}