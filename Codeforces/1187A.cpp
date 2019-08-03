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
	int T;
	cin >> T;

	int n, s, t;
	while (T--)
	{
		cin >> n >> s >> t;

		int both = s+t-n;
		int ind = n - both;

		cout << min(max(s, t) - both + 1, ind+1) << "\n";
	}

	return 0;
}