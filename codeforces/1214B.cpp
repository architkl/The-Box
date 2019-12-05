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
	int b, g, n;
	cin >> b >> g >> n;

	int ans = 0, temp = min(g, n);
	while (temp >= 0 && n - temp <= b)
	{
		temp--;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}