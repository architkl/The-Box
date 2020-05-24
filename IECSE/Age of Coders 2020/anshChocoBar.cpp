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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector < vector <int> > bar(m, vector <int> (n));
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> bar[i][j];

	int a, b;
	cin >> a >> b;

	int num = INT_MAX, temp;
	for (int i = 0; i < m; i++) {
		if (i+a-1 < m) {
			for (int j = 0; j < n; j++) {
				if (j+b-1 < n) {
					temp = 0;
					for (int k = 0; k < a; k++) {
						for (int l = 0; l < b; l++) {
							if (bar[i+k][j+l] == 1) temp++;
						}
					}

					num = min(num, temp);
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (i+b-1 < m) {
			for (int j = 0; j < n; j++) {
				if (j+a-1 < n) {
					temp = 0;
					for (int k = 0; k < b; k++) {
						for (int l = 0; l < a; l++) {
							if (bar[i+k][j+l] == 1) temp++;
						}
					}

					num = min(num, temp);
				}
			}
		}
	}

	cout << num << "\n";

	return 0;
}