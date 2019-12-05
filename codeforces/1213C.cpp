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
	vector <pii> seq(10);
	int tmp, sum, cnt;
	for (int i = 0; i < 10; i++) {
		tmp = i;
		sum = 0;
		cnt = 0;

		while (tmp != 0) {
			cnt++;
			sum += tmp;
			tmp += i;
			tmp %= 10;
		}

		seq[i] = mp(cnt+1, sum);
	}

	int q;
	cin >> q;

	ll n, m, res, rem;
	while (q--) {
		cin >> n >> m;

		res = (n / m) / seq[m%10].first * seq[m%10].second;
		rem = (n / m) % seq[m%10].first;

		for (int i = 1; i <= rem; i++)
			res += ((m%10) * i) % 10;

		cout << res << "\n";
	}

	return 0;
}