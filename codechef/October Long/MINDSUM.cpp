/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
#define make_pair mp

typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int digitsum(ll x)
{
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int rec(ull start, int target, ull D, int op)
{
	if (start == target || op == 25)
		return op;

	if (start / 10 == 0)
		return (rec(start+D, target, D, op + 1));

	return min(rec(start+D, target, D, op + 1), 
		rec(digitsum(start), target, D, op + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	ull N = 123, D = 1;
	int mn, op;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> D;

		if (D % 9 == 0)
			N % 9 == 0 ? mn = 9 : mn = N % 9;

		else if (D % 3 == 0)
			N % 3 == 0 ? mn = 3 : mn = N % 3;

		else
			mn = 1;

		op = rec(N, mn, D, 0);

		cout << mn << " " << op << "\n";
	}

	return 0;
}