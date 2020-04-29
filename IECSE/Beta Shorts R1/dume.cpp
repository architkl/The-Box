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
typedef pair <ll, ll> pll;

const int K = 1e9+7;

//	Binary Exponentiation
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, P;
	cin >> N >> P;

	ll q = N / P, r = N % P;
	ll p1 = ((mod_ex(2, q, K)-1) + K) % K, p2 = mod_ex(2, q, K);
	
	p1 *= P;
	p1 %= K;

	p2 *= r;
	p2 %= K;

	ll ans = (p1+p2) % K;
	cout << ans << "\n";

	return 0;
}