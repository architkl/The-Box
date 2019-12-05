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
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	ll a, b, k;
	while (t--)
	{
		cin >> a >> b >> k;

		if (k % 2)
			cout << (a-b)*(k/2) + a << "\n";
		
		else
			cout << (a-b)*(k/2) << "\n";
	}

	return 0;
}