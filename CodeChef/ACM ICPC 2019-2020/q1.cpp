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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		string s;
		bool val;

		unordered_map <string, int> freq, temp;
		for (int i = 0; i < N; i++) {
			cin >> s >> val;

			freq[s + to_string(val)]++;
			temp[s] = 1;
		}

		int ans = 0;
		for (auto itr : temp) {
			// cout << itr.first << "\n";
			ans += max(freq[itr.first + "0"], freq[itr.first + "1"]);
		}

		cout << ans << "\n";
	}

	return 0;
}