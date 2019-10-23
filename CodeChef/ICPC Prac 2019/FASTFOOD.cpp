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
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> A(n), B(n), pre(n), suff(n);

		cin >> A[0];
		pre[0] = A[0];
		for (int i = 1; i < n; i++) {
			cin >> A[i];
			pre[i] = pre[i-1] + A[i];
		}

		for (int i = 0; i < n; i++) cin >> B[i];

		suff[n-1] = B[n-1];
		for (int i = n-2; i >= 0; i--) suff[i] = B[i] + suff[i+1];

		int mx = max(pre[n-1], suff[0]);
		for (int i = 0; i < n-1; i++) mx = max(mx, pre[i] + suff[i+1]);

		cout << mx << "\n";
	}

	return 0;
}