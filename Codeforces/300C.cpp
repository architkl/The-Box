/*
Author: architkl
Language: C++ 11
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

const int k = 1e9 + 7;
const int N_MAX = 1e6 +  5;

int fact[N_MAX];

void pre()
{
	fact[0] = 1;
	for (int i = 1; i < N_MAX; i++)
		fact[i] = ((long long)fact[i-1] * i) % k;
}

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

bool check(int x, int a, int b)
{
	while (x != 0)
	{
		if ((x % 10) != a && (x % 10) != b)
			return 0;
		
		x /= 10;
	}

	return 1;
}

int main()
{
	pre();

	int a, b, n;
	cin >> a >> b >> n;

	int cnt = 0, i = 0;
	vector <int> d_i;
	while (i != n+1)
	{
		if (check(i*a + (n-i)*b, a, b))
		{
			d_i.pb(i);
			cnt++;
		}

		i++;
	}

	long long int sum = 0;

	if (cnt != 0)
	{
		for (auto j : d_i)
		{
			// cout << j << " ";
			sum += ((long long)(((long long)fact[n] * mod_ex(fact[j], k-2, k)) % k) * mod_ex(fact[n-j], k-2, k)) % k;
			sum %= k;
		}
	}

	cout << sum << "\n";

	return 0;
}