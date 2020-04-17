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
	int T;
	cin >> T;

	int N;
	for (int x = 1; x <= T; x++) {
		cin >> N;
		vector < vector <int> > mat(N, vector <int> (N));
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> mat[i][j];

		int val = 0;
		for (int i = 1; i <= N; i++) val ^= i;

		int k = 0, r = 0, c = 0;
		for (int i = 0; i < N; i++) k += mat[i][i];

		for (int i = 0; i < N; i++) {
			vector <bool> mark(N+1);
			for (int j = 0; j < N; j++) {
				if (mark[mat[i][j]]) {
					r++;
					break;
				}

				mark[mat[i][j]] = true;
			}
		}

		for (int i = 0; i < N; i++) {
			vector <bool> mark(N+1);
			for (int j = 0; j < N; j++) {
				if (mark[mat[j][i]]) {
					// cout << mat[j][i] << " repeated\n";
					c++;
					break;
				}

				mark[mat[j][i]] = true;
			}

			// cout << i << "\n";
			// for (int j = 1; j <= N; j++) cout << j << " " << mark[j] << "\n";
		}

		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < N; j++) cout << mat[i][j] << " ";
		// 	cout << "\n";
		// }

		cout << "Case #" << x << ": " << k << " " << r << " " << c << "\n";
	}

	return 0;
}