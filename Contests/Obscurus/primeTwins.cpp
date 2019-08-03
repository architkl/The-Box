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
#include <string.h>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

vector <int> prime;

void sieve(int limit)
{
	bool arr[limit];

	for (int i = 2; i < limit; i++)
		arr[i] = true;

	arr[0] = arr[1] = false;

	for (int i = 2; i*i < limit; i++)
	{
		if (!arr[i])
			continue;

		for (int j = i*i; j < limit; j+=i)
			arr[j] = false;
	}

	for (int i = 2; i < limit; i++)
	{
		if (arr[i])
		{
			prime.pb(i);
			// cout << i << "\n";
		}
	}
}

int segsieve(int low, int high)
{
	int limit = floor(sqrt(high)) + 1;

	sieve(limit);

	int n = high - low + 1;

	bool mark[n+1];
	memset(mark, true, sizeof(mark));

	for (int i = 0; i < prime.size(); i++)
	{
		int loLim = floor(low / prime[i]) * prime[i];

		// cout << prime[i] << "\n";

		if (loLim < low)
			loLim += prime[i];

		if (loLim == prime[i])
			loLim += prime[i];

		for (int j = loLim; j <= high; j += prime[i])
			mark[j-low] = false;
	}

	int count = 0;
	for (int i = low; i < high; i++)
	{
		if (mark[i-low] && mark[i-low+2])
			count++;
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, q;
	cin >> p >> q;

	cout << segsieve(p, q) << "\n";

	return 0;
}