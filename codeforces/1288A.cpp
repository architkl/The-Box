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

int main() {
	int T;
	cin >> T;

	int n, d;
	while (T--) {
		cin >> n >> d;

		int temp = sqrt(d)-1;
		bool f = false;

		for (int i = -1; i <= 1; i++) {
			if ((temp+i) + ceil(double(d) / (temp+i+1)) <= n) {
				f = 1;
				break;
			}
		}

		if (f) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}