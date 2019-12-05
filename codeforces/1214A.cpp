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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	int n, d, e;
	cin >> n >> d >> e;

	int mn = INT_MAX;
	for (int i = 0; e*i <= n; i+=5)
		mn = min(mn, (n - e*i) % d);
	
	cout << mn << "\n";

	return 0;
}