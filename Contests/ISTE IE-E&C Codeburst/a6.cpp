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

bool solve(int x, int n) {
	string s1 = "";
	while (x) {
		s1 += (x%10)+48;
		x /= 10;
	}

	string s2 = s1;
	reverse(s2.begin(), s2.end());

	string s3 = "";
	int temp = n;
	while (n) {
		s3 += (n%10)+48;
		n /= 10;
	}

	int num = 0;
	for (auto i : s1) {
		num *= 10;
		num += (i-48);
	}

	// cout << s1 << " " << s2 << " " << num << " " << temp << "\n";

	return ((s1 != s2) && num <= temp && prime[num]);
}

int main() {
	sieve();

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (prime[i] && solve(i, n)) cout << i << " ";
	}

	cout << "\n";

	return 0;
}