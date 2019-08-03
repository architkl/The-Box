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

	int n, k;
	cin >> n >> k;

	string s, ans = "";
	cin >> s;

	ans += s[0];
	bool x = s[0]-48;
	for (int i = 1; i < min(n, k); i++)
	{
		ans += to_string(x ^ (s[i]-48));
		x ^= (ans.back()-48);
	}

	for (int i = k; i < n; i++)
	{
		x ^= (ans[i-k]-48);
		ans += to_string(x ^ (s[i]-48));
		x ^= (ans.back()-48);
	}

	cout << ans << "\n";

	return 0;
}