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

//	SIEVE
const int sieve_max = 1e6+5;

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

int main()
{
	sieve();

	int n;
	cin >> n;

	vector <ll> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	ll temp;
	for (int i = 0; i < n; i++)
	{
		temp = (int)sqrt(x[i]);

		if (temp * temp == x[i] && prime[temp])
			cout << "YES\n";

		else
			cout << "NO\n";
	}

	return 0;
}