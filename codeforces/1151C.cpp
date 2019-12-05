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

const int K = 1e9 + 7;

int fun(long long int l)
{
	if (l == 0)
		return 0;

	// long long int n1 = floor(log2(l));
	// if (pow(2, n1+1) <= l)
	// 	n1++;

	// n1++;

	long long int no_e = 0, no_o = 0, k = 1;
	int i = 0;

	while (l > 0)
	{
		if (i % 2)
		{
			no_e += min(l, k);
			no_e %= K;
		}

		else
		{
			no_o += min(l, k);
			no_o %= K;
		}

		// cout << "Odd: " << no_o << "\nEven: " << no_e << "\n\n";

		l -= k;
		k *= 2;
		i++;
	}
	
	/*if (n1 % 2)
	{
		no_e = 2 * (pow(4, n1/2) - 1) / 3;
		no_o = l - no_e;
	}

	else
	{
		no_o = (pow(4, n1 - n1/2) - 1) / 3;
		no_e = l - no_o;
	}*/

	// l %= K;

	long long int pre;
	// if (no_o > no_e)
	// {
	// 	pre = (l*(l+1)) / 2 + ((no_o-no_e - 1) * (no_o-no_e)) / 2;
	// }

	// else
	// 	pre = (l*(l+1)) / 2 + ((no_e-no_o) * (no_e-no_o + 1)) / 2;

	pre = (no_o*no_o) + (no_e * (no_e + 1));
	pre %= K;

	return pre;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int l, r;
	cin >> l >> r;

	int pre_l = fun(l-1);
	int pre_r = fun(r);

	// cout << pre_l << " " << pre_r << "\n";

	if (pre_l > pre_r)
		pre_r += K;

	cout << (pre_r - pre_l) % K << "\n";

	return 0;
}