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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int N, t;
	cin >> N >> t;

	for (int i = 2; i <= N/2; i++)
	{
		if (N % i == 0 && prime[i])
		{
			int c = 0, t = N;
			while (t % i == 0)
			{
				t /= i;
				c++;
			}

			cout << i << " " << c << "\n";
		}
	}

	return 0;
}