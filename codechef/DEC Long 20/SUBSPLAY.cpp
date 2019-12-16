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

	int N;
	while (T--) {
		cin.ignore();
		cin >> N;

		string s;
		cin.ignore();
		cin >> s;

		vector <int> prev(26, INT_MIN);
		int res = INT_MIN;
		for (int i = 0; i < N; i++) {
			if (prev[s[i]-97] != INT_MIN) res = max(res, prev[s[i]-97]+N-i);

			prev[s[i]-97] = max(prev[s[i]-97], i);
		}
	
		if (res <= 0) cout << 0 << "\n";
		
		else cout << res << "\n";

		fflush(stdout);
	}

	return 0;
}