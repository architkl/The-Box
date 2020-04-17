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

	int N, P;
	while (T--) {
		cin >> N >> P;

		vector <int> A(N);
		for (int i = 0; i < N; i++) cin >> A[i];

		int l = 0, r = 0, num = 0, ans = INT_MAX;
		ll sum = 0;
		while (1) {
			while (sum <= P && r < N) {
				num++;
				sum += A[r];
				r++;
			}

			if (sum <= P) break;

			ans = min(ans, num);

			while (sum > P && l < r) {
				l++;
				sum -= A[l];
				num--;
			}

			ans = min(ans, num+1);
		}

		cout << ans << "\n";
	}

	return 0;
}