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

const int N_MAX = 2e5+5;
const int K = 998244353;

vector <ll> fac(N_MAX);

void pre() {
	fac[0] = 1;
	for (int i = 1; i < N_MAX; i++) {
		fac[i] = fac[i-1] * i;
		fac[i] %= K;
	}
}

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
	pre();

	int n, m;
	cin >> n >> m;

	cout << (((((fac[m] * mod_ex(fac[n-1], K-2, K)) % K) * mod_ex(fac[m-n+1], K-2, K)) % K * (n-2)) % K * mod_ex(2, n-3, K)) % K << "\n";

	return 0;
}