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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> q(n+1);
		for (int i = 0; i <= n; i++) q[i] = i;

		vector <int> temp(1);
		while (q.size() > 2) {
			for (int i = 1; i <= q.size(); i++) {
				if (i % 2 == 0) {
					// cout << q[i] << " ";
					temp.pb(q[i]);
				}

				// cout << "\n";
			}

			q.clear();
			q = temp;
			temp.clear();
		}

		cout << q[1] << "\n";
	}

	return 0;
}