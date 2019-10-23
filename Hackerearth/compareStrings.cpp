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
	
	int N, Q;
	cin >> N >> Q;

	string A, B;
	cin >> A >> B;

	unordered_set <int> mismatch;
	for (int i = 0; i < A.length(); i++) if (A[i] != B[i]) mismatch.insert(i);

	bool flag = 0;
	int idx;
	while (Q--) {
		cin >> idx;
		idx--;

		if (flag) cout << "YES\n";

		else if (mismatch.find(idx) == mismatch.end()) cout << "NO\n";

		else {
			mismatch.erase(idx);

			if (mismatch.empty()) {
				flag = 1;
				cout << "YES\n";
			}

			else cout << "NO\n";
		}
	}

	return 0;
}