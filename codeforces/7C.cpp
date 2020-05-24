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
typedef pair <ll, ll> pll;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = extended_gcd(b, a%b, x1, y1);	
	x = y1;
	y = x1 - (a/b) * y1;

	return g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll A, B, C;
	cin >> A >> B >> C;

	ll x, y, g;
	g = extended_gcd(abs(A), abs(B), x, y);

	if (abs(C) % g != 0) cout << -1 << "\n";

	else {
		if (A < 0) x = -x;
		if (B < 0) y = -y;

		x *= -(C / g);
		y *= -(C / g);

		cout << x << " " << y << "\n";
	}

	return 0;
}