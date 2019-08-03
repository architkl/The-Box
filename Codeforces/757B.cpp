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
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

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
	sieve();

	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	unordered_map <int, int> freq;
	for (int i = 0; i < n; i++)
	{
		int lim = sqrt(a[i]); // try with sieve
		for (int j = 2; j <= lim; j++)
		{
			if (a[i] % j == 0 && prime[j])
				freq[j]++;
		}
		
		if (a[i] != 1)
			freq[a[i]]++;
	}
	
	int ans = 1;
	for (auto i : freq)
		if (i.second > ans)
			ans = i.second;
	
	cout << ans << "\n";
	
	return 0;
}

/*
int main()
{
	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	unordered_map <int, int> freq;
	for (int i = 0; i < n; i++)
	{
		int lim = sqrt(a[i]); // try with sieve
		for (int j = 2; j <= lim; j++)
		{
			if (a[i] % j == 0)
			{
				freq[j]++;
				freq[a[i]/j]++;
			}
		}
		
		if (sqrt(a[i]) == lim)
			freq[lim]--;
		
		freq[a[i]]++;
	}
	
	int ans = 1;
	for (auto i : freq)
		if (i.second > ans)
			ans = i.second;
	
	cout << ans << "\n";
	
	return 0;
}
*/