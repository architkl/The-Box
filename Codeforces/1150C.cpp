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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int sieve_max = 3e5;

vector <bool> prime(sieve_max, 1);
vector <int> primes;

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
			primes.pb(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> tiles(n);
	int cnt_1 = 0, cnt_2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tiles[i];

		tiles[i] == 1 ? cnt_1++ : cnt_2++;
	}

	if (cnt_1 == 0 || cnt_2 == 0)
	{
		for (int i = 0; i < n; i++)
			cout << tiles[i] << " ";
		cout << "\n";
	}

	else
	{
		string ans = "";
		int sum = 0, jump;
		for (int i = 0; i < primes.size(); i++)
		{
			jump = (primes[i] - sum);

			if (jump/2 > cnt_2)
			{
				jump -= cnt_2 * 2;
				cnt_2 = 0;

				if (jump > cnt_1)
					break;
				
				cnt_1 -= jump;
			}

			else
			{
				cnt_2 -= jump/2;

				if (jump % 2)
			}
		}
	}

	return 0;
}