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

	vector < vector <char> > board(8, vector <char> (8));
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> board[i][j];

	int ans = 0;
	for (int i = 0; i < 8; i++) {
		if (board[0][i] == 'B') {
			int j = 0;
			while (j < 8 && board[j][i] == 'B') j++;

			if (j == 8) ans++;
		}

		if (board[i][0] == 'B') {
			int j = 0;
			while (j < 8 && board[i][j] == 'B') j++;

			if (j == 8) ans++;
		}
	}

	if (ans == 16) ans = 8;

	cout << ans << "\n";

	return 0;
}