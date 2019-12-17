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

const int sieve_max = 1e7;

vector <bool> prime(sieve_max, 1);

void sieve()
{
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i*i < sieve_max; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j < sieve_max; j+=i)
			prime[j] = false;
	}
}

int main() {
	// sieve();

	int r, c;
	cin >> r >> c;

	vector < vector <int> > mat(r, vector <int> (c));

	if (r == 1 && c == 1) cout << 0 << "\n";

	else if (r == 1 || c == 1) {
		if (r == 1) for (int i = 0; i < c; i++) mat[0][i] = i+2;

		else for (int i = 0; i < r; i++) mat[i][0] = i+2;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) cout << mat[i][j] << " ";
			cout << "\n";
		}
	}

	else {
		int p_idx = 2, c_idx = 4, xplier = 4;
		for (int i = 0; i < c; i++) {
			mat[0][i] = i+2;
		}

		for (int i = 1; i < r; i++) {
			for (int j = 0; j < c; j++) {
				mat[i][j] = mat[0][j] * (c+1+i);
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) cout << mat[i][j] << " ";
			cout << "\n";
		}
	}

	return 0;
}