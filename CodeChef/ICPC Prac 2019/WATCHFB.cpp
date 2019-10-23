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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

/*
//	GRAPHS
const int N_MAX = 1e5+5;

vector <int> G[N_MAX];
vector <piii> G[N_MAX];
vector <bool> vis(N_MAX);

void init()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = 0;
}

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

	for (int i = 0; i < sieve_max; i++)
		if (prime[i])
			cout << i << " ";
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
*/

int main() {
	int T;
	cin >> T;

	int N, c, a, b, t1, t2;
	while (T--) {
		cin >> N;

		t1 = t2 = 0;

		while (N--) {
			cin >> c >> a >> b;

			// cout << "Team 1: " << t1 << " Team 2: " << t2 << "\n";

			if (c == 1) {
				t1 = a;
				t2 = b;

				cout << "YES\n";
			}

			else if (a == b) {
				cout << "YES\n";
				t1 = a;
				t2 = b;
			}

			else {
				if (a < t1 || b < t2 || a < t2 || b < t1) {
					cout << "YES\n";

					if (a < t1 || b < t2) {
						t2 = a;
						t1 = b;
					}

					else {
						t1 = a;
						t2 = b;
					}
				}

				else
					cout << "NO\n";
			}
		}
	}

	return 0;
}