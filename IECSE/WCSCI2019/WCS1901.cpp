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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

const int K = 1e9+7;

int mod_ex(ll a, ll b, int m)
{
	if (b == 0)
		return 1;

	long long int res = mod_ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	int L;
	while (T--) {
		cin >> L;

		if (L < 3) cout << 0 << "\n";

		else cout << ((mod_ex(2, L-1, K) - 2 + K) % K) << "\n";
	}

	return 0;
}

/*
1 5 4 3 2
2 5 4 3 1
3 5 4 2 1
4 5 3 2 1

3 4 5 2 1
2 4 5 3 1
1 4 5 3 2
2 3 5 4 1
1 3 5 4 2
1 2 5 4 3

2 3 4 5 1
1 3 4 5 2
1 2 4 5 3
1 2 3 5 4
*/