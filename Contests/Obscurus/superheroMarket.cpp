/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int sieve_max = 1e7;

//vector <bool> prime(sieve_max, 1);

/*void sieve()
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
*/

int mod_ex(int a, int b, int m)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, d, m, s;
	cin >> p >> d >> m >> s;

	int count = 0;

	if (s > p)
		count++;
	s -= p;
	while (s > 0)
	{
		// cout << p << " ";
		p = max(p-d, m);
		s -= p;
		if (s < 0)
			break;
		count++;
	}

	cout << count << "\n";

	return 0;
}