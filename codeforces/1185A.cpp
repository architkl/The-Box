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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int l = min(a, min(b, c)), m, r = max(a, max(b, c));

	if (a != l && a != r)
		m = a;

	else if (b != l && b != r)
		m = b;

	else
		m = c;

	cout << max(0, d-(m-l)) + max(0, d-(r-m)) << "\n";

	return 0;
}