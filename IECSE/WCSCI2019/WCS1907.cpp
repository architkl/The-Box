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
typedef long long ll;

ll count_occ(ll n, int x) {
	if (n == 0 && x == 0) return 1;
	
	ll occ = 0;
	while (n > 0) {
		if (n % 10 == x) occ++;
		n = n / 10;
	}

	return occ;
}

int main()
{
	int N, Q, X;
	cin >> N >> Q >> X;

	vector <ll> pre(N+1);
	ll t;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		pre[i] = pre[i-1] + count_occ(t, X);
	}

	int a, b;
	while (Q--)
	{
		cin >> a >> b;

		cout << pre[b] - pre[a-1] << "\n";
	}

	return 0;
}