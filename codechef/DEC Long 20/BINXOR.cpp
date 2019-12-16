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
const int N_MAX = 2e5+5;

vector <ll> fac(N_MAX);

void pre() {
	fac[0] = 1;
	for (int i = 1; i < N_MAX; i++) fac[i] = (i * fac[i-1]) % K;
}

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

int nCr(int n, int r) {
	return ((((fac[n] * mod_ex(fac[n-r], K-2, K)) % K) * mod_ex(fac[r], K-2, K)) % K);
}

int main() {
	pre();

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		string A, B;
		cin >> A >> B;

		int cnt_a[2] = {}, cnt_b[2] = {};
		for (int i = 0; i < N; i++) cnt_a[A[i]-48]++;
		for (int i = 0; i < N; i++) cnt_b[B[i]-48]++;

		ll res = 0, val = abs(cnt_a[1] - cnt_b[1]);
		for (int i = 0; i <= min(cnt_a[0], cnt_b[0]); i++) {
			if (val > N || val > (cnt_a[1] + cnt_b[1])) break;

			res += nCr(N, val);
			res %= K;
			val += 2;
		}

		cout << res << "\n";
	}

	return 0;
}