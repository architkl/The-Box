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

bool legal(int nx, int no) {
	return (nx-no <= 1 && nx-no >= 0);
}

bool win(vector < vector <char> > grid, char c) {
	bool win;
	// row check
	for (int i = 0; i < 3; i++) {
		win = 1;
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] != c) {
				win = 0;
				break;
			}
		}

		if (win) return true;
	}

	// col check
	for (int i = 0; i < 3; i++) {
		win = 1;
		for (int j = 0; j < 3; j++) {
			if (grid[j][i] != c) {
				win = 0;
				break;
			}
		}

		if (win) return true;
	}

	// diagonal check
	win = 1;
	for (int i = 0; i < 3; i++) {
		if (grid[i][i] != c) {
			win = 0;
			break;
		}
	}

	if (win) return true;

	win = 1;
	for (int i = 0; i < 3; i++) {
		if (grid[i][2-i] != c) {
			win = 0;
			break;
		}
	}

	return win;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector < vector <char> > grid(3, vector <char> (3));
	int nx = 0, no = 0, nd = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 'X') nx++;
			else if (grid[i][j] == '0') no++;
			else nd++;
		}
	}

	if (!legal(nx, no) || (win(grid, '0') && nx > no) || (win(grid, 'X') && nx == no)) cout << "illegal\n";

	else if (win(grid, 'X')) cout << "the first player won\n";

	else if (win(grid, '0')) cout << "the second player won\n";

	else if (nd == 0) cout << "draw\n";

	else if (nx > no) cout << "second\n";

	else cout << "first\n";


	return 0;
}