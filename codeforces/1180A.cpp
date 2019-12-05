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

	int n;
	cin >> n;
	n--;

	int inc = 4, ans = 1;
	while (n--)
	{
		ans += inc;
		inc += 4;
	}

	cout << ans << "\n";

	return 0;
}