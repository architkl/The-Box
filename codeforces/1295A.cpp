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
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		if (n % 2) {
			cout << 7;
			n -= 3;
			while (n >= 2) {
				n -= 2;
				cout << 1;
			}
		}

		else {
			while (n >= 2) {
				n -= 2;
				cout << 1;
			}
		}

		cout << "\n";
	}

	return 0;
}