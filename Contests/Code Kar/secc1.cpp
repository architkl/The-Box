/*
Author: architkl
Language: C++ 14
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

bool check(string str)
{
	for (int i = 0; i < str.length() / 2; i++)
		if (str[i] != str[str.length()-i-1])
			return false;

	return true;
}

int solve(string str, int del)
{
	if (str.length() == 0)
		return INT_MAX;

	// cout << str << "\n";

	if (check(str))
		return del;

	// cout << false << "\n";

	int n = str.length(), mn = INT_MAX, temp = INT_MAX;

	for (int i = 0; i < n/2; i++)
	{
		if (str[i] != str[n-i-1])
			temp = min(solve(str.erase(i, 1), del+1), solve(str.erase(n-i-1, 1), del+1));
		
		mn = min(mn, temp);
	}

	return mn;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	string str;
	cin >> str;

	cout << solve(str, 0) * 2 << "\n";

	return 0;
}