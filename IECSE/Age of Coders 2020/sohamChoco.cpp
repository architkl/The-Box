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

//	SIEVE
const int sieve_max = 1e7;

vector <bool> prime(sieve_max, 1);

void sieve()
{
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i*i < sieve_max; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j < sieve_max; j+=i)
			prime[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve();

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		if (prime[n]) cout << 1 << "\n";
		else if (n % 2 == 0 || prime[n-2]) cout << 2 << "\n";
		else cout << 3 << "\n";
	}

	return 0;
}